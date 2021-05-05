#include <map>
#include <set>
#include <iostream>
#include <string>

#include "Board.hpp"
using namespace std;
using namespace pandemic;

map<City, int> diseas;
set<City> stations;
bool already_cured[4] = {0};
map<City, set<City>> connections{
    {Algiers, {Madrid, Paris, Istanbul, Cairo}},
    {Atlanta, {Chicago, Miami, Washington}},
    {Baghdad, {Tehran, Istanbul, Cairo, Riyadh, Karachi}},
    {Bangkok, {Kolkata, Chennai, Jakarta, HoChiMinhCity, HongKong}},
    {Beijing, {Shanghai, Seoul}},
    {Bogota, {MexicoCity, Lima, Miami, SaoPaulo, BuenosAires}},
    {BuenosAires, {Bogota, SaoPaulo}},
    {Cairo, {Algiers, Istanbul, Baghdad, Khartoum, Riyadh}},
    {Chennai, {Mumbai, Delhi, Kolkata, Bangkok, Jakarta}},
    {Chicago, {SanFrancisco, LosAngeles, MexicoCity, Atlanta, Montreal}},
    {Delhi, {Tehran, Karachi, Mumbai, Chennai, Kolkata}},
    {Essen, {London, Paris, Milan, StPetersburg}},
    {HoChiMinhCity, {Jakarta, Bangkok, HongKong, Manila}},
    {HongKong, {Bangkok, Kolkata, HoChiMinhCity, Shanghai, Manila, Taipei}},
    {Istanbul, {Milan, Algiers, StPetersburg, Cairo, Baghdad, Moscow}},
    {Jakarta, {Chennai, Bangkok, HoChiMinhCity, Sydney}},
    {Johannesburg, {Kinshasa, Khartoum}},
    {Karachi, {Tehran, Baghdad, Riyadh, Mumbai, Delhi}},
    {Khartoum, {Cairo, Lagos, Kinshasa, Johannesburg}},
    {Kinshasa, {Lagos, Khartoum, Johannesburg}},
    {Kolkata, {Delhi, Chennai, Bangkok, HongKong}},
    {Lagos, {SaoPaulo, Khartoum, Kinshasa}},
    {Lima, {MexicoCity, Bogota, Santiago}},
    {London, {NewYork, Madrid, Essen, Paris}},
    {LosAngeles, {SanFrancisco, Chicago, MexicoCity, Sydney}},
    {Madrid, {London, NewYork, Paris, SaoPaulo, Algiers}},
    {Manila, {Taipei, SanFrancisco, HoChiMinhCity, Sydney}},
    {MexicoCity, {LosAngeles, Chicago, Miami, Lima, Bogota}},
    {Miami, {Atlanta, MexicoCity, Washington, Bogota}},
    {Milan, {Essen, Paris, Istanbul}},
    {Montreal, {Chicago, Washington, NewYork}},
    {Moscow, {StPetersburg, Istanbul, Tehran}},
    {Mumbai, {Karachi, Delhi, Chennai}},
    {NewYork, {Montreal, Washington, London, Madrid}},
    {Osaka, {Taipei, Tokyo}},
    {Paris, {Algiers, Essen, Madrid, Milan, London}},
    {Riyadh, {Baghdad, Cairo, Karachi}},
    {SanFrancisco, {LosAngeles, Chicago, Tokyo, Manila}},
    {Santiago, {Lima}},
    {SaoPaulo, {Bogota, BuenosAires, Lagos, Madrid}},
    {Seoul, {Beijing, Shanghai, Tokyo}},
    {Shanghai, {Beijing, HongKong, Taipei, Seoul, Tokyo}},
    {StPetersburg, {Essen, Istanbul, Moscow}},
    {Sydney, {Jakarta, Manila, LosAngeles}},
    {Taipei, {Shanghai, HongKong, Osaka, Manila}},
    {Tehran, {Baghdad, Moscow, Karachi, Delhi}},
    {Tokyo, {Seoul, Shanghai, Osaka, SanFrancisco}},
    {Washington, {Atlanta, NewYork, Montreal, Miami}}};

bool Board::is_clean()
{
    for (auto &n : diseas)
    {
        if (n.second > 0)
        {
            return false;
        }
    }
    return true;
}

bool Board::is_connected(pandemic::City &c1, pandemic::City &c2)
{
    if (connections.at(c1).count(c2))
    {
        return true;
    }
    return false;
}

void Board::build(pandemic::City c)
{
    stations.insert(c);
}

bool Board::is_research_station(pandemic::City c)
{
    if (stations.count(c))
    {
        return true;
    }
    return false;
}

void Board::curing(pandemic::Color c)
{
    already_cured[c] = true;
}

bool Board::is_there_cure(pandemic::Color c)
{
    return already_cured[c];
}

int Board::get_cubes(pandemic::City c)
{
    if (diseas.count(c)){
    return diseas.at(c);
    }
    else{
        return 0;
    }
}

void Board::x_cubes(pandemic::City c)
{
    if (diseas.count(c))
    {
        diseas.at(c) -= 1;
    }
}

void Board::rm_cubes(pandemic::City c)
{
    if (diseas.count(c))
    {
        diseas.at(c) = 0;
    }
}

Color Board::color(City c)
{
    return cities_colors.at(c);
}

int &Board::operator[](pandemic::City c)
{
    return diseas[c];
}

std::ostream &pandemic::operator<<(std::ostream &out, const Board &b)
{
    out << " ";
    return out;
}

void remove_cures()
{
    for (int i = 0; i < 4; i++)
    {
        already_cured[i] = false;
    }
}