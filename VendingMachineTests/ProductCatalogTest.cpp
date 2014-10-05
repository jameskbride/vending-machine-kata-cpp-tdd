#include <VendingMachine/ProductCatalog.h>
#include <gtest/gtest.h>

using namespace VendingMachineApp;
using namespace testing;

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
    Product chips ("CHIPS", 0.50);

    EXPECT_EQ(chips, TheProductCatalog.GetProduct("CHIPS"));
}
