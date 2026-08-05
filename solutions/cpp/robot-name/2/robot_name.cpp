#include "robot_name.h"
#include <algorithm>
#include <random>

namespace robot_name {
  robot_name_db robot::all_names;
  robot_name_db::iterator robot::next_name;

  robot::robot() {
    if (all_names.empty()) {
      init_all_names();
      next_name = begin(all_names);
    }
    reset();
  }

  void robot::reset() {
    _name = *next_name++;
    if (next_name == end(all_names)) next_name = begin(all_names);
  }

  const std::string& robot::name() const {
    return _name;
  }

  void robot::init_all_names() {
    const std::string letters{"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    const std::string digits{"0123456789"};

    for (auto l1 : letters)
      for (auto l2 : letters)
        for (auto d1 : digits)
          for (auto d2 : digits)
            for (auto d3 : digits)
              all_names.emplace_back(
                  std::string{} + l1 + l2 + d1 + d2 + d3);

    std::random_device rand_dev;
    std::mt19937 rand_gen(rand_dev());
    std::shuffle(begin(all_names), end(all_names), rand_gen);
  }
}