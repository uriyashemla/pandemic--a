#include "Scientist.hpp"

using namespace std;
using namespace pandemic;

Player &Scientist::discover_cure(Color c)
{
    if (board.is_there_cure(c))
    {
        return *this;
    }

    else if (board.is_research_station(cur_city))
    {
        int counter = 0;
        for (auto &col : cards)
        {
            if (board.color(col) == c)
            {
                counter++;
            }
            if (counter == n)
            {
                break;
            }
        }
        if (counter >= n)
        {
            counter = 0;
            for (auto iter = cards.begin(); iter != cards.end() || counter < n; counter++)
            {
                if (board.color(*iter) == c)
                {
                    iter = cards.erase(iter);
                }
                else
                {
                    ++iter;
                }
            }
            board.curing(c);
            return *this;
        }
        else
        {
            throw std::invalid_argument{"theres no enough cards"};
        }
    }
    else
    {

        throw std::invalid_argument{"Theres no research station in your city"};
    }
}