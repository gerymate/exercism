#ifndef GRADE_SCHOOL_H
#define GRADE_SCHOOL_H

#include <vector>
#include <string>
#include <map>

namespace grade_school {
  typedef std::vector<std::string> a_class;
  typedef std::map<int, a_class> roster_t;
  class school {
      roster_t _roster;
    public:
      const roster_t& roster() const;
      void add(const std::string&&, const int);
      a_class grade(const int) const;
  };
};

#endif