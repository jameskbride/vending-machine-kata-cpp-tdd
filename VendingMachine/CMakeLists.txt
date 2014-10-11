set(project_src
    CoinRegisterInterface.h
    CoinRegister.h
    CoinRegister.cpp
    Product.h
    Product.cpp
    ProductCatalogInterface.h
    ProductCatalog.h
    ProductCatalog.cpp
    VendingMachine.h
    VendingMachine.cpp
)

#create the VendingMachine lib
add_library(VendingMachineLib ${project_src})
