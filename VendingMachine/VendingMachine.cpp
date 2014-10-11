#include "VendingMachine.h"
#include "CoinRegister.h"
#include <cstdio>

using namespace VendingMachineApp;

const char* INSERT_COIN_MESSAGE = "INSERT COIN";

VendingMachine::VendingMachine(CoinRegisterInterface *coinRegister, ProductCatalogInterface* productCatalog)
    : ReturnedCoins()
    , DisplayMessage(INSERT_COIN_MESSAGE)
    , TheCoinRegister(coinRegister)
    , TheProductCatalog(productCatalog)
{
}

VendingMachine::~VendingMachine()
{
    delete TheProductCatalog;
    TheProductCatalog = NULL;

    delete TheCoinRegister;
    TheCoinRegister = NULL;
}

std::string VendingMachine::GenerateFormattedMessage(double total)
{
    char buffer[4];
    std::sprintf(buffer, "%0.2f", total);
    std::string formattedString(buffer);

    return formattedString;
}

std::string VendingMachine::ReadDisplay()
{
    return this->DisplayMessage;
}

void VendingMachine::Insert(std::string coin)
{
    if (TheCoinRegister->Accept(coin))
    {
        double total = TheCoinRegister->CalculateTotalInserted();
        std::string formattedMessage = GenerateFormattedMessage(total);
        this->DisplayMessage = (total > 0 ? formattedMessage : std::string(INSERT_COIN_MESSAGE));
    }
    else
    {
        ReturnedCoins.push_back(coin);
    }
}

std::vector<std::string> VendingMachine::CheckCoinReturn()
{
    return ReturnedCoins;
}

void VendingMachine::SelectProduct(std::string product)
{
    Product productToVend = TheProductCatalog->GetProduct(product);
    if (TheCoinRegister->HasAtLeast(productToVend.GetPrice()))
    {
        this->DisplayMessage = "THANK YOU";
    }
}
