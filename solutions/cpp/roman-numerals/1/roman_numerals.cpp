#include "roman_numerals.h"

#include <utility>
#include <vector>

namespace roman_numerals {
    std::string convert(int n) {
        const std::vector<std::pair<int, const char*>> CASES {
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"}, 
            {90, "XC"}, {50, "L"}, {40, "XL"}, {10, "X"}, {9, "IX"}, {5, "V"},
            {4, "IV"}, {1, "I"}
        };

        std::string out {""};

        auto handle_subcase = [&n, &out](int dec, const char* roman) {
            while (n / dec > 0) {
                out += roman;
                n -= dec;
            }
        };

        for (auto [dec, roman] : CASES) {
            handle_subcase(dec, roman);
        }        

        return out;
    }
}  // namespace roman_numerals
