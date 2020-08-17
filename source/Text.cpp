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

#include "Text.hpp"

 /**
  * Initialize the text.
  */
void Text::init(void)
{
	textBuf = C2D_TextBufNew(C2D_DEFAULT_MAX_OBJECTS);
}

/**
 * Initialize the text.
 */
void Text::init(bool)
{
	textBuf = C2D_TextBufNew(C2D_DEFAULT_MAX_OBJECTS);
}

/**
 * Initialize the game.
 *
 * @param str A string of text.
 */
void Text::init(const char* str)
{
	textBuf = C2D_TextBufNew(C2D_DEFAULT_MAX_OBJECTS);
	C2D_TextParse(&Text, textBuf, str);
	C2D_TextOptimize(&Text);
}

/**
 * Initialize the game.
 *
 * @param str A string of text.
 */

void Text::setup(const char* str)
{
	C2D_TextParse(&Text, textBuf, str);
	C2D_TextOptimize(&Text);
}

/**
 * Add text on a given text size and position with color.
 *
 * @param str A string of text.
 * @param x_pos X-axis point for text (upper left).
 * @param y_pos Y-axis point for text (upper left).
 * @param width Width of text.
 * @param height Height of text.
 * @param color The color of the text.
 */
void Text::addText(const char* str, float x_pos, float y_pos, float width, float height, u32 color)
{
	TextStruct tmp;
	tmp.str = str;
	tmp.x_pos = x_pos;
	tmp.y_pos = y_pos;
	tmp.width = width;
	tmp.height = height;
	tmp.color = color;
	tmp.textBuf = C2D_TextBufNew(C2D_DEFAULT_MAX_OBJECTS);
	C2D_TextParse(&tmp.Text, tmp.textBuf, tmp.str);
	C2D_TextOptimize(&tmp.Text);
	batchList.push_back(tmp);
	tmp = TextStruct();
}

/**
 * Draw text to screen on a given position.
 *
 * @param x_pos X-axis point for text (upper left).
 * @param y_pos Y-axis point for text (upper left).
 * @param width Width of text.
 * @param height Height of text.
 */
void Text::draw(float x_pos, float y_pos, float width, float height)
{
	C2D_DrawText(&Text, 0, x_pos, y_pos, 0.5f, width, height);
}

/**
 * Draw all text to screen.
 */
void Text::drawAll(void)
{	
	for (auto iter : batchList)
	{
		C2D_DrawText(&iter.Text, C2D_WithColor,
			iter.x_pos, iter.y_pos, 0.5f, iter.width, iter.height, iter.color);
	}
}

/**
 * Clean up text buffer.
 */
void Text::cleanUp(void)
{
	C2D_TextBufDelete(textBuf);
}

/**
 * Clean up all text buffers.
 */
void Text::cleanUpAll(void)
{
	for (auto iter : batchList)
	{
		C2D_TextBufDelete(iter.textBuf);
	}
}
