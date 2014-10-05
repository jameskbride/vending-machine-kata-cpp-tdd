#include "CoinRegister.h"

using namespace VendingMachineApp;

const char* NICKEL = "NICKEL";
const char* DIME = "DIME";
const char* QUARTER = "QUARTER";

CoinRegister::CoinRegister()
    : ValidCoins()
    , InsertedCoins()
{
    ValidCoins.push_back(NICKEL);
    ValidCoins.push_back(DIME);
    ValidCoins.push_back(QUARTER);
}

CoinRegister::~CoinRegister()
{
}

CoinRegister::CoinRegister(const CoinRegister &rhs)
    : InsertedCoins(rhs.InsertedCoins)
{

}

bool CoinRegister::IsValidCoin(const std::string& coin)
{
    bool foundCoin = false;
    for (std::vector<std::string>::iterator it = ValidCoins.begin(); it != ValidCoins.end(); ++it)
    {
        if (*it != coin)
        {
            continue;
        }

        foundCoin = true;
    }

    return foundCoin;
}

bool CoinRegister::Accept(const std::string& coin)
{
    if (IsValidCoin(coin)) {
        InsertedCoins.push_back(coin);
        return true;
    }

    return false;
}

double CoinRegister::CalculateTotalInserted()
{
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
