#include "trinary.h"

namespace trinary {
  int to_decimal(const std::string& input) {
    int decimal {0};
    for (auto &&digit : input) {
      decimal *= 3;
      switch (digit) {
        case '0': break;
        case '1': decimal += 1; break;
        case '2': decimal += 2; break;
        default: return 0;
      }
    }
    return decimal;
  }
}  // namespace trinary
