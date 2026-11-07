#include "utils_math.h"
#include <numeric>

namespace utils::math {

int binomialCoeff(const unsigned int n, const unsigned int k) {
    if (k > n) {
        return -1;
    }

    if (k == 0 || k == n) {
        return 1;
    }
    unsigned int coeff = 1;
    for (unsigned int i = 1; i <= k; i++) {
        coeff = coeff * (n + 1 - i) / i;
    }

    return coeff;
}

std::vector<std::vector<unsigned int>> k_combination(const unsigned int n, const unsigned int k) {
    if (k > n) {
        return {};
    }
    std::vector<std::vector<unsigned int>> results;
    results.reserve(binomialCoeff(n, k));

    std::vector<unsigned int> combo(k);
    std::iota(combo.begin(), combo.end(), 0);

    while (true) {
        results.push_back(combo);
        int i = k - 1;

        while (i >= 0 && combo.at(i) == n - k + i) {
            i--;
        }

        if (i < 0) {
            break;
        }

        combo.at(i)++;

        for (unsigned int j = i + 1; j < k; j++) {
            combo.at(j) = combo.at(j - 1) + 1;
        }
    }

    return results;
}
} // namespace utils::math