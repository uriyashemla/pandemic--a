#include "Player.hpp"
using namespace std;

namespace pandemic
{
    Player &Player::drive(pandemic::City c)
    {
        if (board.is_connected(cur_city, c))
        {
            cur_city = c;
            return *this;
        }
        else
        {
            throw invalid_argument{"Theres no connection between the cities"};
        }
    }

    Player &Player::fly_direct(pandemic::City c)
    {
        if (cards.count(c))
        {
            cards.erase(c);
            cur_city = c;
            return *this;
        }
        else
        {
            throw invalid_argument{"Theres no match card"};
        }
    }

    Player &Player::fly_charter(pandemic::City c)
    {
        if (cards.count(cur_city))
        {
            cards.erase(cur_city);
            cur_city = c;
            return *this;
        }
        else
        {
            throw invalid_argument{"Theres no match card"};
        }
    }

    Player &Player::fly_shuttle(pandemic::City c)
    {
        if (board.is_research_station(c) && board.is_research_station(cur_city))
        {
            cur_city = c;
            return *this;
        }
        else
        {
            throw invalid_argument{"Theres no research stations in both cities"};
        }
    }
    Player &Player::build()
    {
        if (board.is_research_station(cur_city))
        {
            return *this;
        }
        else if (cards.count(cur_city))
        {
            cards.erase(cur_city);
            board.build(cur_city);
            return *this;
        }
        else
        {
            throw invalid_argument{"Theres no match card"};
        }
    }

    Player &Player::discover_cure(Color c)
    {

        if (board.is_there_cure(c))
        {
            return *this;
        }

        else if (board.is_research_station(cur_city))
        {
            int counter = 0;
            for (auto & col : cards)
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
        else
        {

            throw std::invalid_argument{"Theres no research station in your city"};
        }
    }

    Player &Player::treat(pandemic::City c)
    {
        if (board.get_cubes(c) == 0)
        {
            throw invalid_argument{"Theres no cubes in the city"};
        }
        else if (c != cur_city)
        {
            throw invalid_argument{"The player isn't at the same city"};
        }
        else if (board.is_there_cure(board.color(c)))
        {
            board.rm_cubes(c);
            return *this;
        }
        else
        {
            board.x_cubes(c);
        }
        return *this;
    }

    Player &Player::take_card(pandemic::City c)
    {
        cards.insert(c);
        return *this;
    }
}