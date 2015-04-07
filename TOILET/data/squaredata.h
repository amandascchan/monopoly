#ifndef __SQUAREDATA_H__
#define __SQUAREDATA_H__
#include <map>
using namespace std;

struct SquareData
{
    std::string name;
    std::string block;
    int pCost;
    int imCost;
    int imp[6];
    std::string type;
    int row, column;

};
struct SquareInfo
{
    std::string name;
    std::string type;
};
void fillLoop();
extern std::map<std::string, SquareData> aInfo;
extern std::string const names[];
extern bool const prop[];
extern std::string const cNames[];
extern int spots[][2];


#endif

