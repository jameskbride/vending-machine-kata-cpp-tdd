#include <VendingMachine.h>
#include <CoinRegister.h>
#include <CoinRegisterInterfaceMock.h>
#include <gmock/gmock.h>
#include <gtest/gtest.h>

using namespace VendingMachineApp;
using namespace testing;

class VendingMachineTest : public Test
{

public:
    VendingMachineTest()
        : TheCoinRegisterMock(new NiceMock<CoinRegisterInterfaceMock>())
        , TheVendingMachine(TheCoinRegisterMock)

    {
    }

    ~VendingMachineTest()
    {
    }

    bool FoundReturnedCoin(std::string penny)
    {
        bool foundCoin = false;
        std::vector<std::string> returnedCoins = TheVendingMachine.CheckCoinReturn();
        for (std::vector<std::string>::iterator it = returnedCoins.begin(); it != returnedCoins.end(); ++it)
        {
            if (*it != penny) {
                continue;
            }

            foundCoin = true;
        }

        return foundCoin;
    }

    NiceMock<CoinRegisterInterfaceMock>* TheCoinRegisterMock;
    VendingMachine TheVendingMachine;
};

TEST_F(VendingMachineTest, GivenNoCoinsThenTheDisplayShouldReadINSERTCOIN)
{
    EXPECT_EQ("INSERT COIN", TheVendingMachine.ReadDisplay());
}

TEST_F(VendingMachineTest, GivenAPennyIsInsertedThenTheCoinReturnShouldContainThePenny)
{
    std::string penny("penny");
    TheVendingMachine.Insert(penny);

    EXPECT_TRUE(FoundReturnedCoin(penny));
}

TEST_F(VendingMachineTest, WhenTheCoinRegisterContainsFiftyCentsThenTheDisplayShouldReadFiftyCents)
{
    EXPECT_CALL(*TheCoinRegisterMock, CalculateTotalInserted()).WillOnce(Return(0.50));

    EXPECT_EQ("0.50", TheVendingMachine.ReadDisplay());
}

TEST_F(VendingMachineTest, WhenTheCoinRegisterIsEmptyThenTheDisplayShouldReadINSERTCOIN)
{
    EXPECT_CALL(*TheCoinRegisterMock, CalculateTotalInserted()).WillOnce(Return(0.00));

    EXPECT_EQ("INSERT COIN", TheVendingMachine.ReadDisplay());
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
    VendingMachineSingleCoinTest()
        : TheCoinRegister(new CoinRegister())
        , TheVendingMachine(TheCoinRegister)
    {

    }

    CoinRegisterInterface* TheCoinRegister;
    VendingMachine TheVendingMachine;
};

TEST_P(VendingMachineSingleCoinTest, GivenACoinItShouldDisplayTheCorrectMessage)
{
    TheVendingMachine.Insert(GetParam().Coin);

    EXPECT_EQ(GetParam().ExpectedMessage, TheVendingMachine.ReadDisplay());
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
