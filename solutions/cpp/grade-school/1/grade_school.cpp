#include "grade_school.h"
#include <algorithm>

namespace grade_school {

  const roster_t& school::roster() const {
    return _roster;
  }

  void school::add(const std::string&& name, const int grade) {
    a_class& current_class {_roster[grade]};
    current_class.emplace_back(name);
    std::sort(begin(current_class), end(current_class));
  }

  a_class school::grade(const int grade) const {
    if (!_roster.count(grade)) return a_class{};
    return _roster.at(grade);
  }

}