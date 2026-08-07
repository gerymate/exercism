#include "series.h"
#include <stdexcept>

namespace series {
  intvec digits(const std::string& input) {
    intvec result {begin(input), end(input)};
    for(int& digit : result) {
      digit -= int('0'); // convert from ascii to numeric value
    }
    return result;
  }
  
  const intvecvec slice(const std::string& input, size_t slice_size) {
    if (input.size() < slice_size) throw std::domain_error("Requested too large slice");
    intvec single_digits {digits(input)};
    intvecvec result;
    for (
      auto slice_begin {begin(single_digits)};
      slice_begin + slice_size - 1 != end(single_digits);
      slice_begin++
    ) result.emplace_back(slice_begin, slice_begin + slice_size); 
    return result;
  }

}  // namespace series
