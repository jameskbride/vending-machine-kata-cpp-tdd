#include <TestUtils.h>
#include <VendingMachine.h>

#include <cucumber-cpp/defs.hpp>
#include <gtest/gtest.h>

using namespace VendingMachineApp;
using cucumber::ScenarioScope;

struct Context {
	VendingMachine vendingMachine;
};

WHEN("^no coins are inserted$") {
    //Do nothing
}

GIVEN("^a nickel is inserted$") {
    ScenarioScope<Context> context;
    context->vendingMachine.insert("NICKEL");
}

GIVEN("^a dime is inserted$") {
    ScenarioScope<Context> context;
    context->vendingMachine.insert("DIME");
}

GIVEN("^a quarter is inserted$") {
    ScenarioScope<Context> context;
    context->vendingMachine.insert("QUARTER");
}

GIVEN("^a '(.*)' is inserted$") {
    ScenarioScope<Context> context;
    REGEX_PARAM(std::string, invalidCoin);
    context->vendingMachine.insert(invalidCoin);
}

THEN("^the vending machine displays '(.*)'$") {
    ScenarioScope<Context> context;
    REGEX_PARAM(std::string, displayValue);
    EXPECT_EQ(displayValue, context->vendingMachine.readDisplay());
}

THEN("^the coin return contains the '(.*)'$") {
    ScenarioScope<Context> context;
    REGEX_PARAM(std::string, invalidCoin);
    EXPECT_THAT(invalidCoin, InCoinReturnSlot(context->vendingMachine));
}

