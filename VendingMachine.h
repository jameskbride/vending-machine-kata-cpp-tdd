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


        std::string ReadDisplay();
        void Insert(std::string coin);
        std::vector<std::string> CheckCoinReturn();

    private:
        std::vector<std::string> ReturnedCoins;
        CoinRegisterInterface* TheCoinRegister;

        std::string GenerateFormattedMessage(double total);
        //Not implemented
        VendingMachine(const VendingMachine& rhs);
    };
}

#endif // VENDINGMACHINE_H
