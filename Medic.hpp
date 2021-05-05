#pragma once
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include "Board.hpp"

namespace pandemic{

    class Medic: public Player{

        public:
            Medic(Board& b, City c): Player(b, c, "Medic") {}
            Player& treat(City c) override;
            Player & drive(pandemic::City c) override;
            Player & fly_direct(pandemic::City c) override;
            Player & fly_charter(pandemic::City c) override;
            Player & fly_shuttle(pandemic::City c) override;
    };
}