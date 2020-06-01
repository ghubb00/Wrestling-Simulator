//
//  LeagueSchedule.cpp
//  WrestlingSim
//
//  Created by Gregory Hubbard on 3/27/20.
//  Copyright © 2020 Gregory Hubbard. All rights reserved.
//
#include <iostream>
#include "LeagueSchedule.hpp"
#include "Match.hpp"
#include "Wrestler.hpp"
using namespace std;
LeagueSchedule::LeagueSchedule(Team* teams[32])
{
    
    int robin[2][4] = {
        {0,1,2,3},
        {7,6,5,4}
    };
    
    int temp[2][4] = {
        {0,0,0,0},
        {0,0,0,0}
    };
    
    //store the robin
    for(int i = 0; i<7;i++)
    {
        
        for(int i= 0; i<4; i++)
        {
        doMatch(robin[0][i],robin[1][i],teams);
        }
    
    temp[0][2] = robin[0][1];
    temp[0][3] = robin[0][2];
    temp[1][3] = robin[0][3];
    temp[1][2] = robin[1][3];
    temp[1][1] = robin[1][2];
    temp[1][0] = robin[1][1];
    temp[0][1] = robin[1][0];
        
    int countWeek = 0;
    for (int i = 0; i < 2; i++)
    for (int j = 0; j < 4; j++)
    {
        robin[i][j] = temp[i][j];
    }
        
    }
}
    void LeagueSchedule::doMatch(int t1, int t2,Team* teams[])
    {
        
        int team1 = (t1 + 1) *100;
        int team2 = (t2 + 1) * 100;
        cout<< "Match Between "<<"Team : "<< team1 << " and Team : " << team2;
        Match (teams[t1], teams[t2]);
    }

