#include <string>
#include "playerdata.h"
#include <map>
using namespace std;


pair<string, char> playerData[] = {
    make_pair("Goose", 'G'),
    make_pair("GRT Bus", 'B'),
    make_pair("Tim Hortons Doughnut", 'D'),
    make_pair("Professor", 'P'),
    make_pair("Student", 'S'),
    make_pair("Money", '$'),
    make_pair("Laptop", 'L'),
    make_pair("Pink tie", 'T')
};

map<string, char> playerOptions(playerData, playerData+sizeof playerData / sizeof playerData[0]);
