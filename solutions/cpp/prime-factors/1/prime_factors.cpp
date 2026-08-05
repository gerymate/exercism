#include "prime_factors.h"

namespace prime_factors {
  Factors of(int n) {
    Factors factors{};
    for (int divisor {2}; divisor <= n; ++divisor) {
      while (n % divisor == 0) {
        n /= divisor;
        factors.push_back(divisor);
      }
    }
    return factors;
  }
}  // namespace prime_factors
