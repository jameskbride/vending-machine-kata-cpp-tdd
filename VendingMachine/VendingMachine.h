#ifndef VENDINGMACHINE_H
#define VENDINGMACHINE_H
#include "CoinRegisterInterface.h"
#include "ProductCatalogInterface.h"

#include <string>
#include <vector>

namespace VendingMachineApp
{

    class VendingMachine
    {
    public:
        VendingMachine(CoinRegisterInterface* coinRegister, ProductCatalogInterface* productCatalog);
        ~VendingMachine();


        std::string ReadDisplay();
        void Insert(std::string coin);
        std::vector<std::string> CheckCoinReturn();
        void SelectProduct(std::string product);

    private:
        std::vector<std::string> ReturnedCoins;
        std::string DisplayMessage;
        CoinRegisterInterface* TheCoinRegister;
        ProductCatalogInterface* TheProductCatalog;

        std::string GenerateFormattedMessage(double total);
        //Not implemented
        VendingMachine(const VendingMachine& rhs);
    };
}

#endif // VENDINGMACHINE_H
