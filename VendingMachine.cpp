#include "VendingMachine.h"
#include <cstdio>

using namespace VendingMachineApp;

const char* INSERT_COIN_MESSAGE = "INSERT COIN";

VendingMachine::VendingMachine()
    : InsertedCoins()
{
}

double VendingMachine::calculateTotalInserted()
{
    double total = 0.0;
    for (std::vector<coins>::iterator it = InsertedCoins.begin(); it != InsertedCoins.end(); ++it) {
        switch (*it) {
        case NICKEL:
            total += 0.05;
            break;
        case DIME:
            total += 0.10;
            break;
        case QUARTER:
            total += 0.25;
            break;
        default:
            total += 0.0;
            break;
        }
    }

    return total;
}

std::string VendingMachine::generateFormattedMessage(double total)
{
    char buffer[4];
    std::sprintf(buffer, "%0.2f", total);
    std::string formattedString(buffer);

    return formattedString;
}

std::string VendingMachine::readDisplay()
{
    double total = calculateTotalInserted();
    std::string formattedMessage = generateFormattedMessage(total);
    return total > 0 ? formattedMessage : std::string(INSERT_COIN_MESSAGE);
}

void VendingMachine::insert(coins coin) {
    InsertedCoins.push_back(coin);
}
