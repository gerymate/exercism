#include "allergies.h"
#include<unordered_map>

namespace allergies {

allergy_test::allergy_test(unsigned allergy_codes) {
    std::unordered_map<unsigned, std::string> all_allergies {
        {1, "eggs"},
        {2, "peanuts"},
        {4, "shellfish"},
        {8, "strawberries"},
        {16, "tomatoes"},
        {32, "chocolate"},
        {64, "pollen"},
        {128, "cats"}
    };
    for (const auto& [k, v] : all_allergies) {
        if (allergy_codes & k) {
            allergies.emplace(v);
        }
    };
}
    
bool allergy_test::is_allergic_to(const std::string& allergen) {
    return allergies.find(allergen) != allergies.end();
}
    
std::unordered_set<std::string> allergy_test::get_allergies() {
    return allergies;
}

}  // namespace allergies
