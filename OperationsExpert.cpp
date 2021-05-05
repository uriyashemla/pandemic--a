#include "OperationsExpert.hpp"

using namespace std;
using namespace pandemic;


Player& OperationsExpert::build(){
    board.build(cur_city);
    return *this;
}