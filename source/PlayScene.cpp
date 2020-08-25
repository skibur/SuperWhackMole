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

#include "PlayScene.hpp"
#include "Scene.hpp"

/**
* Constructor of the main scene
*/
PlayScene::PlayScene(Game* game)
{
	this->game = game;
	consoleInit(GFX_TOP, NULL);
	bottom_screen = C2D_CreateScreenTarget(GFX_BOTTOM, GFX_LEFT);

	// Clear screen
	C3D_FrameBegin(C3D_FRAME_SYNCDRAW);
	C2D_TargetClear(bottom_screen, COLOR_BLACK);
	C2D_SceneBegin(bottom_screen);
	C3D_FrameEnd(0);
}

/**
 * Destructor of the play scene.
 */
PlayScene::~PlayScene()
{
	// TODO
}

/**
 * Input handling.
 */
void PlayScene::input()
{
	hidScanInput();
	hidTouchRead(&touch);

	u32 kDown = hidKeysDown();

	if (kDown & KEY_START)
	{
		// Clear top screen
		top_screen = C2D_CreateScreenTarget(GFX_TOP, GFX_LEFT);
		C3D_FrameBegin(C3D_FRAME_SYNCDRAW);
		C2D_TargetClear(top_screen, COLOR_BLACK);
		C2D_SceneBegin(top_screen);
		C3D_FrameEnd(0);

		// Flush and swap framebuffers
		gfxFlushBuffers();
		gfxSwapBuffers();

		//Wait for VBlank
		gspWaitForVBlank();
		this->game->popState();
	}
}

/**
 * Update game data.
 */
void PlayScene::update(const float dt)
{
	// TODO
}

/**
 * Render game objects.
 */
void PlayScene::render(const float dt)
{
	printf("%03d, %03d\n", touch.px, touch.py);
}

/**
 * Clean up game.
 */
void PlayScene::cleanUp()
{
	// TODO
}

/**
 * Exit game.
 */
bool PlayScene::exit(void)
{
	return this->exit_flag;
}