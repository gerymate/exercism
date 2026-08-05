#include "pascals_triangle.h"

namespace pascals_triangle {
  triangle_t generate_rows(int rows) {
    triangle_t triangle{};
    for (int i = 0; i != rows; i++) {
      row_t row{1};
      if (i > 1) {
        for (int j = 0; j != i-1; j++) {
          int value = triangle.at(i-1).at(j) + triangle.at(i-1).at(j+1);
          row.push_back(value);
        }
      } 
      if (i != 0) row.push_back(1);
      triangle.push_back(row);
    }
    return triangle;
  }

}  // namespace pascals_triangle
