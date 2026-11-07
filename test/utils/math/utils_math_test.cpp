#include "utils_math.h"
#include <gtest/gtest.h>

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

TEST(UtilsMathTest, k_combination_badInput) {
    auto vec = utils::math::k_combination(3, 5);

    EXPECT_TRUE(vec.empty());
}

TEST(UtilsMathTest, k_combination_success) {
    std::vector<std::vector<unsigned int>> result = {{0, 1}, {0, 2}, {0, 3}, {1, 2}, {1, 3}, {2, 3}};
    auto vec = utils::math::k_combination(4, 2);

    ASSERT_EQ(vec.size(), result.size());

    for (size_t i = 0; i < result.size(); i++) {
        EXPECT_TRUE(std::equal(vec.begin(), vec.end(), result.begin(), result.end()));
    }
}
