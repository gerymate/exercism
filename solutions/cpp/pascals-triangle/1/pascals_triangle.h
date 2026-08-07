#if !defined(PASCALS_TRIANGLE_H)
#define PASCALS_TRIANGLE_H

#include <vector>

namespace pascals_triangle {
  typedef std::vector<int> row_t;
  typedef std::vector<row_t> triangle_t;
  triangle_t generate_rows(int);
}  // namespace pascals_triangle

#endif // PASCALS_TRIANGLE_H