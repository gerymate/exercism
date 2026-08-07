#include "nth_prime.h"
#include <stdexcept>
#include <cmath>
#include <vector>

const std::vector<bool> primes(const int n) {
    std::vector<bool> is_prime(n, true);
    is_prime[0] = false;
    for (int i = 2; i <= n; i++) {
        if (!is_prime[i-1]) continue;
            for (int j = 2*i; j <= n; j += i) {
                is_prime[j-1] = false;
        }
    }
    return is_prime;
}

namespace nth_prime {
    int nth(const int n) {
        if (n == 0) throw std::domain_error{"There's no zeroeth prime"};
        int upper_bound = std::ceil(8.0 / 3.0 * n * std::log2(n)) + 2;
        auto my_primes {primes(upper_bound)};
        int i{0};
        for (int ps{0}; i < upper_bound; i++){
            if (my_primes[i]) ps++;
            if (ps == n) break;
        }
        return i+1;
    }

}  // namespace nth_prime
