#include <VendingMachine.h>
#include <CoinRegister.h>
#include <ProductCatalog.h>
#include <cucumber-cpp/defs.hpp>
#include <gtest/gtest.h>

using namespace VendingMachineApp;
using cucumber::ScenarioScope;

struct Context {
    Context()
        : TheCoinRegister(new CoinRegister())
        , TheProductCatalog(new ProductCatalog())
        , vendingMachine(TheCoinRegister, TheProductCatalog)
    {

    }

    CoinRegisterInterface* TheCoinRegister;
    ProductCatalogInterface* TheProductCatalog;
	VendingMachine vendingMachine;
};

WHEN("^no coins are inserted$")
{
    //Do nothing
}

GIVEN("^a nickel is inserted$")
{
    ScenarioScope<Context> context;
    context->vendingMachine.Insert("NICKEL");
}

GIVEN("^a dime is inserted$")
{
    ScenarioScope<Context> context;
    context->vendingMachine.Insert("DIME");
}

GIVEN("^a quarter is inserted$")
{
    ScenarioScope<Context> context;
    context->vendingMachine.Insert("QUARTER");
}

GIVEN("^a '(.*)' is inserted$")
{
    ScenarioScope<Context> context;
    REGEX_PARAM(std::string, invalidCoin);
    context->vendingMachine.Insert(invalidCoin);
}

WHEN("^'(.*)' are selected$") {
    ScenarioScope<Context> context;
    REGEX_PARAM(std::string, product);

    context->vendingMachine.SelectProduct(product);
}

THEN("^the vending machine displays '(.*)'$")
{
    ScenarioScope<Context> context;
    REGEX_PARAM(std::string, displayValue);
    EXPECT_EQ(displayValue, context->vendingMachine.ReadDisplay());
}

THEN("^the coin return contains the '(.*)'$")
{
    ScenarioScope<Context> context;
    REGEX_PARAM(std::string, invalidCoin);
    bool foundCoin = false;
    std::vector<std::string> returnedCoins = context->vendingMachine.CheckCoinReturn();
    for (std::vector<std::string>::iterator it = returnedCoins.begin(); it != returnedCoins.end(); ++it)
    {
        if (*it != invalidCoin) {
            continue;
        }

        foundCoin = true;
    }

    EXPECT_TRUE(foundCoin);
}

