#ifndef VENDINGMACHINE_H
#define VENDINGMACHINE_H
#include "CoinRegisterInterface.h"

#include <string>
#include <vector>

namespace VendingMachineApp
{

    class VendingMachine
    {
    public:
        VendingMachine();
        ~VendingMachine();
    private:
        std::string GenerateFormattedMessage(double total);
        //Not implemented
        VendingMachine(const VendingMachine& rhs);
    };
}

#endif // VENDINGMACHINE_H
