/*
 * Copyright (C) Christian Briones, 2013
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, see <http://www.gnu.org/licenses/>.
 */

#ifndef COLORGRADIENT_H_
#define COLORGRADIENT_H_

#include <vector>
#include "FreeImage.h"

struct RGBA_Color {
    int r;
    int g;
    int b;
    int a;

    RGBQUAD toFreeImageQuad(){
        RGBQUAD quad;

        quad.rgbReserved = a;
        quad.rgbRed = r;
        quad.rgbGreen = g;
        quad.rgbBlue = b;

        return quad;
    }
};

class ColorGradient {
    public:
        void set_min(float min){
            min_ = min;
        }
        void set_max(float max){
            max_ = max;
        }

        void add_color(RGBA_Color);
        RGBA_Color get_color(float value);
    private:
        float min_ = 0.0;
        float max_ = 1.0;

        int interpolate(int start, int finish, float ratio);

        std::vector<RGBA_Color> colors_;
};

#endif /* COLORGRADIENT_H_ */
