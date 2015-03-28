#ifndef __ACADEMIC_H__
#define __ACADEMIC_H__
#include <string>
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

};

extern std::map<std::string, Academic> aInfo;
extern std::string const names[];
extern bool const prop[];


#endif

