#include <string>
#include "npdata.h"
#include <map>
using namespace std;


npData OSAP = {"Collect OSAP", "Collect $200, unless told otherwise", 200, 0, 0};
npData DCTL = {"DC Tims Line", "Nothing happens", 0, 0,0};
npData GTTIMS = {"Go to Tims", "HAHA, Go go Tim's Line, do not collect $200 from OSAP", 0, 0};
npData GNEST = {"Goose Nesting", "You just got attacked by a flock of geese",0,0,0};
npData TUITION = {"Tuition", "Choose between paying paying $300 of your total worth (including savings, printed prices of all buildings you own, and costs of each improvement", 0,0,0};
npData COOPFEE = {"Coop Fee", "Pay $150 to school", -150, 0,0};
npData SLC = {"SLC", "we are going to randomly move you on the board", 0,0,0};
npData NHALL = {"Needles Hall", "Oh shit", 0,0,0};

pair<string, npData> nPInfo_data[] =  
{
    make_pair("COLLECT OSAP", OSAP),
    make_pair("DC Tims Line", DCTL),
    make_pair("GO TO TIMS", GTTIMS),
    make_pair("Goose Nesting", GNEST),
    make_pair("TUITION", TUITION),
    make_pair("COOP FEE", COOPFEE),
    make_pair("SLC", SLC),
    make_pair("NEEDLES HALL", NHALL)
};
map<string, npData> npInfo(nPInfo_data, nPInfo_data + sizeof nPInfo_data / sizeof nPInfo_data[0]);



