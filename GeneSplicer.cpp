#include "GeneSplicer.hpp"

using namespace std;
using namespace pandemic;

Player &GeneSplicer::discover_cure(Color c)
{
    if (cards.size() < 5)
    {
        throw std::invalid_argument{"theres no enough cards"};
    }

    else if (board.is_research_station(cur_city))
    {
        int counter = 0;
        for (auto iter = cards.begin(); iter != cards.end() || counter<5; counter++)
        {
            iter = cards.erase(iter);
        }
        board.curing(c);
        return *this;
    }
    else
    {
        throw std::invalid_argument{"Theres no research station in your city"};
    }
}