//
//  NonLeagueSchedule.cpp
//  WrestlingSim
//
//  Created by Gregory Hubbard on 3/27/20.
//  Copyright © 2020 Gregory Hubbard. All rights reserved.
//

#include <iostream>
#include <random>
#include <ctime>
#include "Match.hpp"
#include "Wrestler.hpp"
#include "Team.hpp"
#include "NonLeagueSchedule.hpp"

using namespace std;

NonLeagueSchedule::NonLeagueSchedule(Team* teams[32])
{
   int S[8][8];
    bool W[24][8];
    for(int i=0; i<8; i++)
    {
        for(int j=0; j<8; j++)
        S[i][j]=0;
    }
    for(int i=0; i<24; i++)
        {
            for(int j=0; j<8; j++)
            {W[i][j]=false;}
        }
    default_random_engine gen(time(NULL));
    uniform_int_distribution<int> Tdist(8,32);
    int R;
    bool cont = true; ///short for continue
    bool found = false;
    for(int col =0; col<8; col++)
    {
        for(int row=0; row<8; row++)
        {
        while(cont)
            {
            R = Tdist(gen);

            for(int prevCol=0; prevCol<col; prevCol++)
            {if(S[row][prevCol]==(R*100)){found = true;}
            }
            if(!found)
                {
                if(W[R-9][col]==false){W[R-8][col]=true;
                          S[row][col]=R-1;
                          cont = false;
                          }
                }
            found = false;
            }
            cont=true;

        }
}
    for(int x=0; x<8; x++)
    {
        for(int y=0; y<8; y = y+2)
        {
        int nexty = y+1;
        doMatch(S[x][y],S[x][nexty], teams);
        }
    }
}

void NonLeagueSchedule::doMatch(int t1, int t2,Team* teams[])
{
    if(t1 > 32)
    {
        t1 = 31;
    }
    if(t2 > 32)
    {
        t2 = 31;
    }
    int team1 = (t1) *100;
    int team2 = (t2) * 100;
    cout<< "Match Between "<<"Team : "<< team1 << " and Team : " << team2;

    Match(teams[t1], teams[t2]);
}


