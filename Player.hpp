#pragma once
#include "Board.hpp"
#include "City.hpp"
#include <set>

namespace pandemic
{

    class Player
    {
    protected:
        std::set<City> cards;
        City cur_city;
        std::string player_role;
        Board &board;

    public:
        Player(Board &b, City c, std::string r) : board(b), cur_city(c), player_role(r) {}

        virtual Player &drive(City c);
        virtual Player &fly_direct(City c);
        virtual Player &fly_charter(City c);
        virtual Player &fly_shuttle(City c);
        virtual Player &build();
        virtual Player &discover_cure(Color c);
        virtual Player &treat(City c);
        Player &take_card(City c);
        std::string role() { return player_role; }
    };

}