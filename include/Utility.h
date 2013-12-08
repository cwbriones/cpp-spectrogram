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
