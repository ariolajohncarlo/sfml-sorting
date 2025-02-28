#include "RandomNumberGenerator.h"

#include <gtest/gtest.h>

TEST(RandomNumberGeneratorTests, AssertCorrectMaxAndMinValues)
{
    const int MIN = 10;
    const int MAX = 100;
    RandomNumberGenerator randomNumberGenerator{MIN, MAX};

    EXPECT_EQ(randomNumberGenerator.GetMin(), MIN);
    EXPECT_EQ(randomNumberGenerator.GetMax(), MAX);
}