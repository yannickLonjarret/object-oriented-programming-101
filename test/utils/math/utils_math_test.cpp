#include <gtest/gtest.h>

#include "utils_math.h"

TEST(UtilsMathTest, binomial_success) {
    const int result = utils::math::binomialCoeff(54, 3);
    EXPECT_EQ(result, 24804);
}

TEST(UtilsMathTest, binomial_badInput) {
    const int result = utils::math::binomialCoeff(3, 54);
    EXPECT_EQ(result, -1);
}

TEST(UtilsMathTest, binomial_EdgeCases) {
    int result = utils::math::binomialCoeff(54, 54);
    EXPECT_EQ(result, 1);

    result = utils::math::binomialCoeff(54, 0);
    EXPECT_EQ(result, 1);
}

