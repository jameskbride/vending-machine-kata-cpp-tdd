if(BUILD_WITH_ACCEPTANCE_TESTS)
    set(project_feature_src
        features/step_definitions/VendingMachineSteps.cpp
    )

    #get the cucumber libraries
    set(CUKE_INCLUDE_DIRS /usr/include/cucumber-cpp)
    set(CUKE_LIBRARIES libcucumber-cpp.a)

    #get boost
    set(CUKE_CORE_BOOST_LIBS thread system regex date_time)
    set(CUKE_DYNAMIC_BOOST_LIBS ${CUKE_CORE_BOOST_LIBS} ${CUKE_TEST_BOOST_LIBS})
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DBOOST_ALL_DYN_LINK")
    set(Boost_USE_STATIC_LIBS OFF)
    find_package(Boost COMPONENTS ${CUKE_DYNAMIC_BOOST_LIBS})
    include_directories(${Boost_INCLUDE_DIRS})

    #define the cuke extra libs
    set(CUKE_EXTRA_LIBRARIES ${CUKE_EXTRA_LIBRARIES} ${Boost_THREAD_LIBRARY} ${Boost_SYSTEM_LIBRARY} ${Boost_REGEX_LIBRARY} ${Boost_DATE_TIME_LIBRARY})

    #Create the cucumber wire server to provide steps
    add_executable(VendingMachineSteps ${project_feature_src})
    add_dependencies(VendingMachineSteps VendingMachineLib TestUtilsLib)
    target_link_libraries(VendingMachineSteps ${CUKE_LIBRARIES} ${CUKE_EXTRA_LIBRARIES} ${GTEST_LIBRARIES} ${GMOCK_LIBRARIES} pthread VendingMachineLib TestUtilsLib)
endif(BUILD_WITH_ACCEPTANCE_TESTS)
