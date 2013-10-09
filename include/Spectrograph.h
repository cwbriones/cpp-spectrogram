#ifndef SPECTROGRAPH_H_
#define SPECTROGRAPH_H_

#include <string>
#include <sndfile.hh>
#include <vector>
#include <complex>
#include <functional>

#include <map>

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

    RGBQUAD get_color(std::complex<double>& c, float threshold);
    std::complex<double> omega(float p, float q);
    void read_in_data();

    std::string fname_;

    SndfileHandle file_handle_;
    std::vector<short> data_;

    Spectrogram_t spectrogram_;

    int height_ = 480;
    int width_ = height_ * 5;

    float max_frequency_ = 0.5 * 44800;

    std::function<double(int, int)> window_;
    std::map<float, std::complex<double>> omega_cache_;
};

#endif /* SPECTROGRAPH_H_ */
