//
//  main.cpp
//  WrestlingSim
//
//  Created by Gregory Hubbard on 1/27/20.
//  Copyright © 2020 Gregory Hubbard. All rights reserved.
//

#include <iostream>
#include <array>
#include <queue>
#include <vector>
#include "Wrestler.hpp"
#include "Team.hpp"
#include "Bout.hpp"
#include "Match.hpp"
#include "Tournament.hpp"
#include "LeagueSchedule.hpp"
#include "NonLeagueSchedule.hpp"

using namespace std;

int main()
{
    //creates 32 teams with mean size of 28 and a std div of 5.
    Team* allTeams[32];
    for(int x = 0; x < 32; x++)
    {
        allTeams[x] = new Team(x+1); //starting at team 100
        allTeams[x] -> generateTeamSize();
        allTeams[x] -> populateTeam();
    }
    
    //first week of matches only against teams inside league 1
    cout<<"Start of Simulation"<<endl;
    cout<<endl<<"-----------------------------------------------"<<endl;
    LeagueSchedule m1(allTeams);
    cout<<endl<<"-----------------------------------------------"<<endl;
    //tournament 2 league teams and 6 non league teams
   Tournament t1(allTeams);
   cout<<endl<<"-----------------------------------------------"<<endl;
  cout<<"Start of Week 4"<<endl;
    cout<<endl<<"-----------------------------------------------"<<endl;
   NonLeagueSchedule m2(allTeams);
    cout<<endl<<"-----------------------------------------------"<<endl;
   Tournament t2(allTeams);
    cout<<endl<<"-----------------------------------------------"<<endl;
    cout<<"Start of Week 8"<<endl;
    cout<<endl<<"-----------------------------------------------"<<endl;
    NonLeagueSchedule m3(allTeams);
    cout<<endl<<"-----------------------------------------------"<<endl;
   Tournament t3(allTeams);
    cout<<"Start of Week 12"<<endl;
    cout<<endl<<"-----------------------------------------------"<<endl;
    NonLeagueSchedule m4(allTeams);
    cout<<endl<<"-----------------------------------------------"<<endl;
    //gets the teams in League 1
    Team* League1[8];
    for(int x =0; x<32; x++)
    {
        League1[x] = allTeams[x];
    }
    bool tournament = true;
    
    cout<<endl;
    cout<<"Week 16 (FINAL TOURNAMENT)"<<endl;
    Tournament t4(League1,tournament);
    cout<<endl<<"-----------------------------------------------"<<endl;
    
    
    cout<<endl;
    cout<<endl;
    cout<<endl<<"-----------------------------------------------"<<endl;
    cout<<"END OF SIMULATION"<<endl;
    cout<<endl<<"-----------------------------------------------"<<endl;
    cout<<"final team results"<<endl;
    for(int x = 0; x < 32; x++)
    {
        cout<<"Team "<< x << " won against Ids:" ;
        allTeams[x] -> displayWins();
        
        cout<<endl;
    }
    
    
    
    return 0;
}

