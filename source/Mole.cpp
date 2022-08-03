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

#include "Mole.hpp"

 /**
  * Clean up text buffer.
  */
Mole::Mole(float x_pos, float y_pos)
{
	spriteSheet = C2D_SpriteSheetLoad("romfs:/gfx/mole.t3x");
	C2D_SpriteFromSheet(&spr, spriteSheet, 11);
	C2D_SpriteSetPos(&spr, x_pos, y_pos);
    x = x_pos;
    y = y_pos;
    x_width = 50;
    y_height = 40;
    status = true;
    hit = false;
}

/**
 * Draw image to screen.
 */
void Mole::draw(void)
{
	C2D_DrawSprite(&spr);
    if (hit)
    {
        C2D_SpriteFromSheet(&spr, spriteSheet, 12);
	    C2D_SpriteSetPos(&spr, x, y);
        C2D_DrawSprite(&spr);
        hit = false;
    }

}

bool Mole::checkHit(touchPosition& touch)
{
    if (status)
    {
        if ((x < touch.px) &&
            (touch.px < x + x_width) &&
            (y < touch.py) &&
            (touch.py < y + y_height))
            return true;
    }
    return false;
}

void Mole::setHit(void)
{
    hit = true;
}

/**
 * Clean up image sheet.
 */
void Mole::exit(void)
{
	C2D_SpriteSheetFree(spriteSheet);
}