#include <VendingMachine/VendingMachine.h>
#include <VendingMachine/CoinRegister.h>
#include <VendingMachine/ProductCatalog.h>
#include <TestUtils/CoinRegisterInterfaceMock.h>
#include <TestUtils/ProductCatalogInterfaceMock.h>

#include <gmock/gmock.h>
#include <gtest/gtest.h>

using namespace VendingMachineApp;
using namespace testing;

class VendingMachineTest : public Test
{

public:
    VendingMachineTest()
        : TheCoinRegisterMock(new NiceMock<CoinRegisterInterfaceMock>())
        , TheProductCatalogMock(new NiceMock<ProductCatalogInterfaceMock>())
        , TheVendingMachine(TheCoinRegisterMock, TheProductCatalogMock)
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
    NiceMock<ProductCatalogInterfaceMock>* TheProductCatalogMock;
    VendingMachine TheVendingMachine;
};

TEST_F(VendingMachineTest, GivenAPennyIsInsertedThenTheCoinReturnShouldContainThePenny)
{
    std::string penny("penny");
    EXPECT_CALL(*TheCoinRegisterMock, Accept("penny")).WillOnce(Return(false));

    TheVendingMachine.Insert(penny);

    EXPECT_TRUE(FoundReturnedCoin(penny));
}

TEST_F(VendingMachineTest, WhenTheCoinRegisterContainsFiftyCentsThenTheDisplayShouldReadFiftyCents)
{
    ON_CALL(*TheCoinRegisterMock, Accept(_)).WillByDefault(Return(true));
    EXPECT_CALL(*TheCoinRegisterMock, CalculateTotalInserted()).WillRepeatedly(Return(0.50));

    TheVendingMachine.Insert("QUARTER");
    TheVendingMachine.Insert("QUARTER");

    EXPECT_EQ("0.50", TheVendingMachine.ReadDisplay());
}

TEST_F(VendingMachineTest, WhenTheCoinRegisterIsEmptyThenTheDisplayShouldReadINSERTCOIN)
{
    EXPECT_EQ("INSERT COIN", TheVendingMachine.ReadDisplay());
}

TEST_F(VendingMachineTest, GivenEnoughMoneyHasBeenEnteredWhenChipsAreSelectedThenTheDisplayReadsTHANKYOU)
{
    Product chips("CHIPS", 0.50);
    {
        InSequence sequence;
        EXPECT_CALL(*TheProductCatalogMock, GetProduct("CHIPS")).WillOnce(Return(chips));
        EXPECT_CALL(*TheCoinRegisterMock, HasAtLeast(_)).WillOnce(Return(true));
    }

    TheVendingMachine.SelectProduct("CHIPS");
    EXPECT_EQ("THANK YOU", TheVendingMachine.ReadDisplay());
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
        , TheProductCatalog(new ProductCatalog())
        , TheVendingMachine(TheCoinRegister, TheProductCatalog)
    {

    }

    CoinRegisterInterface* TheCoinRegister;
    ProductCatalogInterface* TheProductCatalog;
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
