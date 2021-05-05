#include "Virologist.hpp"

using namespace std;
using namespace pandemic;

Player &Virologist::treat(City c)
{
    if (board.get_cubes(c) == 0)
    {
        throw invalid_argument{"Theres no cubes in the city"};
    }
    else if (!cards.count(c))
    {
        throw invalid_argument{"Theres no match card"};
    }
    else if (board.is_there_cure(board.color(c)))
    {
        board.rm_cubes(c);
        cards.erase(c);
        return *this;
    }
    else
    {
        board.x_cubes(c);
        cards.erase(c);
    }
    return *this;
}