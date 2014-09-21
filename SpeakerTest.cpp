#include "Speaker.h"
#include <gtest/gtest.h>

using namespace CppTddExample;

TEST(SpeakerTest, WhenSpeakerSpeaksItShouldSayHelloWorld) {
    Speaker speaker;
    std::string expectedString("Hello World!");
    EXPECT_EQ(expectedString, speaker.speak());
}
