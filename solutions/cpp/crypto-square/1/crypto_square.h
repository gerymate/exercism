#if !defined(CRYPTO_SQUARE_H)
#define CRYPTO_SQUARE_H

#include<string>
#include<vector>

namespace crypto_square {
  typedef std::vector<std::string> square;
  class cipher {
      std::string _original;
      std::string _normalized;
      size_t _rows, _cols;
      void calc_rows_and_cols();
      square _plain_segmented;
      square _ciphered_segments;
      void calc_ciphered_segments();
    public:
      cipher(const std::string&);
      std::string normalize_plain_text() const;
      square plain_text_segments() const;
      std::string cipher_text() const;
      std::string normalized_cipher_text() const;
  };

}  // namespace crypto_square

#endif // CRYPTO_SQUARE_H