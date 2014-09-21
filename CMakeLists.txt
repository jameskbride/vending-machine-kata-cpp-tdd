cmake_minimum_required(VERSION 2.8)
project(cpp-tdd-example CXX)
find_package(GTest REQUIRED)

set(project_src
    Speaker.h
    Speaker.cpp
)

set(project_test_src
    ExampleTestsMain.cpp
    SpeakerTest.cpp
)

set(project_feature_src
    features/step_definitions/SpeakerSteps.cpp
)

include_directories(${GTEST_INCLUDE_DIRS} ${CMAKE_SOURCE_DIR})
enable_testing()
add_executable(runTests ${project_test_src} ${project_src})
target_link_libraries(runTests ${GTEST_LIBRARIES} pthread)

#get boost
set(CUKE_CORE_BOOST_LIBS thread system regex date_time)
set(CUKE_DYNAMIC_BOOST_LIBS ${CUKE_CORE_BOOST_LIBS} ${CUKE_TEST_BOOST_LIBS})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DBOOST_ALL_DYN_LINK")
set(Boost_USE_STATIC_LIBS OFF)
find_package(Boost COMPONENTS ${CUKE_DYNAMIC_BOOST_LIBS})
include_directories(${Boost_INCLUDE_DIRS})
set(CUKE_EXTRA_LIBRARIES ${CUKE_EXTRA_LIBRARIES} ${Boost_THREAD_LIBRARY} ${Boost_SYSTEM_LIBRARY} ${Boost_REGEX_LIBRARY} ${Boost_DATE_TIME_LIBRARY})

#Create the cucumber wire server to provide steps
set(CUKE_INCLUDE_DIRS /usr/include/cucumber-cpp)
set(CUKE_LIBRARIES libcucumber-cpp.a)
add_executable(SpeakerSteps ${project_feature_src} ${project_src})
target_link_libraries(SpeakerSteps ${CUKE_LIBRARIES} ${CUKE_EXTRA_LIBRARIES} ${GTEST_LIBRARIES} pthread)
