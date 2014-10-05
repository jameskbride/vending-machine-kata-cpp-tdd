#include <VendingMachine.h>
#include <gmock/gmock.h>
#include <gtest/gtest.h>

using namespace VendingMachineApp;
using namespace testing;

class VendingMachineTest : public Test
{

public:
    VendingMachineTest()
    {

    }

    ~VendingMachineTest()
    {

    }

    bool FoundReturnedCoin(std::string penny)
    {
        bool foundCoin = false;
        std::vector<std::string> returnedCoins = vendingMachine.CheckCoinReturn();
        for (std::vector<std::string>::iterator it = returnedCoins.begin(); it != returnedCoins.end(); ++it)
        {
            if (*it != penny) {
                continue;
            }

            foundCoin = true;
        }

        return foundCoin;
    }

    VendingMachine vendingMachine;
};

TEST_F(VendingMachineTest, GivenNoCoinsThenTheDisplayShouldReadINSERTCOIN)
{
    EXPECT_EQ("INSERT COIN", vendingMachine.ReadDisplay());
}

TEST_F(VendingMachineTest, GivenAPennyIsInsertedThenTheCoinReturnShouldContainThePenny)
{
    std::string penny("penny");
    vendingMachine.Insert(penny);

    EXPECT_TRUE(FoundReturnedCoin(penny));
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

class VendingMachineSingleCoinTest : public TestWithParam<CoinTestValues>
{
public:
    VendingMachine vendingMachine;
};

TEST_P(VendingMachineSingleCoinTest, GivenACoinItShouldDisplayTheCorrectMessage)
{
    vendingMachine.Insert(GetParam().Coin);

    EXPECT_EQ(GetParam().ExpectedMessage, vendingMachine.ReadDisplay());
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
