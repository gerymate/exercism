#include <string>


namespace reverse_string {

static std::string reverse_string(const std::string& input) {
    return std::string{input.rbegin(), input.rend()};
}

};

