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

#ifndef GAME_HPP
#define GAME_HPP

#include <citro2d.h>
#include <cstdlib>
#include <vector>

using std::vector;

class Scene;

class Game
{
public:
	Game();
	~Game();
	Scene* CurrentState();
	C3D_RenderTarget* getBottom();
	C3D_RenderTarget* getTop();
	bool exit = false;
	void loop();
	void pushState(Scene* state);
	void popState();
	void exitGame();
private:
	C3D_RenderTarget* bottom;
	C3D_RenderTarget* top;
	vector<Scene*> states;
};

#endif