#include <CoinRegister.h>
#include <gtest/gtest.h>

using namespace VendingMachineApp;
using namespace testing;

class CoinRegisterTest : public Test
{
public:
    CoinRegisterTest()
        : TheCoinRegister()
    {
    }

    ~CoinRegisterTest()
    {
    }

    CoinRegister TheCoinRegister;
};

TEST_F(CoinRegisterTest, WhenANickelIsCheckedThenItIsValid)
{
    std::string nickel("NICKEL");

    EXPECT_TRUE(TheCoinRegister.IsValidCoin(nickel));
}

TEST_F(CoinRegisterTest, WhenADimeIsCheckedThenItIsValid)
{
    std::string dime("DIME");

    EXPECT_TRUE(TheCoinRegister.IsValidCoin(dime));
}

TEST_F(CoinRegisterTest, WhenAQuarterIsCheckedThenItIsValid)
{
    std::string quarter("QUARTER");

    EXPECT_TRUE(TheCoinRegister.IsValidCoin(quarter));
}

TEST_F(CoinRegisterTest, WhenAPennyIsCheckedThenItIsInValid)
{
    std::string penny("PENNY");

    EXPECT_FALSE(TheCoinRegister.IsValidCoin(penny));
}

TEST_F(CoinRegisterTest, GivenANickelIsInsertedWhenTheTotalIsCalculatedThenItIsFiveCents)
{
    ASSERT_TRUE(TheCoinRegister.Accept("NICKEL"));

    EXPECT_DOUBLE_EQ(0.05, TheCoinRegister.CalculateTotalInserted());
}

TEST_F(CoinRegisterTest, GivenADimeIsInsertedWhenTheTotalIsCalculatedThenItIsTenCents)
{
    ASSERT_TRUE(TheCoinRegister.Accept("DIME"));

    EXPECT_DOUBLE_EQ(0.10, TheCoinRegister.CalculateTotalInserted());
}
TEST_F(CoinRegisterTest, GivenAQuarterIsInsertedWhenTheTotalIsCalculatedThenItIsTwentyFiveCents)
{
    ASSERT_TRUE(TheCoinRegister.Accept("QUARTER"));

    EXPECT_DOUBLE_EQ(0.25, TheCoinRegister.CalculateTotalInserted());
}

TEST_F(CoinRegisterTest, GivenAPennyIsInsertedWhenTheTotalIsCalculatedThenItIsZeroCents)
{
    ASSERT_FALSE(TheCoinRegister.Accept("PENNY"));

    EXPECT_DOUBLE_EQ(0.00, TheCoinRegister.CalculateTotalInserted());
}
