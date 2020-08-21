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

#include "SplashScene.hpp"

 /**
  * Initialize the game.
  */
void SplashScene::init(void)
{
	top_screen = C2D_CreateScreenTarget(GFX_TOP, GFX_LEFT);
	splashTopImage.addImage("romfs:/gfx/splash_top.t3x", 0.0f, 0.0f);
	
	bottom_screen = C2D_CreateScreenTarget(GFX_BOTTOM, GFX_LEFT);
	splashBottomImage.addImage("romfs:/gfx/splash_bottom.t3x", 0.0f, 0.0f);

	this->render();
}

/**
 * Update game data.
 */
void SplashScene::update(void)
{
	// TODO
}

/**
 * Render game objects.
 */
void SplashScene::render(void)
{
	u64 start = osGetTime();

	C3D_FrameBegin(C3D_FRAME_SYNCDRAW);

	C2D_TargetClear(top_screen, COLOR_BLACK);
	C2D_SceneBegin(top_screen);
	splashTopImage.draw();

	C2D_TargetClear(bottom_screen, COLOR_BLACK);
	C2D_SceneBegin(bottom_screen);
	splashBottomImage.draw();

	C3D_FrameEnd(0);

	u8 count = 0;
	while (count != 4)
	{
		u64 end = osGetTime();
		count = (end - start)/1000;
	}

	C3D_FrameBegin(C3D_FRAME_SYNCDRAW);

	C2D_TargetClear(top_screen, COLOR_BLACK);
	C2D_SceneBegin(top_screen);
	C2D_TargetClear(bottom_screen, COLOR_BLACK);
	C2D_SceneBegin(bottom_screen);

	C3D_FrameEnd(0);

	this->exit();
}

/**
 * Exit game.
 */
void SplashScene::exit(void)
{
	splashTopImage.exit();
	splashBottomImage.exit();
}