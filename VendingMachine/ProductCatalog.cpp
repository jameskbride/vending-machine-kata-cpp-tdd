#include "ProductCatalog.h"

using namespace VendingMachineApp;

ProductCatalog::ProductCatalog()
{
}

Product ProductCatalog::GetProduct(const std::string &/*product*/)
{
    Product product("CHIPS", 0.50);
    return product;
}
