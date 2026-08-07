#include "crypto_square.h"
#include <algorithm>
#include <locale>
#include <cmath>

namespace crypto_square {
  cipher::cipher(const std::string& original) : _original{original} {
    _normalized = normalize_plain_text();
    calc_rows_and_cols();
    _plain_segmented = plain_text_segments();
    calc_ciphered_segments();
  }

  std::string cipher::normalize_plain_text() const {
    std::string normal;
    std::copy_if(begin(_original), end(_original), std::back_inserter(normal),
        [](unsigned char c) -> unsigned char { return std::isalnum(c); } 
    );
    std::transform(
        begin(normal), end(normal), begin(normal),
        [](unsigned char c) -> unsigned char { return std::tolower(c); }
    );
    return normal;
  }

  void cipher::calc_rows_and_cols() {
    const size_t num_of_chars {_normalized.length()};
    _rows = size_t(std::sqrt(num_of_chars));
    _cols = _rows*_rows < num_of_chars ? _rows+1 : _rows;
  }

  square cipher::plain_text_segments() const {
    square segments;
    for (size_t row=0; row!=_rows; row++) {
      segments.emplace_back(_normalized.substr(row * _cols, _cols));
    }
    return segments;
  }

  void cipher::calc_ciphered_segments() {
    _ciphered_segments.resize(_cols);
    for (size_t col_num=0; col_num!=_cols; col_num++) {
      for (auto row : _plain_segmented) {
        if (col_num < row.length()) _ciphered_segments.at(col_num) += row.at(col_num);
      }
    }
  }

  std::string cipher::cipher_text() const {
    std::string ciphered;
    for (auto row : _ciphered_segments) ciphered += row;
    return ciphered;
  }

  std::string cipher::normalized_cipher_text() const {
    std::string normal_ciphered;
    for (auto row : _ciphered_segments) {
      const auto padding {row.size() < _rows ? " " : ""};
      normal_ciphered += row + padding + " ";
    }
    normal_ciphered.pop_back();
    return normal_ciphered;
  }

}  // namespace crypto_square
