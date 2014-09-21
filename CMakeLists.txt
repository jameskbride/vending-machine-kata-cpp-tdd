cmake_minimum_required(VERSION 2.8)
project(cpp-tdd-example CXX)
find_package(GTest REQUIRED)

include_directories(${GTEST_INCLUDE_DIRS})

set(project_src
    ExampleTestsMain.cpp
    Speaker.h
    Speaker.cpp
    SpeakerTest.cpp
)

enable_testing()

add_executable(runTests ${project_src})

target_link_libraries(runTests ${GTEST_LIBRARIES} pthread)
