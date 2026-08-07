#include "robot_simulator.h"

namespace robot_simulator {
  Robot::Robot(const Position& p, const Bearing b) : position{p}, bearing{b} {
  }

  Robot::Robot() : Robot{{0, 0}, Bearing::NORTH} {
  }

  Bearing Robot::get_bearing() const {
    return bearing;
  }

  Position Robot::get_position() const {
    return position;
  }

  void Robot::turn_right() {
    bearing = (bearing == Bearing::NORTH) ? Bearing::EAST
            : (bearing == Bearing::EAST)  ? Bearing::SOUTH
            : (bearing == Bearing::SOUTH) ? Bearing::WEST
            :                               Bearing::NORTH;
  }

  void Robot::turn_left() {
    bearing = (bearing == Bearing::NORTH) ? Bearing::WEST
            : (bearing == Bearing::WEST)  ? Bearing::SOUTH
            : (bearing == Bearing::SOUTH) ? Bearing::EAST
            :                               Bearing::NORTH;
  }

  void Robot::advance() {
    switch (bearing) {
    case Bearing::NORTH: ++position.second; break;
    case Bearing::SOUTH: --position.second; break;
    case Bearing::EAST: ++position.first; break;
    case Bearing::WEST: --position.first; break;
    }
  }

  void Robot::execute_sequence(const std::string& commands) {
    for (const auto& command : commands) {
      switch (command) {
      case 'A': advance(); break;
      case 'L': turn_left(); break;
      case 'R': turn_right(); break;
      default: ;
      }
    }
  }
}  // namespace robot_simulator
