#ifndef VENDINGMACHINE_H
#define VENDINGMACHINE_H

#include <string>
#include <vector>

namespace VendingMachineApp {

    class VendingMachine
    {
    public:
        VendingMachine();

        std::string readDisplay();
        void insert(std::string coin);
        std::vector<std::string> checkCoinReturn();

    private:
        std::vector<std::string> InsertedCoins;
        std::vector<std::string> ReturnedCoins;
        std::vector<std::string> ValidCoins;

        double calculateTotalInserted();
        std::string generateFormattedMessage(double total);
        bool isValidCoin(std::string coin);
    };
}

#endif // VENDINGMACHINE_H
