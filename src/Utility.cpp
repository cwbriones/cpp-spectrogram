#include "Utility.h"
#include <cmath>
#include <functional>

namespace Utility {

    uint32_t reverse_bits(uint32_t val, int power){
        int reversed = 0;

        for (int i = 0; i < power; i++){
            bool cur_bit = (1 << i) & val;
            reversed |= (cur_bit << (power - i - 1));
        }
        return reversed;
    }
    
    double hann_function(int n, int samples){
        return 0.5 * (1.0 - cos((2.0 * M_PI * n)/(samples - 1.0)));
    }

    double blackman_harris(int n, int samples){
        const float a0 = 0.35875;
        const float a1 = 0.48829;
        const float a2 = 0.14128;
        const float a3 = 0.01168;

        const float arg = 2 * M_PI * n / (samples - 1);

        return a0 - a1 * cos(arg) + a2 * cos(2 * arg) - a3 * cos( 3 * arg);
    }

    void flatten(complex_d& c){
        double real = std::abs(c.real()) < EPSILON ? 0.0 : c.real();
        double imag = std::abs(c.imag()) < EPSILON ? 0.0 : c.imag();

        c = complex_d(real, imag);
    }

    void flatten(std::vector<complex_d>& signal){
        for (auto& c : signal){
            flatten(c);
        }
    }

    double mag(complex_d& c){
        return c.real() * c.real() + c.imag() * c.imag();
    }

    double abs(complex_d& c){
        return sqrt(c.real() * c.real() + c.imag() + c.imag());
    }

    complex_d omega(float p, float q){
        const float trig_arg = 2 * M_PI * q / p;
        return complex_d(cos(trig_arg), sin(trig_arg));
    }
};
