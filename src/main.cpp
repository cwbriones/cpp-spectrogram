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

#include "Spectrograph.h"
#include "Utility.h"

#include <iostream>
#include <string>

int main(int argc, const char *argv[])
{ 
    if (argc < 2){
        std::cout << "You must specify an input file." << std::endl;
        return -1;
    }
    std::string fname(argv[1]);

    Spectrograph spectrograph(fname, 800, 600);

    if (!spectrograph.file_is_valid()){
        return -1;
    }
    spectrograph.set_window(Utility::blackman_harris);
    spectrograph.compute(2048, 0.8);
    spectrograph.save_image("spectrogram.png", false);
    return 0;
}
