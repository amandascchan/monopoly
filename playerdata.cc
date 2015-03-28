#include <string>
#include "playerdata.h"
#include <map>
using namespace std;


pair<string, char> playerData[] = {
    make_pair("Goose", 'G'),
    make_pair("GRT BUS", 'B'),
    make_pair("Tim Hortons Doughnut", 'D'),
    make_pair("Professor", 'P'),
    make_pair("Student", 'S'),
    make_pair("Money", '$'),
    make_pair("Laptop", 'L'),
    make_pair("Pink Tie", 'T')
};

map<string, char> playerOptions(playerData, playerData+sizeof playerData / sizeof playerData[0]);
