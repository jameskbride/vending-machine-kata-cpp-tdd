#ifndef COIN_REGISTER_INTERFACE_MOCK_H
#define COIN_REGISTER_INTERFACE_MOCK_H
#include <CoinRegisterInterface.h>
#include <gmock/gmock.h>

namespace VendingMachineApp {
    class CoinRegisterInterfaceMock : public CoinRegisterInterface
    {
    public:
        CoinRegisterInterfaceMock() {}
        virtual ~CoinRegisterInterfaceMock(){}

        MOCK_METHOD1(IsValidCoin, bool(const std::string&));
        MOCK_METHOD1(Accept, bool(const std::string&));
        MOCK_METHOD0(CalculateTotalInserted, double());
        MOCK_METHOD1(HasAtLeast, bool(const double));
    };
}
#endif // COIN_REGISTER_INTERFACE_MOCK_H
