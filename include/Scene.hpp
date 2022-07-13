/**
 * Copyright 2022 Juan A. Sauceda <jasauceda@skibur.com>
 *
 * This program is free software; you can redistribute itand /or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111 - 1307  USA
 */

#ifndef SCENE_HPP
#define SCENE_HPP

#include "Game.hpp"

class Scene
{
public:
	Game* game;
	virtual ~Scene() = default;
	// Provide implementation for the following methods
	virtual void input() = 0;
	virtual void update(const float dt) = 0;
	virtual void render(const float dt) = 0;
	virtual void cleanUp() = 0;
	virtual bool exit() = 0;
};

#endif