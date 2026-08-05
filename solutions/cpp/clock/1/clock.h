#if !defined(CLOCK_H)
#define CLOCK_H

#include <string>

namespace date_independent {
  class clock {
    int minutes;
    void normalize();
    public:
    static clock at(int, int);
    clock(int, int);
    operator std::string() const;
    clock plus(int);
    bool operator==(const clock&) const;
    bool operator!=(const clock&) const;
  };
}  // namespace date_independent

#endif // CLOCK_H