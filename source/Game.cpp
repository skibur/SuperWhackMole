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

/**
 * Initialize the game.
 */
void Game::init(void)
{
	romfsInit();
	gfxInitDefault();
	C3D_Init(C3D_DEFAULT_CMDBUF_SIZE);
	C2D_Init(C2D_DEFAULT_MAX_OBJECTS);
	C2D_Prepare();
}

/**
 * Check if start was pressed.
 * @return True or False.
 */
bool Game::isStartPressed(void)
{
	// Scan for user input
	hidScanInput();

	u32 kDown = hidKeysDown();

	if (kDown & KEY_START)
	{
		return true;
	}
	else {
		return false;
	}
}

/**
 * Begin sync drawing frame.
 */
void Game::frameBegin(void)
{
	C3D_FrameBegin(C3D_FRAME_SYNCDRAW);
}

/**
 * Update game data.
 */
void Game::update(void)
{
	// TODO
}

/**
 * Render game objects.
 */
void Game::render(void)
{
	// TODO
}

/**
 * End sync drawing frame.
 */
void Game::frameEnd(void)
{
	C3D_FrameEnd(0);
}

/**
 * Exit game.
 */
void Game::exit(void)
{
	C2D_Fini();
	C3D_Fini();
	romfsExit();
	gfxExit();
}