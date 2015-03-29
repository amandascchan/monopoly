#ifndef __PLAYERDATA_H__
#define __PLAYERDATA_H__
#include <string>
#include <map>

struct PlayerData {
    std::string name;
    char avatar;
    int row, column;
};
extern std::map<std::string, PlayerData> playerOptions;
#endif

