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

#ifndef SPECTROGRAPH_H_
#define SPECTROGRAPH_H_

#include <string>
#include <sndfile.hh>
#include <vector>
#include <complex>
#include <functional>

#include <map>

#include "ColorGradient.h"
#include "FreeImage.h"

class Spectrograph {
public:
    Spectrograph(std::string fname, int width, int height);
    
    typedef std::function<double(int, int)> Window_t;
    typedef std::vector< std::vector<std::complex<double> > > Spectrogram_t;

    int width();
    int height();

    bool file_is_valid();

    void compute(const int CHUNK_SIZE = 4096, const float OVERLAP = 0.5);
    void save_image(
            std::string fname,
            bool log_mode);
            // float start_frequency = -1,
            // float end_frequency = -1

    void set_window(std::function<double(int, int)> window);

    void transform(std::vector<std::complex<double>>& signal, int min_size = -1);
    void transform_recursive(std::vector<std::complex<double>>& signal, int min_size = -1);
    void pad(std::vector<std::complex<double>>& signal, int new_size);
    int pad_to_power2(std::vector<std::complex<double>>& signal, int min_size);
private:
    void _transform(std::vector<std::complex<double>>& signal, int min_size = -1);
    int get_number_of_chunks(const int CHUNK_SIZE, const int STEP);
    void chunkify(const int CHUNK_SIZE, const int STEP);

    RGBQUAD get_color(double c, float max_threshold, float min_threshold);
    std::complex<double> omega(float p, float q);
    void read_in_data();

    std::string fname_;

    SndfileHandle file_handle_;
    std::vector<float> data_;

    Spectrogram_t spectrogram_;
    ColorGradient gradient_;

    int height_ = 480;
    int width_ = height_ * 5;

    float max_frequency_ = 0.5 * 44800;

    std::function<double(int, int)> window_;
    std::map<float, std::complex<double>> omega_cache_;
};

#endif /* SPECTROGRAPH_H_ */
