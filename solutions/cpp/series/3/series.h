#if !defined(SERIES_H)
#define SERIES_H

#include<vector>
#include<string>

namespace series {
  typedef std::vector<int> intvec;
  typedef std::vector<intvec> intvecvec;
  intvec digits(const std::string&);
  const intvecvec slice(const std::string&, size_t);
}  // namespace series

#endif // SERIES_H