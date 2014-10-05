#include <VendingMachine/Product.h>
#include <gtest/gtest.h>

using namespace VendingMachineApp;
using namespace testing;

TEST(ProductTest, WhenProductsWithTheSameNameAndPriceAreComparedThenTheyAreEqual)
{
    Product first("", 0.0);
    Product second("", 0.0);

    EXPECT_EQ(first, second);
}

TEST(ProductTest, WhenProductsWithDifferentNamesAreComparedThenTheyAreNotEqual)
{
    Product first("", 0.0);
    Product second("different", 0.0);

    EXPECT_NE(first, second);
}

TEST(ProductTest, WhenProductsWithTheSameNameAndDifferentPricesAreComparedThenTheyAreNotEqual)
{
    Product first("", 1.0);
    Product second("", 0.0);

    EXPECT_NE(first, second);
}
