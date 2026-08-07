#include "binary.h"

namespace binary {
  int convert(const std::string& input) {
    int decimal {0};
    for (auto digit : input) { 
      decimal *= 2;
      if (digit == '1') decimal += 1;
      else if (digit == '0');
      else return 0;
    }
    return decimal;
  }
}  // namespace binary
