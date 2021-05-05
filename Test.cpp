
#include "doctest.h"
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "Researcher.hpp"
#include "Scientist.hpp"
#include "FieldDoctor.hpp"
#include "GeneSplicer.hpp"
#include "OperationsExpert.hpp"
#include "Dispatcher.hpp"
#include "Medic.hpp"
#include "Virologist.hpp"

#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>
#include <stdexcept>
#include <string>
#include <vector>
#include <stdlib.h>
#include <time.h>

using namespace pandemic;
using namespace std;

TEST_CASE("Test OperationsExpert and Board")
{
    Board board;
    CHECK(board.is_clean());
    CHECK_NOTHROW(board[City::Manila] = 3;);
    CHECK_FALSE(board.is_clean());
    CHECK_FALSE(board.is_research_station(Manila));
    OperationsExpert player{board, Manila};
    CHECK_NOTHROW(player.build());
    CHECK(board.is_research_station(Manila));
}

TEST_CASE("Test Dispatcher")
{
    Board board;
    Dispatcher player{board, Algiers};
    player.take_card(Algiers);
    CHECK_NOTHROW(player.build());
    player.take_card(Algiers);
    CHECK_NOTHROW(player.build());
    CHECK_NOTHROW(player.fly_direct(Taipei));
    CHECK_THROWS(player.build());
    CHECK_THROWS(player.fly_direct(Shanghai));
}

TEST_CASE("Test Scientist")
{
    Board board;
    Scientist player{board, Istanbul, 4};
    player.take_card(Delhi);
    player.take_card(Istanbul);
    player.take_card(Karachi);
    CHECK_THROWS(player.discover_cure(Black));
    CHECK_NOTHROW(player.build());
    player.take_card(Kolkata);
    player.take_card(Istanbul);
    CHECK_NOTHROW(player.discover_cure(Black));
    player.take_card(Delhi);
    player.take_card(Istanbul);
    player.take_card(Karachi);
    CHECK_NOTHROW(player.discover_cure(Black));
}

TEST_CASE("Test Researcher")
{
    Board board;
    Researcher player{board, Madrid};
    player.take_card(Johannesburg);
    player.take_card(Khartoum);
    player.take_card(Kinshasa);
    player.take_card(Lagos);
    CHECK_THROWS(player.discover_cure(Yellow));
    player.take_card(Lima);
    CHECK_NOTHROW(player.discover_cure(Yellow));
}

TEST_CASE("Test Medic")
{
    Board board;
    Medic player{board, MexicoCity};
    CHECK_NOTHROW(board[City::Lima] = 3;);
    CHECK(board.is_there_cure(Yellow));
    CHECK_NOTHROW(player.drive(Lima));
    CHECK_THROWS(player.treat(Lima));
    player.take_card(MexicoCity);
    CHECK_NOTHROW(player.fly_direct(MexicoCity));
    //CHECK_NOTHROW(player.drive(MexicoCity));
    CHECK_NOTHROW(board[City::MexicoCity] = 3;);
    CHECK_NOTHROW(player.treat(MexicoCity));
    CHECK_THROWS(player.treat(MexicoCity));
}

TEST_CASE("Test Virologist")
{
    Board board;
    Virologist player{board, Osaka};
    CHECK_THROWS(player.treat(Lima));
    CHECK_NOTHROW(board[City::Lima] = 3;);
    CHECK_THROWS(player.treat(Lima));
    player.take_card(Lima);
    CHECK_NOTHROW(player.treat(Lima));
}

TEST_CASE("Test GeneSplicer")
{
    Board board;
    GeneSplicer player{board, MexicoCity};
    player.take_card(Jakarta);
    player.take_card(Kinshasa);
    player.take_card(Madrid);
    player.take_card(Beijing);
    CHECK_THROWS(player.build());
    player.take_card(MexicoCity);
    CHECK_NOTHROW(player.build());
    CHECK_THROWS(player.discover_cure(Blue));
    player.take_card(Lima);
    CHECK_NOTHROW(player.discover_cure(Blue));
}

TEST_CASE("Test FieldDoctor")
{
    Board board;
    FieldDoctor player{board, Manila};
    CHECK_THROWS(player.treat(Taipei));
    CHECK_NOTHROW(board[City::Taipei] = 3;);
    CHECK_NOTHROW(player.treat(Taipei));
    CHECK_NOTHROW(player.treat(Taipei));
    CHECK_NOTHROW(player.treat(Taipei));
    CHECK_THROWS(player.treat(Taipei));
    CHECK_NOTHROW(board[City::Algiers] = 1;);
    CHECK_THROWS(player.treat(Algiers));
}

TEST_CASE("Drive and Flys")
{
    Board board;
    GeneSplicer player{board, Washington};
    CHECK_NOTHROW(player.drive(Atlanta));
    CHECK_NOTHROW(player.drive(Chicago));
    CHECK_THROWS(player.drive(Chennai));
    player.take_card(Chicago);
    CHECK_NOTHROW(player.build());
    player.take_card(Chicago);
    CHECK_THROWS(player.fly_direct(Paris));
    CHECK_NOTHROW(player.fly_charter(Paris));
    CHECK_THROWS(player.fly_shuttle(Chicago));
    CHECK_THROWS(player.fly_charter(Chicago));
    CHECK_THROWS(player.build());
    player.take_card(Paris);
    CHECK_NOTHROW(player.build());
    CHECK_NOTHROW(player.fly_shuttle(Chicago));
    CHECK_NOTHROW(player.fly_shuttle(Paris));
}