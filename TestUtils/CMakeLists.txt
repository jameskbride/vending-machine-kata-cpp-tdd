#shared libs
if(BUILD_WITH_UNIT_TESTS OR BUILD_WITH_ACCEPTANCE_TESTS)
    set(project_test_utils_src
        CoinRegisterMock.h
        CoinRegisterMock.cpp
    )

    add_library(TestUtilsLib ${project_test_utils_src})
    add_dependencies(TestUtilsLib VendingMachineLib)
endif(BUILD_WITH_UNIT_TESTS OR BUILD_WITH_ACCEPTANCE_TESTS)
