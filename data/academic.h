#ifndef __ACADEMIC_H__
#define __ACADEMIC_H__
#include <map>
using namespace std;

struct Academic
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
extern std::map<std::string, Academic> aInfo;
extern std::string const names[];
extern bool const prop[];
extern std::string const cNames[];
extern int spots[][2];


#endif

