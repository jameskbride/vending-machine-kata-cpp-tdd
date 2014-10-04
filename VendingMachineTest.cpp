#include <VendingMachine.h>
#include <gmock/gmock.h>
#include <gtest/gtest.h>

using namespace VendingMachineApp;
using namespace testing;

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
    VendingMachine vendingMachine;
};

TEST_P(VendingMachineSingleCoinTest, GivenACoinItShouldDisplayTheCorrectMessage) {
    vendingMachine.insert(GetParam().Coin);

    EXPECT_EQ(GetParam().ExpectedMessage, vendingMachine.readDisplay());
}

INSTANTIATE_TEST_CASE_P(ParameterizedSingleCoinTest, VendingMachineSingleCoinTest,
    Values(
        CoinTestValues("NICKEL",  "0.05"),
        CoinTestValues("DIME",    "0.10"),
        CoinTestValues("QUARTER", "0.25"),
        CoinTestValues("PENNY",   "INSERT COIN")
    )
);

class VendingMachineTest : public Test {

public:
    VendingMachineTest() {

    }

    ~VendingMachineTest() {

    }

    VendingMachine vendingMachine;
};

TEST_F(VendingMachineTest, GivenNoCoinsThenTheDisplayShouldReadINSERTCOIN) {
    EXPECT_EQ("INSERT COIN", vendingMachine.readDisplay());
}

TEST_F(VendingMachineTest, WhenTheVendingMachineIsCopiedWithNoCoinsThenTheNewVendingMachineShouldMatchTheExistingMachine) {
    VendingMachine copiedMachine(vendingMachine);

    EXPECT_EQ(copiedMachine, vendingMachine);
}

TEST_F(VendingMachineTest, WhenTheVendingMachineIsCopiedWithInsertedCoinsThenTheNewVendingMachineShouldMatchTheExistingMachine) {
    vendingMachine.insert("NICKEL");

    VendingMachine copiedMachine(vendingMachine);

    EXPECT_EQ(copiedMachine, vendingMachine);
}

TEST_F(VendingMachineTest, WhenTheVendingMachineIsCopiedWithReturnedCoinsThenTheNewVendingMachineShouldMatchTheExistingMachine) {
    vendingMachine.insert("PENNY");

    VendingMachine copiedMachine(vendingMachine);

    EXPECT_EQ(copiedMachine, vendingMachine);
}

TEST_F(VendingMachineTest, GivenTwoVendingMachinesWithDifferentInsertedCoinsThenThenTheyShouldNotBeEqual) {
    vendingMachine.insert("NICKEL");

    VendingMachine emptyVendingMachine;

    EXPECT_NE(emptyVendingMachine, vendingMachine);
}

TEST_F(VendingMachineTest, GivenTwoVendingMachinesWithDifferentReturnedCoinsThenTheyShouldNotBeEqual) {
    vendingMachine.insert("PENNY");

    VendingMachine emptyVendingMachine;

    EXPECT_NE(emptyVendingMachine, vendingMachine);
}

//MATCHER_P(InCoinReturnSlot, vendingMachine, "") {
//    bool foundCoin = false;
//    std::vector<std::string> returnedCoins = vendingMachine.checkCoinReturn();
//    for (std::vector<std::string>::iterator it = returnedCoins.begin(); it != returnedCoins.end(); ++it) {
//        if (*it != arg) {
//            continue;
//        }

//        foundCoin = true;
//    }

//    return foundCoin;
//}

//TEST_F(VendingMachineTest, DISABLED_GivenAPennyIsInsertedThenTheCoinReturnShouldContainThePenny) {
//    std::string penny("penny");
//    vendingMachine.insert(penny);

//    EXPECT_THAT("penny", InCoinReturnSlot<VendingMachine>(vendingMachine));
//}
