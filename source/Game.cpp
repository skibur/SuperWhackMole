/**
 * Copyright 2020 Juan A. Sauceda <jasauceda@skibur.com>
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

#include "Game.hpp"
#include "Scene.hpp"

/**
 * Constructor for the game.
 */
Game::Game()
{
	romfsInit();
	gfxInitDefault();
	C3D_Init(C3D_DEFAULT_CMDBUF_SIZE);
	C2D_Init(C2D_DEFAULT_MAX_OBJECTS);
	C2D_Prepare();
}

/**
 * Destructor for the game
 */
Game::~Game()
{
	while (!states.empty())
		popState();
}

/**
 * A pointer to the current scene in vector states
 * @return Scene
 */
Scene* Game::CurrentState()
{
	if (states.empty())
		return nullptr;
	else
		return states.back();
}

/**
 * Main Game loop
 */
void Game::loop()
{
	while (aptMainLoop())
	{
		float dt = 10.0f;

		//exception handling
		if (CurrentState() == nullptr)
			continue;

		//get user input for current game state
		CurrentState()->input();

		//update anything neccessary
		CurrentState()->update(dt);

		//draw anything in the current game state
		CurrentState()->render(dt);

		if (CurrentState()->exit())
			break;
	}
	this->exitGame();
}

/**
 * Push scene to vector state.
 */
void Game::pushState(Scene* state)
{
	states.push_back(state);
}

/**
 * Pop scene from vector state.
 */
void Game::popState()
{
	states.back();
	delete states.back();
	states.pop_back();
}

/**
 * Exit game.
 */
void Game::exitGame(void)
{
	C2D_Fini();
	C3D_Fini();
	romfsExit();
	gfxExit();
}