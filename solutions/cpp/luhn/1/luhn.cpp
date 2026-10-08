#include "luhn.h"

#include <vector>
#include <unordered_map>
#include <numeric>

namespace luhn {

    const std::unordered_map<int, char> DIGITS = {{'0', 0}, {'1', 1}, {'2', 2}, {'3', 3}, {'4', 4}, {'5', 5}, {'6', 6}, {'7', 7}, {'8', 8}, {'9', 9}};
    bool valid(const std::string& in) {
        // Convert string to numeric digits
        std::vector<int> digits;
        for (auto ch : in) {
            if (ch == ' ') continue;
            auto d = DIGITS.find(ch);
            if (d == DIGITS.end()) return false;
            digits.push_back(d->second);
        }
        // Validate size
        if (digits.size() < 2) {
            return false;
        }
        // Double and clamp every second digit from the back
        for (int i = digits.size()-2; i >= 0; i -= 2) {
            auto d = digits[i] * 2;
            if (d > 9) d -= 9;
            digits[i] = d;
        }
        // Check if sum's divisible by 10
        auto sum = std::accumulate(digits.begin(), digits.end(), 0);
        return sum % 10 == 0;
    }

}  // namespace luhn
