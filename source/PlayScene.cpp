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

#include <sstream>
#include "Mole.hpp"
#include "PlayScene.hpp"
#include "Scene.hpp"
#include "Text.hpp"

using std::to_string;

/**
* Constructor of the main scene
*/
PlayScene::PlayScene(Game* game)
{
	this->game = game;
	playsceneTopImage.addImage("romfs:/gfx/playscene_top.t3x", 0.0f, 0.0f);
	playsceneBottomImage.addImage("romfs:/gfx/playscene_bottom.t3x", 0.0f, 0.0f);

	cords.init();
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

	// if ((touch.px != 0) && touch.py != 0)
	// 	cords.setup(to_string(touch.px) + ", " + to_string(touch.py));

	u32 kDown = hidKeysDown();

	if (Moles.size() > 0)
	{
		for (Mole mole : Moles)
		{
			if (mole.checkHit(touch))
			{
				cords.setup("Hit!");
				mole.setHit();
				cords.clearText();
			}

		}
	}

	if (kDown & KEY_START)
	{
		u64 start = osGetTime();
		u8 count = 0;
		while (count != 1)
		{
			u64 end = osGetTime();
			count = (end - start) / 1000;
		}
		this->cleanUp();
		this->game->popState();
	}
}

/**
 * Update game data.
 */
void PlayScene::update(const float dt)
{
	if (Moles.size() == 0)
	{
		// Top
		Moles.push_back(Mole(16.0f, 40.0f));
		Moles.push_back(Mole(76.0f, 40.0f));
		Moles.push_back(Mole(136.0f, 40.0f));
		Moles.push_back(Mole(196.0f, 40.0f));
		Moles.push_back(Mole(256.0f, 40.0f));

		//Middle
		Moles.push_back(Mole(16.0f, 100.0f));
		Moles.push_back(Mole(76.0f, 100.0f));
		Moles.push_back(Mole(136.0f, 100.0f));
		Moles.push_back(Mole(196.0f, 100.0f));
		Moles.push_back(Mole(256.0f, 100.0f));

		//Bottom
		Moles.push_back(Mole(16.0f, 160.0f));
		Moles.push_back(Mole(76.0f, 160.0f));
		Moles.push_back(Mole(136.0f, 160.0f));
		Moles.push_back(Mole(196.0f, 160.0f));
		Moles.push_back(Mole(256.0f, 160.0f));
	}
}

/**
 * Render game objects.
 */
void PlayScene::render(const float dt)
{
	C3D_FrameBegin(C3D_FRAME_SYNCDRAW);
	C2D_SceneBegin(game->getTop());
	playsceneTopImage.draw();
	cords.draw(10, 10, 2, 2);

	C2D_SceneBegin(game->getBottom());
	playsceneBottomImage.draw();
	if (Moles.size() > 0)
	{
		for (Mole mole : Moles)
			mole.draw();
	}
	C3D_FrameEnd(0);
}

/**
 * Clean up game.
 */
void PlayScene::cleanUp()
{
	playsceneTopImage.exit();
	playsceneBottomImage.exit();
	if (Moles.size() > 0)
	{
		for (Mole mole : Moles)
			mole.exit();
	}
	cords.cleanUp();
}

/**
 * Exit game.
 */
bool PlayScene::exit(void)
{
	return this->exit_flag;
}