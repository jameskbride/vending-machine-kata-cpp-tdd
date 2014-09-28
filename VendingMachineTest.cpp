#include <VendingMachine.h>

#include <gtest/gtest.h>

TEST(VendingMachineTest, GivenNoCoinsThenTheDisplayShouldReadINSERTCOIN) {
    VendingMachine vendingMachine;

    EXPECT_EQ("INSERT COIN", vendingMachine.readDisplay());
}
