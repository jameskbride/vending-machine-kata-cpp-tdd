#include <VendingMachine.h>

#include <gtest/gtest.h>

using namespace VendingMachineApp;

TEST(VendingMachineTest, GivenNoCoinsThenTheDisplayShouldReadINSERTCOIN) {
    VendingMachine vendingMachine;

    EXPECT_EQ("INSERT COIN", vendingMachine.readDisplay());
}

TEST(VendingMachineTest, GivenANickelIsInsertedThenTheDisplayShouldReadFiveCents)
{
    VendingMachine vendingMachine;

    vendingMachine.insert(NICKEL);

    EXPECT_EQ("0.05", vendingMachine.readDisplay());
}
