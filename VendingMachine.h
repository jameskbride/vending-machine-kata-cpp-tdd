#ifndef VENDINGMACHINE_H
#define VENDINGMACHINE_H

#include <string>
#include <vector>

namespace VendingMachineApp {

    enum coins {
        NICKEL,
        DIME
    };

    class VendingMachine
    {
    public:
        VendingMachine();

        std::string readDisplay();
        void insert(coins coin);

    private:
        std::vector<coins> InsertedCoins;

        double calculateTotalInserted();
        std::string generateFormattedMessage(double total);
    };
}

#endif // VENDINGMACHINE_H
