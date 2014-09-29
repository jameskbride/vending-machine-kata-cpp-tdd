#include <VendingMachine.h>

#include <gtest/gtest.h>

using namespace VendingMachineApp;
using namespace testing;

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

TEST_F(VendingMachineTest, GivenANickelIsInsertedThenTheDisplayShouldReadFiveCents) {
    vendingMachine.insert(NICKEL);

    EXPECT_EQ("0.05", vendingMachine.readDisplay());
}

TEST_F(VendingMachineTest, GivenADimeIsInsertedThenTheDisplayShouldReadTenCents) {
    vendingMachine.insert(DIME);

    EXPECT_EQ("0.10", vendingMachine.readDisplay());
}

TEST_F(VendingMachineTest, GivenAQuarterIsInsertedThenTheDisplayShouldReadTwentyFiveCents) {
    vendingMachine.insert(QUARTER);

    EXPECT_EQ("0.25", vendingMachine.readDisplay());
}
