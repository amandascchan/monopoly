#include <string>
#include "academic.h"
#include <map>
using namespace std;


Academic AL = {"AL", "Arts1", 40, 50, {2,10,30,90,160,250}, "A"};
Academic ML = {"ML", "Arts1", 60, 50, {4,20,60,180,320,450}, "A"};
Academic ECH = {"ECH", "Arts2", 100, 50, {6,30, 90, 270, 400, 550}, "A"};
Academic PAS = {"PAS", "Arts2", 100, 50, {6,30,90,270,400, 550}, "A"};
Academic HH = {"HH", "Arts2", 120, 50, {8,40,100,300,450,600}, "A"};
Academic RCH = {"RCH", "Eng", 140, 100, {10, 50, 150, 450, 625,750}, "A"};
Academic DWE = {"DWE", "Eng", 140, 100, {10, 50, 150, 450, 625, 750}, "A"};
Academic CPH = {"CPH", "Eng", 160, 100, {12, 60, 180, 500, 700, 900}, "A"};
Academic LHI = {"LHI", "Health", 180, 100, {14, 70, 200, 550, 750, 950}, "A"};
Academic BMH = {"BMH", "Health", 180, 100, {14, 70, 200, 550, 750, 950}, "A"};
Academic OPT = {"OPT", "Health", 200, 100, {16,80,220,600,800,1000}, "A"};
Academic EV1 = {"EV1", "Env", 220, 150, {18, 90, 250, 700, 875, 1050}, "A"};
Academic EV2 = {"EV2", "Env", 220, 150, {18,90,250,700,875,1050}, "A"};
Academic EV3 = {"EV3", "Env", 240,150,{20,100,300,750,925,1100}, "A"};
Academic PHYS = {"PHYS", "Sci1", 260, 150, {22,110,330,800,975,1150}, "A"};
Academic B1 = {"B1", "Sci1", 260, 150, {22, 110, 330, 800, 975, 1150}, "A"};
Academic B2 = {"B2", "Sci1", 280 , 150, {24,120, 360,850, 1025, 1200}, "A"};
Academic EIT = {"EIT", "Sci2",300, 200, {26,130, 390, 900,1100, 1275}, "A"};
Academic ESC= {"ESC", "Sci2", 300, 200, {26, 130, 390, 900, 1100, 1275}, "A"};
Academic C2 = {"C2", "Sci2", 320, 200 ,{28,150,450, 1000, 1200, 1400}, "A"};
Academic MC = {"MC", "Math", 350, 200, {35,175, 500,1100, 1300, 1500}, "A"};
Academic DC ={"DC", "Math", 400, 200, {50, 200, 600, 1400, 1700, 2000}, "A"};
Academic MKV = {"MKV", "", 200, 0, {0,25,50,100, 150,0}, "R"};
Academic UWP = {"UWP", "", 200, 0, {0,25,50,100,150,0}, "R"};
Academic V1 = {"V1", "", 200, 0, {0,25,50,100,150,0}, "R"};
Academic REV = {"REV", "", 200, 0, {0,25,50,100,150,0}, "R"};
Academic PAC = {"PAC", "", 150, 0, {0,0,0,0,0,0}, "G"};
Academic CIF = {"CIF", "", 150, 0, {0,0,0,0,0,0}, "G"};

pair<string, Academic> aInfo_data[] =  
{
    make_pair("AL",AL),
    make_pair("ML", ML),
    make_pair("ECH", ECH),
    make_pair("HH", HH),
    make_pair("RCH",RCH),
    make_pair("DWE",DWE),
    make_pair("CPH",CPH),
    make_pair("LHI",LHI),
    make_pair("BMH",BMH),
    make_pair("OPT",OPT),
    make_pair("EV1",EV1),
    make_pair("EV2",EV2),
    make_pair("EV3",EV3),
    make_pair("PHYS", PHYS),
    make_pair("B1", B1),
    make_pair("B2", B2),
    make_pair("EIT", EIT),
    make_pair("ESC", ESC),
    make_pair("C2",C2),
    make_pair("MC", MC),
    make_pair("DC", DC),
    make_pair("PAC", PAC),
    make_pair("CIF", CIF),
    make_pair("MKV", MKV),
    make_pair("REV", REV),
    make_pair("UWP", UWP),
    make_pair("V1", V1)
};
map<string, Academic> aInfo(aInfo_data, aInfo_data + sizeof aInfo_data / sizeof aInfo_data[0]);

const string names[] = {"Goose Nesting", "EV1", "NEEDLES HALL", "EV2", "EV3", "V1","PHYS","B1", "CIF", "B2", "GO TO TIMS", "OPT", "EIT", "BMH", "ESC", "SLC", "SLC", "LHI", "C2", "UWP", "REV", "CPH", "NEEDLES HALL", "DWE", "MC", "PAC", "COOP FEE", "RCH", "DC", "DC Tims Line", "HH","PAS", "NEEDLES HALL", "ECH", "MKV", "TUITION", "ML", "SLC", "AL", "COLLECT OSAP"};
const bool prop[] = {false, true, false, true, true, false, true, true, false, true, false, true,true, true, true, false, false, true, true, false, false, true, false, true, true, false,false, true, true, false, true, true, false, true, false, false, true, false, true, false};
