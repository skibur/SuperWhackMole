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

#include "Image.hpp"

 /**
  * Clean up text buffer.
  */
void Image::addImage(const char* spriteFile, float x_pos, float y_pos)
{
	spriteSheet = C2D_SpriteSheetLoad(spriteFile);
	C2D_SpriteFromSheet(&spr, spriteSheet, 0);
	C2D_SpriteSetPos(&spr, x_pos, y_pos);
}

/**
 * Draw image to screen.
 */
void Image::draw(void)
{
	C2D_DrawSprite(&spr);
}

/**
 * Clean up image sheet.
 */
void Image::exit(void)
{
	C2D_SpriteSheetFree(spriteSheet);
}