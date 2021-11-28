#include <gtest/gtest.h>
#include "version.h"

// Demonstrate some basic assertions.
TEST(HelloTest, BasicAssertions) {
EXPECT_TRUE(version::getVersion()>=0);
}