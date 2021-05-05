#pragma once
#include "City.hpp"
#include "Color.hpp"

namespace pandemic
{

    class Board
    {
    public:
        Board() {}
        bool is_clean();
        bool is_connected(City &c1, City &c2);
        void build(City c);
        bool is_research_station(City c);
        void curing(Color c);
        bool is_there_cure(Color c);
        int get_cubes(City c);
        void x_cubes(City c);
        void rm_cubes(City c);
        Color color(City c);
        int &operator[](City c);
        friend std::ostream &operator<<(std::ostream &out, const Board &b);
        void remove_cures();
    };

}