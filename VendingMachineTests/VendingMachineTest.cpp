#include <VendingMachine/VendingMachine.h>
#include <gmock/gmock.h>
#include <gtest/gtest.h>

using namespace VendingMachineApp;
using namespace testing;

class VendingMachineTest : public Test {

public:
    VendingMachineTest() {

    }

    ~VendingMachineTest() {

    }

    bool InCoinReturnSlot(const std::string& coin)
    {
        bool foundCoin = false;
        std::vector<std::string> returnedCoins(TheVendingMachine.checkCoinReturn());
        for (std::vector<std::string>::iterator it = returnedCoins.begin(); it != returnedCoins.end(); ++it) {
            if (*it != coin) {
                continue;
            }

            foundCoin = true;
        }

        return foundCoin;
    }

    VendingMachine TheVendingMachine;
};

TEST_F(VendingMachineTest, GivenNoCoinsThenTheDisplayShouldReadINSERTCOIN)
{
    EXPECT_EQ("INSERT COIN", TheVendingMachine.readDisplay());
}

TEST_F(VendingMachineTest, GivenAPennyIsInsertedThenTheCoinReturnShouldContainThePenny)
{
    std::string penny("penny");
    TheVendingMachine.insert(penny);

    EXPECT_TRUE(InCoinReturnSlot(penny));
}

// TEST_P Example
/////////////////////////////////////////////////////////////////
struct CoinTestValues {
    CoinTestValues(std::string coin, std::string expectedMessage)
        : Coin(coin)
        , ExpectedMessage(expectedMessage)
    {
    }

    std::string Coin;
    std::string ExpectedMessage;
};

class VendingMachineSingleCoinTest : public TestWithParam<CoinTestValues> {
public:
    VendingMachine TheVendingMachine;
};

TEST_P(VendingMachineSingleCoinTest, GivenACoinItShouldDisplayTheCorrectMessage) {
    TheVendingMachine.insert(GetParam().Coin);

    EXPECT_EQ(GetParam().ExpectedMessage, TheVendingMachine.readDisplay());
}

INSTANTIATE_TEST_CASE_P(ParameterizedSingleCoinTest, VendingMachineSingleCoinTest,
    Values(
        CoinTestValues("NICKEL",  "0.05"),
        CoinTestValues("DIME",    "0.10"),
        CoinTestValues("QUARTER", "0.25"),
        CoinTestValues("PENNY",   "INSERT COIN")
    )
);

//////////////////////////////////////////////////////////////////////
