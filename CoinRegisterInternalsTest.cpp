#include <CoinRegister.h>
#include <gtest/gtest.h>

using namespace VendingMachineApp;
using namespace testing;
class CoinRegisterInternalsTest : public Test
{
public:
    CoinRegisterInternalsTest()
    {
    }

    ~CoinRegisterInternalsTest()
    {
    }

    CoinRegister TheCoinRegister;
};

TEST_F(CoinRegisterInternalsTest, WhenTheCoinRegisterIsCopiedWithNoCoinsThenTheyShouldBeEqual) {
    CoinRegister copiedReigster(TheCoinRegister);

    EXPECT_EQ(copiedReigster, TheCoinRegister);
}

TEST_F(CoinRegisterInternalsTest, WhenTheCoinRegisterIsCopiedWithInsertedCoinsThenTheyShouldBeEqual) {
    ASSERT_TRUE(TheCoinRegister.Accept("NICKEL"));

    CoinRegister copiedRegister(TheCoinRegister);

    EXPECT_EQ(copiedRegister, TheCoinRegister);
}

TEST_F(CoinRegisterInternalsTest, GivenTwoCoinRegistersWithDifferentInsertedCoinsThenThenTheyShouldNotBeEqual) {
    ASSERT_TRUE(TheCoinRegister.Accept("NICKEL"));

    CoinRegister emptyRegister;

    EXPECT_NE(emptyRegister, TheCoinRegister);
}

TEST_F(CoinRegisterInternalsTest, WhenACoinRegisterIsAssignedThenTheTotalShouldMatch) {
    ASSERT_TRUE(TheCoinRegister.Accept("NICKEL"));
    ASSERT_TRUE(TheCoinRegister.Accept("DIME"));

    CoinRegister newCoinRegister;
    newCoinRegister = TheCoinRegister;

    EXPECT_DOUBLE_EQ(0.15, newCoinRegister.CalculateTotalInserted());
}
