#include <string>
#include "playerdata.h"
#include <map>
using namespace std;

PlayerData GOOSE = {"Goose", 'G', 0,0};
PlayerData GRT = {"GRT Bus", 'B', 0,0};
PlayerData THD = {"Tim Hortons Doughnut", 'D',0,0};
PlayerData PROF = {"Professor", 'P',0,0};
PlayerData STUDENT = {"Student", 'S', 0,0};
PlayerData MONEY = {"Money", '$', 0,0};
PlayerData LAPTOP = {"Laptop", 'L', 0,0};
PlayerData PT = {"Pink tie", 'T', 0,0};

pair<string, PlayerData> playerDataBox[] = {
    make_pair("Goose", GOOSE),
    make_pair("GRT Bus",  GRT),
    make_pair("Tim Hortons Doughnut", THD),
    make_pair("Professor", PROF),
    make_pair("Student", STUDENT),
    make_pair("Money", MONEY),
    make_pair("Laptop", LAPTOP),
    make_pair("Pink tie", PT)
};

map<string, PlayerData> playerOptions(playerDataBox, playerDataBox+sizeof playerDataBox / sizeof playerDataBox[0]);
