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

#ifndef COLORS_HPP
#define COLORS_HPP

#include <citro2d.h>

C2D_CONSTEXPR u32 COLOR_BLACK = C2D_Color32(0, 0, 0, 255);
C2D_CONSTEXPR u32 COLOR_WHITE = C2D_Color32(255, 255, 255, 255);
C2D_CONSTEXPR u32 COLOR_BLUE = C2D_Color32(0, 0, 255, 255);
C2D_CONSTEXPR u32 COLOR_RED = C2D_Color32(255, 0, 0, 255);
C2D_CONSTEXPR u32 COLOR_GREEN = C2D_Color32(0, 255, 0, 255);
C2D_CONSTEXPR u32 COLOR_BG = C2D_Color32(51, 51, 51, 255);

#endif