#ifndef PRODUCT_CATALOG_H
#define PRODUCT_CATALOG_H

#include "ProductCatalogInterface.h"

namespace VendingMachineApp
{
    class ProductCatalog : public ProductCatalogInterface
    {
    public:
        ProductCatalog();
        Product GetProduct(const std::string& product);
    };
}
#endif // PRODUCT_CATALOG_H
