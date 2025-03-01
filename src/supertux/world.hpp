//  SuperTux
//  Copyright (C) 2006 Matthias Braun <matze@braunis.de>
//
//  This program is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program.  If not, see <http://www.gnu.org/licenses/>.

#ifndef HEADER_SUPERTUX_SUPERTUX_WORLD_HPP
#define HEADER_SUPERTUX_SUPERTUX_WORLD_HPP

#include <memory>
#include <string>

class World final
{
public:
  /** Load a World
      @param directory  Directory containing the info file, e.g. "levels/world1" */
  static std::unique_ptr<World> from_directory(const std::string& directory);
  static std::unique_ptr<World> create(const std::string& title, const std::string& desc);

private:
  World(const std::string& directory);

public:
  std::string get_basedir() const { return m_basedir; }
  std::string get_title() const { return m_title; }
  std::string get_description() const { return m_description; }

  bool hide_from_contribs() const { return m_hide_from_contribs; }

  bool is_levelset() const { return m_is_levelset; }
  bool is_worldmap() const { return !m_is_levelset; }
  
  std::string get_contrib_type() const { return m_contrib_type; }

  std::string get_worldmap_filename() const;
  std::string get_savegame_filename() const;

  void save(bool retry = false);

public:
  std::string m_title;
  std::string m_description;
  bool m_is_levelset;

private:
  std::string m_basedir;
  bool m_hide_from_contribs;
  std::string m_contrib_type; // Type of world if it is contrib: official, community, user

private:
  World(const World&) = delete;
  World& operator=(const World&) = delete;
};

#endif

/* EOF */
