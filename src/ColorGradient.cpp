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

#include "ColorGradient.h"
#include <cassert>

RGBA_Color ColorGradient::get_color(float value){
    assert(colors_.size() > 1);

    if (value >= max_){
        return colors_.back();
    }
    float ratio = value/max_;
    float width = 1.0/static_cast<float>(colors_.size() - 1);
    int i = 0;

    // Find the "bin"
    while (ratio > width){
        ratio -= width;
        i++;
    }

    ratio *= colors_.size() - 1;

    assert(0.0 <= ratio);
    assert(ratio <= 1.0);
    assert(0 <= i);
    assert(i < colors_.size());

    RGBA_Color first = colors_[i];
    RGBA_Color second = colors_[i + 1];

    RGBA_Color color;
    color.a = 255;
    color.r = interpolate(first.r, second.r, ratio);
    color.g = interpolate(first.g, second.g, ratio);
    color.b = interpolate(first.b, second.b, ratio);

    return color;
}

void ColorGradient::add_color(RGBA_Color color){
    colors_.push_back(color);
}

int ColorGradient::interpolate(int start, int finish, float ratio){
    float val = static_cast<float>(finish - start) * ratio + static_cast<float>(start);

    return static_cast<int>(val);
}
