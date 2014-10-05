set(project_src
    CoinRegister.h
    CoinRegister.cpp
    CoinRegisterInterface.h
    Product.h
    Product.cpp
    ProductCatalog.h
    ProductCatalog.cpp
    ProductCatalogInterface.h
    VendingMachine.h
    VendingMachine.cpp
)

#create the VendingMachine lib
add_library(VendingMachineLib ${project_src})
