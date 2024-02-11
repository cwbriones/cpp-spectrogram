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
