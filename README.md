# C++ Spectrogram

A spectrogram written in C++.

You will need the FreeImage library and a C++11 compatible compiler to
compile the program.

Run with (assuming g++)
```
$ mkdir build & cd build
$ g++ -o spectro ../src/*.cpp -I ../include -std=c++11
$ ./spectro <filename>
```

The file is saved as spectrograph.png in the same directory as the
executable.

Currently there is no way to specify command line arguments, so you will
have to code them in if you would like to change settings.

## Copying
This source is released under the MIT license.

NOTE: Prior releases of this project were released under GPLv3.

## Contributing
This project was only ever intended as a learning exercise and is not currently
accepting any contributions.

You are welcome to fork and use the code under the terms of the license.
