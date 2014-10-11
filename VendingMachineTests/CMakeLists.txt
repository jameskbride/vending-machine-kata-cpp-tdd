#unit tests
if(BUILD_WITH_UNIT_TESTS)
    set(project_test_src
        ExampleTestsMain.cpp
        VendingMachineTest.cpp
    )

    add_executable(RunTests ${project_test_src})
    add_dependencies(RunTests VendingMachineLib TestUtilsLib)
    target_link_libraries(RunTests ${GTEST_LIBRARIES} ${GMOCK_LIBRARIES} pthread VendingMachineLib TestUtilsLib)
endif(BUILD_WITH_UNIT_TESTS)
