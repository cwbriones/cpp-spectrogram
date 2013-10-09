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
