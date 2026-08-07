#if !defined(ROBOT_SIMULATOR_H)
#define ROBOT_SIMULATOR_H

#include <utility>
#include <string>

namespace robot_simulator {
  enum class Bearing {
    NORTH,
    EAST,
    SOUTH,
    WEST
  };

  typedef std::pair<int, int> Position;

  class Robot {
    Position position;
    Bearing bearing;
    public:
    Robot();
    Robot(const Position&, const Bearing);
    Bearing get_bearing() const;
    Position get_position() const;
    void turn_right();
    void turn_left();
    void advance();
    void execute_sequence(const std::string&);
  };
}  // namespace robot_simulator

#endif // ROBOT_SIMULATOR_H