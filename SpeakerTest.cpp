#include "Speaker.h"
#include <gtest/gtest.h>

using namespace CppTddExample;
using namespace testing;

TEST(SpeakerTest, WhenSpeakerSpeaksItShouldSayHelloWorld) {
    Speaker speaker;
    std::string expectedString("Hello World!");
    EXPECT_EQ(expectedString, speaker.speak());
}
