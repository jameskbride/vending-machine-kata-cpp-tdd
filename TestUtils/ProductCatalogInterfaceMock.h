#ifndef PRODUCT_CATALOG_INTERFACE_MOCK_H
#define PRODUCT_CATALOG_INTERFACE_MOCK_H

#include <VendingMachine/ProductCatalogInterface.h>

#include <gmock/gmock.h>

namespace VendingMachineApp
{
    class ProductCatalogInterfaceMock : public ProductCatalogInterface
    {
    public:
        MOCK_METHOD1(GetProduct, Product(const std::string&));
    };
}

#endif // PRODUCT_CATALOG_INTERFACE_MOCK_H
