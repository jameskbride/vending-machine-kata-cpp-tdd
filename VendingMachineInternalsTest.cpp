#include <VendingMachine.h>
#include <gtest/gtest.h>

using namespace VendingMachineApp;
using namespace testing;

class VendingMachineInternalsTest : public Test {

public:
    VendingMachineInternalsTest() {

    }

    ~VendingMachineInternalsTest() {

    }

    VendingMachine vendingMachine;
};

TEST_F(VendingMachineInternalsTest, WhenTheVendingMachineIsCopiedWithNoCoinsThenTheyShouldBeEqual) {
    VendingMachine copiedMachine(vendingMachine);

    EXPECT_EQ(copiedMachine, vendingMachine);
}

TEST_F(VendingMachineInternalsTest, WhenTheVendingMachineIsCopiedWithInsertedCoinsThenTheyShouldBeEqual) {
    vendingMachine.insert("NICKEL");

    VendingMachine copiedMachine(vendingMachine);

    EXPECT_EQ(copiedMachine, vendingMachine);
}

TEST_F(VendingMachineInternalsTest, WhenTheVendingMachineIsCopiedWithReturnedCoinsThenTheyShouldBeEqual) {
    vendingMachine.insert("PENNY");

    VendingMachine copiedMachine(vendingMachine);

    EXPECT_EQ(copiedMachine, vendingMachine);
}

TEST_F(VendingMachineInternalsTest, GivenTwoVendingMachinesWithDifferentInsertedCoinsThenThenTheyShouldNotBeEqual) {
    vendingMachine.insert("NICKEL");

    VendingMachine emptyVendingMachine;

    EXPECT_NE(emptyVendingMachine, vendingMachine);
}

TEST_F(VendingMachineInternalsTest, GivenTwoVendingMachinesWithDifferentReturnedCoinsThenTheyShouldNotBeEqual) {
    vendingMachine.insert("PENNY");

    VendingMachine emptyVendingMachine;

    EXPECT_NE(emptyVendingMachine, vendingMachine);
}

TEST_F(VendingMachineInternalsTest, WhenAVendingMachineIsAssignedThenTheDisplayedTotalShouldMatch) {
    vendingMachine.insert("NICKEL");
    vendingMachine.insert("DIME");

    VendingMachine newVendingMachine;
    newVendingMachine = vendingMachine;

    EXPECT_EQ("0.15", newVendingMachine.readDisplay());
}
