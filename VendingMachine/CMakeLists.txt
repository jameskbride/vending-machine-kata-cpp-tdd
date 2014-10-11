set(project_src
    CoinRegisterInterface.h
    VendingMachine.h
    VendingMachine.cpp
)

#create the VendingMachine lib
add_library(VendingMachineLib ${project_src})
