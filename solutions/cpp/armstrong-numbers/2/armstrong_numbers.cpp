#include "armstrong_numbers.h"

namespace armstrong_numbers {

bool is_armstrong_number(const unsigned n) {
    // count number of digits
    auto digits = 0;
    for (auto nn = n; nn != 0; nn /= 10) {
        digits++;
    }

    // calculate armstrong sum
    unsigned sum = 0;
    for (auto nn = n; nn != 0; nn /= 10) {
        // power function by a loop
        auto prod = 1;
        auto digit = nn % 10;
        for (auto i = 0; i != digits; i++) {
            prod *= digit;
        }
        sum += prod;
    }

    return sum == n;
}

}  // namespace armstrong_numbers
