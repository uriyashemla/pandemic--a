#include "Medic.hpp"
#include "Board.hpp"

using namespace std;
using namespace pandemic;

Player &Medic::treat(City c)
{
    if (board.get_cubes(c) == 0)
    {
        throw invalid_argument{"Theres no cubes in the city"};
    }
    else
    {
        board.rm_cubes(c);
    }
    return *this;
}

Player &Medic::drive(pandemic::City c)
{
    if (board.is_connected(cur_city, c))
    {
        cur_city = c;
        if (board.is_there_cure(board.color(c)))
        {
            board.rm_cubes(c);
        }
        return *this;
    }
    else
    {
        throw invalid_argument{"Theres no connection between the cities"};
    }
}

Player &Medic::fly_direct(pandemic::City c)
{
    if (cards.count(c))
    {
        cards.erase(c);
        cur_city = c;
        if (board.is_there_cure(board.color(c)))
        {
            board.rm_cubes(c);
        }
        return *this;
    }
    else
    {
        throw invalid_argument{"Theres no match card"};
    }
}

Player &Medic::fly_charter(pandemic::City c)
{
    if (cards.count(cur_city))
    {
        cards.erase(cur_city);
        cur_city = c;
        if (board.is_there_cure(board.color(c)))
        {
            board.rm_cubes(c);
        }
        return *this;
    }
    else
    {
        throw invalid_argument{"Theres no match card"};
    }
}

Player &Medic::fly_shuttle(pandemic::City c)
{
    if (board.is_research_station(c) && board.is_research_station(cur_city))
    {
        cur_city = c;
        if (board.is_there_cure(board.color(c)))
        {
            board.rm_cubes(c);
        }
        return *this;
    }
    else
    {
        throw invalid_argument{"Theres no research stations in both cities"};
    }
}