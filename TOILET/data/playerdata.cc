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
    make_pair("1", GOOSE),
    make_pair("2",  GRT),
    make_pair("3", THD),
    make_pair("4", PROF),
    make_pair("5", STUDENT),
    make_pair("6", MONEY),
    make_pair("7", LAPTOP),
    make_pair("8", PT)
};

map<string, PlayerData> playerOptions(playerDataBox, playerDataBox+sizeof playerDataBox / sizeof playerDataBox[0]);
