#ifndef COIN_REGISTER_INTERFACE_H
#define COIN_REGISTER_INTERFACE_H
#include <string>

namespace VendingMachineApp
{
    class CoinRegisterInterface
    {
    public:
        virtual ~CoinRegisterInterface(){}
        virtual bool IsValidCoin(const std::string& coin) = 0;
        virtual bool Accept(const std::string& coin) = 0;
        virtual double CalculateTotalInserted() = 0;
        virtual bool HasAtLeast(const double amount) = 0;
    };
}
#endif // COIN_REGISTER_INTERFACE_H
