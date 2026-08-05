#include"doctor_data.h"

namespace heaven {
void Vessel::make_buster() {
    busters++;
}

bool Vessel::shoot_buster() {
    if (busters != 0) {
        busters--;
        return true;
    }
    return false;
}

const std::string& get_older_bob(const Vessel& first, const Vessel& second) {
    return first.generation <= second.generation ? first.name : second.name;
}

bool in_the_same_system(const Vessel& first, const Vessel& second) {
    return first.current_system == second.current_system;
}

}

/*
hp4,ölacöiömthö%Äsmaö%Äsubö(311040ö%Äspaö%Äaddö(311040ö%Ädacöiömthö%Äcountö.hpt,hp4ö%Äxctöhd2ö%Ädacöiöma1
hp2,öjmpö.
*/