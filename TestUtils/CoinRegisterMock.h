#ifndef COINREGISTERMOCK_H
#define COINREGISTERMOCK_H
#include <VendingMachine/CoinRegisterInterface.h>

namespace VendingMachineApp
{
    class CoinRegisterMock : public CoinRegisterInterface
    {
    public:
        CoinRegisterMock();
    };
}

#endif // COINREGISTERMOCK_H
