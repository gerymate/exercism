#if !defined(PRIME_FACTORS_H)
#define PRIME_FACTORS_H

#include <vector>

namespace prime_factors {
  typedef std::vector<int> Factors;
  Factors of(int);
}  // namespace prime_factors

#endif // PRIME_FACTORS_H