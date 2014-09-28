#include <VendingMachine.h>
#include <gtest/gtest.h>
#include <cucumber-cpp/defs.hpp>

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
    context->vendingMachine.insert(NICKEL);
}


THEN("^the vending machine displays '(.*)'$") {
    ScenarioScope<Context> context;
    REGEX_PARAM(std::string, displayValue);
    EXPECT_EQ(displayValue, context->vendingMachine.readDisplay());
}
