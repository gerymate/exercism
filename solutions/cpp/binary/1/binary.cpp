#include "binary.h"
#include <locale>

namespace binary {
  int convert(const std::string& input) {
    int decimal {0};
    for (auto digit = begin(input); digit != end(input); digit++) { 
      if (!std::isdigit(*digit)) return 0;
      decimal *= 2;
      if (*digit == '1') decimal += 1;
    }
    return decimal;
  }

}  // namespace binary
