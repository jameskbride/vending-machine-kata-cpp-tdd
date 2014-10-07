#include <VendingMachine/ProductCatalog.h>
#include <gtest/gtest.h>
#include <gmock/gmock.h>

using namespace VendingMachineApp;
using namespace testing;


MATCHER_P2(MatchesProduct, name, price, "")
{
    Product expectedProduct(name, price);

    return arg == expectedProduct;
}

class ProductCatalogTest : public Test
{
public:
    ProductCatalogTest()
    {
    }

    ~ProductCatalogTest()
    {
    }

    ProductCatalog TheProductCatalog;
};

TEST_F(ProductCatalogTest, WhenChipsAreRequestedThenTheProductIsReturned)
{
    Product actualProduct = TheProductCatalog.GetProduct("CHIPS");
    EXPECT_THAT(actualProduct, MatchesProduct("CHIPS", 0.50));
}
