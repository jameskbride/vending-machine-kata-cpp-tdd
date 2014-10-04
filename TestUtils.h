#ifndef _TEST_UTILS_H
#define _TEST_UTILS_H
#include <gmock/gmock.h>
namespace VendingMachineApp {
    MATCHER_P(InCoinReturnSlot, vendingMachine, "") {
        bool foundCoin = false;
        std::vector<std::string> returnedCoins(vendingMachine.checkCoinReturn());
        for (std::vector<std::string>::iterator it = returnedCoins.begin(); it != returnedCoins.end(); ++it) {
            if (*it != arg) {
                continue;
            }

            foundCoin = true;
        }

        return foundCoin;
    }
}
#endif // _TEST_UTILS_H
