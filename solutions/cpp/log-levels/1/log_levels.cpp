#include <string>

namespace log_line {
std::string message(std::string line) {
    const std::string separator {": "};
    const auto sep_len {separator.length()};
    
    auto message_start = line.find(separator) + sep_len;
    return line.substr(message_start);
}

std::string log_level(std::string line) {
    auto ll_start = line.find("[") + 1;
    auto ll_end = line.find("]") - 1;
    return line.substr(ll_start, ll_end);
}

std::string reformat(std::string line) {
    return message(line) + " (" + log_level(line) + ")";
}
}  // namespace log_line
