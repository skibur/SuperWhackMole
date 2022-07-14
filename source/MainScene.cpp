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

#include "MainScene.hpp"
#include "Scene.hpp"
#include "PlayScene.hpp"

/**
* Constructor of the main scene.
*/
MainScene::MainScene(Game* game)
{
	this->game = game;
	spriteSheet = C2D_SpriteSheetLoad("romfs:/gfx/main_scene.t3x");
}

/**
 * Destructor of the main scene.
 */
MainScene::~MainScene(void)
{
	// TODO
}

/**
 * Input handling.
 */
void MainScene::input(void)
{
	hidScanInput();
	hidTouchRead(&touch);

	if (touch.px >= 100.0f && touch.px <= 220.0f &&
		touch.py >= 40.0f && touch.py <= 80.0f)
	{
		play_select = true;
	}
	else {
		play_select = false;
	}

	if (touch.px >= 100.0f && touch.px <= 220.0f &&
		touch.py >= 100.0f && touch.py <= 140.0f)
	{
		about_select = true;
	}
	else {
		about_select = false;
	}

	if (touch.px >= 100.0f && touch.px <= 220.0f &&
		touch.py >= 160.0f && touch.py <= 200.0f)
	{
		exit_select = true;
		this->set_exit = true;
	}
	else {
		exit_select = false;
	}
}

/**
 * Update game data.
 */
void MainScene::update(const float dt)
{
	C2D_SpriteFromSheet(&play_button, spriteSheet, PLAY);
	C2D_SpriteFromSheet(&about_button, spriteSheet, ABOUT);
	C2D_SpriteFromSheet(&exit_button, spriteSheet, EXIT);
	C2D_SpriteFromSheet(&select_button, spriteSheet, SELECT);
	C2D_SpriteSetPos(&play_button, 100.0f, 40.0f);
	C2D_SpriteSetPos(&about_button, 100.0f, 100.0f);
	C2D_SpriteSetPos(&exit_button, 100.0f, 160.0f);
}

/**
 * Render game objects.
 */
void MainScene::render(const float dt)
{
	C3D_FrameBegin(C3D_FRAME_SYNCDRAW);
	C2D_TargetClear(game->getBottom(), COLOR_BLACK);
	C2D_SceneBegin(game->getBottom());

	C2D_DrawSprite(&play_button);
	C2D_DrawSprite(&about_button);
	C2D_DrawSprite(&exit_button);

	if (play_select)
	{
		u64 start = osGetTime();
		C2D_SpriteSetPos(&select_button, 97.0f, 37.0f);
		C2D_DrawSprite(&select_button);
		C3D_FrameEnd(0);
		u8 count = 0;
		while (count != 1)
		{
			u64 end = osGetTime();
			count = (end - start) / 1000;
		}
		this->loadPlay();
		play_select = false;
	}

	if (about_select)
	{
		C2D_SpriteSetPos(&select_button, 97.0f, 97.0f);
		C2D_DrawSprite(&select_button);
		C3D_FrameEnd(0);
	}

	if (exit_select)
	{
		u64 start = osGetTime();
		C2D_SpriteSetPos(&select_button, 97.0f, 157.0f);
		C2D_DrawSprite(&select_button);
		C3D_FrameEnd(0);
		u8 count = 0;
		while (count != 1)
		{
			u64 end = osGetTime();
			count = (end - start) / 1000;
		}
		this->cleanUp();
		this->exit_flag = true;
	}
	C3D_FrameEnd(0);
}

/**
 * Exit Scene.
 * @return true or false.
 */
bool MainScene::exit()
{
	return this->exit_flag;
}

/**
 * Exit game.
 */
void MainScene::cleanUp(void)
{
	C2D_SpriteSheetFree(spriteSheet);
}

/**
 * Load play scene
 */
void MainScene::loadPlay()
{
	game->pushState(new PlayScene(game));
}