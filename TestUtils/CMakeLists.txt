#shared libs
if(BUILD_WITH_UNIT_TESTS OR BUILD_WITH_ACCEPTANCE_TESTS)
    set(project_test_utils_src
        CoinRegisterInterfaceMock.h
        CoinRegisterInterfaceMock.cpp
        ProductCatalogInterfaceMock.h
        ProductCatalogInterfaceMock.cpp
    )

    add_library(TestUtilsLib ${project_test_utils_src})
    add_dependencies(TestUtilsLib VendingMachineLib)
endif(BUILD_WITH_UNIT_TESTS OR BUILD_WITH_ACCEPTANCE_TESTS)
