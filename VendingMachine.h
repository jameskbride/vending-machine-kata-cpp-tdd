#ifndef VENDINGMACHINE_H
#define VENDINGMACHINE_H
#include "CoinRegisterInterface.h"
#include <string>
#include <vector>

namespace VendingMachineApp {

    class VendingMachine
    {
    public:
        VendingMachine();
        ~VendingMachine();


        std::string readDisplay();
        void insert(std::string coin);
        std::vector<std::string> checkCoinReturn();

    private:
        std::vector<std::string> ReturnedCoins;
        CoinRegisterInterface* TheCoinRegister;

        double calculateTotalInserted();
        std::string generateFormattedMessage(double total);
        //Not implemented
        VendingMachine(const VendingMachine& rhs);
    };
}

#endif // VENDINGMACHINE_H
