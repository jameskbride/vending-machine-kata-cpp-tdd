cmake_minimum_required(VERSION 2.8)
project(vending-machine-kata CXX)

option(BUILD_WITH_UNIT_TESTS "Build with unit tests" ON)
option(BUILD_WITH_ACCEPTANCE_TESTS "Build with acceptance tests" ON)

include_directories(${CMAKE_SOURCE_DIR})

#define all the sources
add_subdirectory(VendingMachine)

#shared libs
if(BUILD_WITH_UNIT_TESTS OR BUILD_WITH_ACCEPTANCE_TESTS)
    #get the gmock and cucumber libraries
    find_package(GTest REQUIRED)
    set(GMOCK_INCLUDE_DIRS /usr/include/gmock)
    set(GMOCK_LIBRARIES
        libgmock.a
        libgmock_main.a
    )
    include_directories(${GTEST_INCLUDE_DIRS} ${GMOCK_INCLUDE_DIRS} )
    enable_testing()

    #Add the test utility classes
    add_subdirectory(TestUtils)
endif(BUILD_WITH_UNIT_TESTS OR BUILD_WITH_ACCEPTANCE_TESTS)

if(BUILD_WITH_UNIT_TESTS)
    add_subdirectory(VendingMachineTests)
endif(BUILD_WITH_UNIT_TESTS)

if(BUILD_WITH_ACCEPTANCE_TESTS)
    add_subdirectory(VendingMachineAcceptanceTests)
endif(BUILD_WITH_ACCEPTANCE_TESTS)

if(BUILD_WITH_UNIT_TESTS AND BUILD_WITH_ACCEPTANCE_TESTS)
    set(empty_main_src
        EmptyMain.cpp
    )

    #Run all unit tests and cukes
    add_executable(RunAllTests ${empty_main_src})
    target_link_libraries(RunAllTests ${CUKE_LIBRARIES} ${CUKE_EXTRA_LIBRARIES} ${GTEST_LIBRARIES} ${GMOCK_LIBRARIES} pthread)

    add_custom_command(TARGET RunAllTests
        POST_BUILD
        COMMAND RunTests
        COMMAND VendingMachineSteps 55555 &
        COMMAND cucumber -s ${CMAKE_SOURCE_DIR}/VendingMachineAcceptanceTests/features
    )
endif(BUILD_WITH_UNIT_TESTS AND BUILD_WITH_ACCEPTANCE_TESTS)

