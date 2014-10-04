#include "VendingMachine.h"
#include <cstdio>

using namespace VendingMachineApp;

const char* INSERT_COIN_MESSAGE = "INSERT COIN";
const char* NICKEL = "NICKEL";
const char* DIME = "DIME";
const char* QUARTER = "QUARTER";

VendingMachine::VendingMachine()
    : InsertedCoins()
    , ValidCoins()
{
    ValidCoins.push_back(NICKEL);
    ValidCoins.push_back(DIME);
    ValidCoins.push_back(QUARTER);
}

VendingMachine::VendingMachine(const VendingMachine &rhs)
    : InsertedCoins(rhs.InsertedCoins)
    , ReturnedCoins(rhs.ReturnedCoins)
{

}

bool VendingMachine::operator==(const VendingMachine& rhs) const {
    return (this->InsertedCoins == rhs.InsertedCoins) &&
            (this->ReturnedCoins == rhs.ReturnedCoins);
}

bool VendingMachine::operator!=(const VendingMachine& rhs) const {
    return !(*this == rhs);
}

VendingMachine& VendingMachine::operator=(const VendingMachine& rhs) {
    if (this != &rhs) {
        InsertedCoins = rhs.InsertedCoins;
        ReturnedCoins = rhs.ReturnedCoins;
    }

    return (*this);
}

double VendingMachine::calculateTotalInserted() {
    double total = 0.0;
    for (std::vector<std::string>::iterator it = InsertedCoins.begin(); it != InsertedCoins.end(); ++it) {
        if (*it == NICKEL) {
            total += 0.05;
        } else if (*it == DIME) {
            total += 0.10;
        } else if (*it == QUARTER) {
            total += 0.25;
        } else {
            total += 0.0;
        }
    }

    return total;
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

bool VendingMachine::isValidCoin(std::string coin)
{
    bool foundCoin = false;
    for (std::vector<std::string>::iterator it = ValidCoins.begin(); it != ValidCoins.end(); ++it) {
        if (*it != coin) {
            continue;
        }

        foundCoin = true;
    }

    return foundCoin;
}

void VendingMachine::insert(std::string coin) {
    if (isValidCoin(coin)) {
        InsertedCoins.push_back(coin);
    } else {
        ReturnedCoins.push_back(coin);
    }
}

std::vector<std::string> VendingMachine::checkCoinReturn() const {
    return ReturnedCoins;
}
