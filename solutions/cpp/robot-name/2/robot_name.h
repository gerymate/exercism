#ifndef ROBOT_NAME_H
#define ROBOT_NAME_H

#include <string>
#include <vector>

namespace robot_name {
  typedef std::vector<std::string> robot_name_db;

  class robot {
    public:
      robot();
      void reset();
      const std::string& name() const;
    private:
      std::string _name;
      static robot_name_db all_names;
      static robot_name_db::iterator next_name;
      static void init_all_names();
  };
}

#endif