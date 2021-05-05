#include "Researcher.hpp"

using namespace std;
using namespace pandemic;

Player &Researcher::discover_cure(Color c)
{
    if (board.is_there_cure(c))
    {
        return *this;
    }

    else
    {
        int counter = 0;
        for (auto &col : cards)
        {
            if (board.color(col) == c)
            {
                counter++;
            }
            if (counter == 5)
            {
                break;
            }
        }
        if (counter >= 5)
        {
            counter = 0;
            for (auto iter = cards.begin(); iter != cards.end() || counter < 5; counter++)
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
}