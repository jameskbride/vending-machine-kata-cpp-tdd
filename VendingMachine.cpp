#include "VendingMachine.h"
#include "CoinRegister.h"
#include <cstdio>

using namespace VendingMachineApp;

const char* INSERT_COIN_MESSAGE = "INSERT COIN";

VendingMachine::VendingMachine()
    : ReturnedCoins()
    , TheCoinRegister(new CoinRegister())
{
}

VendingMachine::~VendingMachine()
{
    delete TheCoinRegister;
    TheCoinRegister = NULL;
}

double VendingMachine::calculateTotalInserted() {
    return TheCoinRegister->CalculateTotalInserted();
}

std::string VendingMachine::generateFormattedMessage(double total) {
    char buffer[4];
    std::sprintf(buffer, "%0.2f", total);
    std::string formattedString(buffer);

    return formattedString;
}

std::string VendingMachine::readDisplay() {
    double total = calculateTotalInserted();
    std::string formattedMessage = generateFormattedMessage(total);
    return total > 0 ? formattedMessage : std::string(INSERT_COIN_MESSAGE);
}

void VendingMachine::insert(std::string coin) {
    if (!TheCoinRegister->Accept(coin))
    {
        ReturnedCoins.push_back(coin);
    }
}

std::vector<std::string> VendingMachine::checkCoinReturn() {
    return ReturnedCoins;
}
