#ifndef __NPDATA_H__
#define __NPDATA_H__
#include <string>
#include <map>
using namespace std;

struct npData
{
    std::string name;
    std::string desc;
    int pCost;
    int row, column;

};

extern std::map<std::string, npData> npInfo;


#endif

