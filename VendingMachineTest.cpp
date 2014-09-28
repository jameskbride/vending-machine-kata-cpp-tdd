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

TEST_F(VendingMachineTest, GivenANickelIsInsertedThenTheDisplayShouldReadFiveCents)
{
    vendingMachine.insert(NICKEL);

    EXPECT_EQ("0.05", vendingMachine.readDisplay());
}
