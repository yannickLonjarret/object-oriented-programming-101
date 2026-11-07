#ifndef UTILS_MATH_H
#define UTILS_MATH_H

#include <vector>

namespace utils::math {

int binomialCoeff(const unsigned int n, const unsigned int k);

std::vector<std::vector<unsigned int>> k_combination(const unsigned int n, const unsigned int k);

} // namespace utils::math

#endif