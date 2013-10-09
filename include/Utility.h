#ifndef UTILITY_H_
#define UTILITY_H_

#include <vector>
#include <complex>
#include <iostream>

#include <functional>
#include <map>

typedef std::complex<double> complex_d;

namespace Utility {

    void pad(std::vector<complex_d>& data, int padded_size);
    int pad_to_power2(std::vector<complex_d>& data, int min_size);
    uint32_t reverse_bits(uint32_t val, int power);
    const double EPSILON = 1.0e-6;

    double hann_function(int n, int samples);
    double blackman_harris(int n, int samples);

    double mag(complex_d& c);
    double abs(complex_d& c);

    void flatten(complex_d& c);
    void flatten(std::vector<complex_d>& signal);

    template <class Iterator>
    void print_nums(Iterator start, Iterator end){
        while (start != end){
            std::cout << *start << ' ';
            ++start;
        }
        std::cout << std::endl;
    }

    template <class R, class ... Args>
    std::function<R(Args...)> memoize(R(*fn)(Args...)){
        std::map<std::tuple<Args ...>, R> cache;

        return [fn, cache](Args ... args) mutable -> R {
            auto arg_tuple = std::make_tuple(args...);
            auto memo = cache.find(arg_tuple);

            if (memo != cache.end()){
                return memo->second;
            }

            auto result = fn(args...);
            cache[arg_tuple] = result;
            return result;
        };
    }
}

#endif /* UTILITY_H_ */
