#include "Product.h"

using namespace VendingMachineApp;

Product::Product(std::string name, double price)
    : Name(name)
    , Price(price)
{

}

bool Product::operator==(const Product &rhs) const
{
    return (this->Name == rhs.Name) && (this->Price == rhs.Price);
}

bool Product::operator!=(const Product &rhs) const
{
    return !(*this == rhs);
}

double Product::GetPrice()
{
    return Price;
}

std::string Product::GetName()
{
    return Name;
}
