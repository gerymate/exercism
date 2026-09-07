#include "hexadecimal.h"

#include <utility>

namespace hexadecimal {

const std::string DIGITS {"0123456789abcdef"};

int convert(const std::string& in) {
    int out {0};
    for (auto [multiplier, i] = std::pair{1, in.rbegin()}; i != in.rend(); i++) {
        if (auto d = DIGITS.find(*i); d == std::string::npos) {
            return 0;
        } else {
            out += d * multiplier;
            multiplier *= 16;
        }
    }
    return out;
}

}  // namespace hexadecimal
