#include "phone_number.h"
#include <regex>

phone_number::phone_number(const std::string& input) {
    std::regex not_number("\\D");
    _number = std::regex_replace(input, not_number, "");
    if (_number.size() == 11 && _number[0] == '1') _number.erase(0, 1);
    if (_number.size() != 10 
      || _number[0] == '0'
      || _number[0] == '1'
      || _number[3] == '0'
      || _number[3] == '1'
      ) throw std::domain_error("Invalid phone number");
}

std::string phone_number::number() const {
  return _number;
}

std::string phone_number::area_code() const {
  return _number.substr(0, 3);
}

phone_number::operator std::string() const {
  return std::string{"("} 
    + _number.substr(0, 3) 
    + ") " 
    + _number.substr(3, 3)
    + "-"
    + _number.substr(6, 4);
}
