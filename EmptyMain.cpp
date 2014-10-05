#include <gtest/gtest.h>

//This file only exists to allow the main build
//to run all tests on post_build.
int main(int argc, char *argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

