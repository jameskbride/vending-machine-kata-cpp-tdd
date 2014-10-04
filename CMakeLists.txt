cmake_minimum_required(VERSION 2.8)
project(vending-machine-kata CXX)
find_package(GTest REQUIRED)

set(GMOCK_INCLUDE_DIRS /usr/include/gmock)
set(GMOCK_LIBRARIES
    libgmock.a
    libgmock_main.a
)

set(project_src
    VendingMachine.h
    VendingMachine.cpp
)

set(project_test_src
    ExampleTestsMain.cpp
    VendingMachineTest.cpp
)

set(project_feature_src
    features/step_definitions/VendingMachineSteps.cpp
)

set(project_test_utils_src
    TestUtils.h
)

add_library(VendingMachineLib ${project_src})

include_directories(${GTEST_INCLUDE_DIRS} ${GMOCK_INCLUDE_DIRS} ${CMAKE_SOURCE_DIR})
enable_testing()
add_executable(RunTests ${project_test_src} ${project_src} ${project_test_utils_src})
target_link_libraries(RunTests ${GTEST_LIBRARIES} ${GMOCK_LIBRARIES} pthread)
add_dependencies(RunTests SpeakerLib)

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
add_executable(VendingMachineSteps ${project_feature_src} ${project_src} ${project_test_utils_src})
target_link_libraries(VendingMachineSteps ${CUKE_LIBRARIES} ${CUKE_EXTRA_LIBRARIES} ${GTEST_LIBRARIES} ${GMOCK_LIBRARIES} pthread)
add_dependencies(VendingMachineSteps VendingMachineLib)

add_executable(RunAllTests ${project_test_src} ${project_feature_src} ${project_src})
target_link_libraries(RunAllTests ${CUKE_LIBRARIES} ${CUKE_EXTRA_LIBRARIES} ${GTEST_LIBRARIES} ${GMOCK_LIBRARIES} pthread)

add_custom_command(TARGET RunAllTests
    POST_BUILD
    COMMAND RunTests
    COMMAND VendingMachineSteps 55555 &
    COMMAND cucumber -s ${CMAKE_SOURCE_DIR}/features
)
