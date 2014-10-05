#include "VendingMachine.h"
#include "CoinRegister.h"
#include <cstdio>

using namespace VendingMachineApp;

const char* INSERT_COIN_MESSAGE = "INSERT COIN";

VendingMachine::VendingMachine(CoinRegisterInterface *coinRegister)
    : ReturnedCoins()
    , TheCoinRegister(coinRegister)
{
}

VendingMachine::~VendingMachine()
{
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
    double total = TheCoinRegister->CalculateTotalInserted();
    std::string formattedMessage = GenerateFormattedMessage(total);
    return total > 0 ? formattedMessage : std::string(INSERT_COIN_MESSAGE);
}

void VendingMachine::Insert(std::string coin)
{
    if (!TheCoinRegister->Accept(coin))
    {
        ReturnedCoins.push_back(coin);
    }
}

std::vector<std::string> VendingMachine::CheckCoinReturn()
{
    return ReturnedCoins;
}
