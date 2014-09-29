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

    private:
        std::vector<std::string> InsertedCoins;

        double calculateTotalInserted();
        std::string generateFormattedMessage(double total);
    };
}

#endif // VENDINGMACHINE_H
