#include <stdio>
#include <string>
#include "academic.h"
using namespace std;


struct Academic 
{
    string name;
    string block;
    int pCost;
    int imCost;
    int imp[5];
}

Academic AL = {"AL", "Arts1", 40, 50, {2,10,30,90,160,250}};
Academic ML = {"ML", "Arts1", 60, 50, {4,20,60,180,320,450}};
Academic ECH = {"ECH", "Arts2", 100, 50, {6,30, 90, 270, 400, 550}};
Academic PAS = {"PAS", "Arts2", 100, 50, {6,30,90,270,400, 550}};
Academic HH = {"HH", "Arts2", 120, 50, {8,40,100,300,450,600}};
Academic RCH = {"RCH", "Eng", 140, 100, {10, 50, 150, 450, 625,750}};
Academic DWE = {"DWE", "Eng", 140, 100, {10, 50, 150, 450, 625, 750}};
Academic CPH = {"CPH", "Eng", 160, 100, {12, 60, 180, 500, 700, 900}};
Academic LHI = {"LHI", "Health", 180, 100, {14, 70, 200, 550, 750, 950}};
Academic BMH = {"BMH", "Health", 180, 100, {14, 70, 200, 550, 750, 950}};
Academic OPT = {"OPT", "Health", 200, 100, {16,80,220,600,800,1000}};
Academic EV1 = {"EV1", "Env", 220, 150, {18, 90, 250, 700, 875, 1050}};
Academic EV2 = {"EV2", "Env", 220, 150, {18,90,250,700,875,1050}};
Academic EV3 = {"EV3", "Env", 240,150,{20,100,300,750,925,1100}};
Academic PHYS = {"PHYS", "Sci1", 260, 150, {22,110,330,800,975,1150}};
Academic B1 = {"B1", "Sci1", 260, 150, {22, 110, 330, 800, 975, 1150};
Academic B2 = {"B2", "Sci1", 280 , 150, {24,120, 360,850, 1025, 1200}};
Academic EIT = {"EIT", "Sci2",300, 200, {26,130, 390, 900,1100, 1275}};
Academic ESC {"ESH", "Sci2", 300, 200, {26, 130, 390, 900, 1100, 1275}};
Academic C2 = {"C2", "Sci2", 320, 200 {28,150,450, 1000, 1200, 1400}};
Academic MC = {"MC", "Math", 350, 200, {35,175, 500,1100, 1300, 1500}};
Academic Dc ={"DC", "Math", 400, 200, {50, 200, 600, 1400, 1700, 2000}};

Academic info[] = {AL, ML, SCH, PAS, HH, RCH, DWE, CPH, LHI, BMH, OPT, EV1, EV2, EV4, PHYS, B1, B2, EIT, ESC, C2, MC, DC};




