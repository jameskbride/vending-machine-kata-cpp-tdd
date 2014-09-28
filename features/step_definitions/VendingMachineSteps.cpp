#include <VendingMachine.h>
#include <gtest/gtest.h>
#include <cucumber-cpp/defs.hpp>

using cucumber::ScenarioScope;

struct Context {
	VendingMachine vendingMachine;
};

WHEN("^no coins are inserted$") {
    //Do nothing
}


THEN("^the vending machine displays '(.*)'$") {
    ScenarioScope<Context> context;
    EXPECT_EQ("INSERT COIN", context->vendingMachine.readDisplay());
}
