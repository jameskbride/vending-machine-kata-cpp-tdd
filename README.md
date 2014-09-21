# C++ TDD/BDD Example Project

This project demonstrates how to implement TDD and BDD in C++ development.  
It will include examples for how to use Google's GTest and GMock frameworks
for unit testing and mocking.  It will also include examples for cucumber-cpp,
a C++ implementation of Cucumber, the BDD tool.

This project requires:
* Boost 1.4 or later (`thread`, `system`, `regex`, and `date_time` libraries specifically)
* GTest 1.6
* GMock 1.6
* Qt4
* Ruby (I used 2.1.3, the latest, but I'm sure it will work with older versions)
* cucumber-cpp

The following steps are recommended (and are specific to Ubuntu 14.04, though they may work in lower versions):
1. Install boost via: `sudo apt-get install libboost-all-dev`
2. Install Ruby via RVM (http://rvm.io/rvm/install)
3. Install qt4 via: `sudo apt-get install libqt4-dev`
4. Install GMock and GTest by downloading the latest version of GMock (1.7 at the moment) from https://code.google.com/p/googlemock, following the instructions to install it from the README.  GTest comes bundled with GMock, which helps to insure that there isn't a dependency mismatch. 
	1. After building copy the .a files to /usr/lib
	2. Also be sure to copy the include/gmock directory to /usr/include (be sure the entire gmock directory is copied)
	3. Build the bundled gtest as well, via CMake in the gtest directory
	4. Copy the .a and include/gtest to their respective locations (/usr/lib and /usr/include)
5. Download cucumber-cpp (https://github.com/cucumber/cucumber-cpp) and build it from source. NOTE: I ran into issues with pthread dependencies.  I fixed this by adding `-lpthread` to the `CMAKE_EXE_LINKER_FLAGS`
6. Once cucumber-cpp has been built (and good luck with that btw, may God have mercy on your soul.), you'll need to perform the same steps that you did with GMock and GTest, copying the .a (located in the `src` directory) files to `/usr/lib` and the `include/cucumber-cpp` directory to `/usr/include`.
While you _can_ get GTest and GMock via apt on Ubuntu I recommend against it as I paid a 
high cost in time an energy trying to get these libraries to play nice with cucumber-cpp, which
is not currently distributed in any convenient package form. I ran into a number of version inconsistencies by attempting to use the distributed packages instead of the downloaded and built source.

I primarily followed Rich Dammkoehler's directions (and blame him for this whole affair, which serves him right for doing the right thing and sharing his knowledge :) ), found at https://github.com/rdammkoehler/CucumberCPPDemoProject.  The added benefit is that I got cucumber-cpp working on a version of Ubuntu later than 10.04 (so in your face Rich!).

I'm sure I've forgotten something here, and when I remember it I'll update this README.  This is a work in progress, so bear with me.

Major props to Rich, as his git repo is the very first result when googling for "cucumber-cpp cmake".  May you live in internet infamy.

