#ifndef COIN_REGISTER_INTERFACE_MOCK_H
#define COIN_REGISTER_INTERFACE_MOCK_H
#include "CoinRegisterInterface.h"
#include <gmock/gmock.h>

class CoinRegisterInterfaceMock : public CoinRegisterInterface
{
public:
    CoinRegisterInterfaceMock();
    virtual ~CoinRegisterInterfaceMock();

    MOCK_METHOD1(IsValidCoin, bool(const std::string&));
    MOCK_METHOD1(Accept, bool(const std::string&));
    MOCK_METHOD0(CalculateTotalInserted, double());
};

#endif // COIN_REGISTER_INTERFACE_MOCK_H
