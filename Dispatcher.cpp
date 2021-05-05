#include "Dispatcher.hpp"

using namespace std;
using namespace pandemic;

Player& Dispatcher::fly_direct(City c){
    if(board.is_research_station(cur_city)) {
        cur_city = c;
        return *this;
    }
    else {
        return Player::fly_direct(c);
    }
}