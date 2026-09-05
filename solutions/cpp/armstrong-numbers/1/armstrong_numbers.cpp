#include "armstrong_numbers.h"

namespace armstrong_numbers {

bool is_armstrong_number(const unsigned n) {
    // count number of digits
    auto digits {0};
    auto nn {n};
    while (nn != 0) {
        digits++;
        nn /= 10;
    }

    // calculate armstrong sum
    unsigned sum {0};
    auto nnn {n};
    while (nnn != 0) {
        auto prod {1};
        auto digit {nnn % 10};
        // power function by a loop
        for (auto i {0}; i != digits; i++) {
            prod *= digit;
        }
        sum += prod;
        nnn /= 10;
    }

    return sum == n;
}

}  // namespace armstrong_numbers
