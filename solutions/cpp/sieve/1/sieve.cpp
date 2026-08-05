#include "sieve.h"
#include <cmath>

namespace sieve {
    const std::vector<int> primes(const int n) {
        std::vector<bool> is_prime(n, true);
        is_prime[0] = false;
        for (int i = 2; i <= n; i++) {
            if (!is_prime[i-1]) continue;
            for (int j = 2*i; j <= n; j += i) {
                is_prime[j-1] = false;
            }
        }
        std::vector<int> my_primes;
        for (int i = 0; i < n; i++) {
            if (is_prime[i]) my_primes.push_back(i+1); 
        }
        return my_primes;
    }

}  // namespace sieve
