#ifndef COINREGISTERMOCK_H
#define COINREGISTERMOCK_H
#include <VendingMachine/CoinRegisterInterface.h>
#include <gmock/gmock.h>
namespace VendingMachineApp
{
    class CoinRegisterInterfaceMock : public CoinRegisterInterface
    {
    public:
        CoinRegisterInterfaceMock();

        MOCK_METHOD1(IsValidCoin, bool(const std::string&));
        MOCK_METHOD1(Accept, bool(const std::string& coin));
        MOCK_METHOD0(CalculateTotalInserted, double());
    };
}

#endif // COINREGISTERMOCK_H
