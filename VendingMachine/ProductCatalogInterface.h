#ifndef PRODUCT_CATALOG_INTERFACE_H
#define PRODUCT_CATALOG_INTERFACE_H

#include "Product.h"

namespace VendingMachineApp
{
    class ProductCatalogInterface
    {
    public:
        virtual ~ProductCatalogInterface() {}
        virtual Product GetProduct(const std::string& product) = 0;
    };
}

#endif // PRODUCT_CATALOG_INTERFACE_H
