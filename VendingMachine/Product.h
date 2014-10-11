#ifndef PRODUCT_H
#define PRODUCT_H
#include <string>

namespace VendingMachineApp {
    class Product
    {
    public:
        Product(std::string name, double price);
        bool operator==(const Product& rhs) const;
        bool operator!=(const Product& rhs) const;

        double GetPrice();

    private:
        std::string Name;
        double Price;
    };
}
#endif // PRODUCT_H
