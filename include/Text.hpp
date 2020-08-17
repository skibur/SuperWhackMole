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

#ifndef TEXT_HPP
#define TEXT_HPP

#include <vector>
#include <citro2d.h>

#define BATCH true

using std::vector;

typedef struct
{
	const char* str;
	float x_pos;
	float y_pos;
	float width;
	float height;
	u32 color;
	C2D_Text Text;
	C2D_TextBuf textBuf;
} TextStruct;

class Text
{
public:
	float size = 0.6f;
	C2D_Text Text;
	C2D_TextBuf textBuf;
	vector<TextStruct> batchList;
	void init(void);
	void init(bool);
	void init(const char* str);
	void setup(const char* str);
	void addText(const char* str, float x_pos, float y_pos, float width, float height, u32 color);
	void draw(float x_pos, float y_pos, float width, float height);
	void drawAll(void);
	void cleanUp(void);
	void cleanUpAll(void);
};

#endif
