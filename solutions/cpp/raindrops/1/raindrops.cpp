#include "raindrops.h"

namespace raindrops {
    std::string convert(const int n) { 
        auto is_divisible_by_3 {n % 3 == 0};
        auto is_divisible_by_5 {n % 5 == 0};
        auto is_divisible_by_7 {n % 7 == 0};
        std::string result {""};
        if (is_divisible_by_3) result += "Pling";
        if (is_divisible_by_5) result += "Plang";
        if (is_divisible_by_7) result += "Plong";
        if (result == "") result = std::to_string(n);
        return result;
    };

}  // namespace raindrops
