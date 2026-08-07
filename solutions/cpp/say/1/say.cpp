#include "say.h"

#include <unordered_map>
#include <iostream>
#include <stdexcept>

namespace say {
  std::unordered_map<int, std::string> number_words {
    {0, "zero"},
    {1, "one"},
    {2, "two"},
    {3, "three"},
    {4, "four"},
    {5, "five"},
    {6, "six"},
    {7, "seven"},
    {8, "eight"},
    {9, "nine"},
    {10, "ten"},
    {11, "eleven"},
    {12, "twelve"},
    {13, "thirteen"},
    {14, "fourteen"},
    {15, "fifteen"},
    {16, "sixteen"},
    {17, "seventeen"},
    {18, "eightteen"},
    {19, "nineteen"},
  };

  std::unordered_map<int, std::string> tens_words {
    {1, "ten"},
    {2, "twenty"},
    {3, "thirty"},
    {4, "forty"},
    {5, "fifty"},
    {6, "sixty"},
    {7, "seventy"},
    {8, "eighty"},
    {9, "ninety"},
  };

  std::string in_english(long long n) {
    if (n < 0 || n >= 1000'000'000'000LL ) throw std::domain_error("Negative or too large number");
    if (n < 20) return number_words.at(n);

    std::string number {""};
    int billions {static_cast<int>(n / 1'000'000'000LL)};
    n -= 1'000'000'000LL * billions;
    int millions {static_cast<int>(n / 1'000'000)};
    n -= 1'000'000 * millions;
    int thousands {static_cast<int>(n / 1000)};
    n -= 1000 * thousands;
    int hundreds {static_cast<int>(n / 100)};
    n -= 100 * hundreds;
    int tens {static_cast<int>(n / 10)};
    n -= 10 * tens;
    int ones {static_cast<int>(n)};
  
    if (billions) number += in_english(billions) + " billion ";
    if (millions) number += in_english(millions) + " million ";
    if (thousands) number += in_english(thousands) + " thousand ";
    if (hundreds) number += number_words.at(hundreds) + " hundred ";
    if (tens) number += tens_words.at(tens) + "-";
    if (ones) number += number_words.at(ones) + "Z";
    number.pop_back();
    return number;
  }
}  // namespace say
