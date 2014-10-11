#ifndef COIN_REGISTER_H
#define COIN_REGISTER_H
#include <VendingMachine/CoinRegisterInterface.h>

#include <string>
#include <vector>

namespace VendingMachineApp
{
    class CoinRegister : public CoinRegisterInterface
    {
    public:
        CoinRegister();
        virtual ~CoinRegister();
        bool IsValidCoin(const std::string& coin);
        bool Accept(const std::string &coin);
        double CalculateTotalInserted();

    private:
        std::vector<std::string> ValidCoins;
        std::vector<std::string> InsertedCoins;
        //Not implemented
        CoinRegister(const CoinRegister& rhs);
    };
}

#endif // COIN_REGISTER_H
