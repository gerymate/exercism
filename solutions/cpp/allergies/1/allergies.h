#pragma once

#include<string>
#include<unordered_set>
#include<unordered_map>

namespace allergies {

// TODO: add your solution here
class allergy_test {
    public:
        allergy_test(unsigned);
        bool is_allergic_to(const std::string&);
        std::unordered_set<std::string> get_allergies();
    private:
        std::unordered_set<std::string> allergies;
};
}  // namespace allergies
