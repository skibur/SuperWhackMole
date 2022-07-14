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

#ifndef SPLASHSCENE_HPP
#define SPLASHSCENE_HPP

#include "Scene.hpp"
#include "Image.hpp"
#include "colors.hpp"

class SplashScene
{
public:
	Image splashTopImage;
	Image splashBottomImage;
	C3D_RenderTarget* top_screen;
	C3D_RenderTarget* bottom_screen;
	void init(void);
	void update(void);
	void render(void);
	void cleanUp(void);
	void exit(void);
};

#endif