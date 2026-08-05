#include<string>

namespace star_map {
    enum class System {
    Sol,
    AlphaCentauri,
    BetaHydri,
    DeltaEridani,
    EpsilonEridani,
    Omicron2Eridani
    };
}

namespace heaven {
    class Vessel {
    public:
        Vessel(const std::string& name, int generation, star_map::System system = star_map::System::Sol) 
            : name{name}, current_system{system}, generation{generation} {}
        Vessel replicate(const std::string& name) const {
            return Vessel(name, generation + 1, current_system);
        };
        void make_buster();
        bool shoot_buster();
        std::string name{};
        star_map::System current_system{};
        int generation{};
        int busters{};
    };

    const std::string& get_older_bob(const Vessel&, const Vessel&);
    bool in_the_same_system(const Vessel&, const Vessel&);
}

/*
hp1, üapöhp2ö % Äcountöiöma1,
    öhp2ö % Älawöhp3öö / önextöstepö % Ädacöiöml1ö % Älawö7ö % Ädacöiömb1ö %
        Ärandomöö % Äscrö9sö % Äsirö9sö % Äxctöhr1ö % Äaddöiömx1ö %
        Ädacöiömx1ö % Äswapö % Äaddöiömy1ö % Ädacöiömy1ö % Ärandomö % Äscrö9sö %
        Äsirö9sö % Äxctöhr2ö % Ädacöiömdyö % Ädioöiömdxö % Äsetupö.hpt,
    3ö % Älacöranö % Ädacöiömth
*/