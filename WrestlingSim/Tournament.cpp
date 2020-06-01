//
//  Tournament.cpp
//  WrestlingSim
//
//  Created by Gregory Hubbard on 3/26/20.
//  Copyright © 2020 Gregory Hubbard. All rights reserved.
//
#include <vector>
#include <iostream>
#include "Tournament.hpp"
#include "Wrestler.hpp"
#include "Bout.hpp"
using namespace std;
Tournament::Tournament(Team* teams[32])
{
    for(int w = 0; w<14; w++) //for each weight class
    {
    getParticipants(); //get 8 teams with 2 per league
    vector<Wrestler*> inital = prelimRanking(teams, w);
    Bout *k[14];
    cout<<endl<<"-----------------------------------------------"<<endl;
    cout<<"Tournament: results for weight class "<< w <<endl;
    displayTop3(doTournament(inital, k));
    cout<<endl;
    }
};

Tournament::Tournament(Team* teams[8], bool finalT)
{
    bool leagueT = true;
    for(int x =0; x<8;x++)
    {
        participants[x] = x;
    }
    for(int w = 0; w<14; w++) //for each weight class
    {
    vector<Wrestler*> inital = prelimRanking(teams, w);
    Bout *k[14];
    cout<<endl<<"-----------------------------------------------"<<endl;
    cout<<"Final Tournament: results for weight class "<< w <<endl;
    displayTop3(doTournament(inital, k));

    }


};

void Tournament::getParticipants()
{
       int T1L1 = rand() % 8;
       participants[0] = T1L1;
       int T2L1 = rand() % 8;
       participants[1] = T2L1;
       //league 2
       int T1L2 = rand() % 8 + 8;
       participants[2] = T1L2;
       int T2L2 = rand() % 8 + 8;
       participants[3] = T2L2;
       //srand(time(NULL));
       int T1L3 = rand() % 8 + 16;
       participants[4] = T1L3;
       //srand(time(NULL));
       int T2L3 = rand() % 8 + 16;
       participants[5] = T2L3;
       //srand(time(NULL));
       int T1L4 = rand() % 8 + 24;
       participants[6] = T1L4;
       //srand(time(NULL));
       int T2L4 = rand() % 8 + 24;
       participants[7] = T2L4;
}


vector<Wrestler*> Tournament::prelimRanking(Team* allTeams[], int w)
{
        vector<Wrestler*> prelimRank;

        for(int i =0; i < 8 ; i++)
        {
            prelimRank.push_back(allTeams[participants[i]] -> getWrestler(w));
        }
    
    
        //sorted by ability power
        int i, j;
        Wrestler *temp;   // holding variable
        
            for (i=0; i< prelimRank.size() - 1; i++)    // element to be compared
           {
                 for(j = i+1; j < prelimRank.size(); j++)   // rest of the elements
                {
                    if(prelimRank[i] == nullptr)
                        continue;
                    if(prelimRank[j] == nullptr)
                        continue;
                       if (prelimRank[i]  -> getAbility() < prelimRank[j] -> getAbility())
                      {
                               temp = prelimRank[i];          // swap
                               prelimRank[i] = prelimRank[j];
                               prelimRank[j] = temp;
                      }
                 }
            }
    return prelimRank;
}

vector<Wrestler*> Tournament::doTournament(vector<Wrestler*> prelimRank, Bout *k[14])
{
vector<Wrestler*> seedRank;

//first 4 of bracket

Bout a(prelimRank[0],prelimRank[7]); 
k[0] = &a;
seedRank.push_back(k[0]->getLoser());

Bout b(prelimRank[1],prelimRank[6]);
k[1] = &b;
seedRank.push_back(k[1]->getLoser());

Bout c(prelimRank[2],prelimRank[5]);
k[2] = &c;
seedRank.push_back(k[2]->getLoser());

Bout d(prelimRank[3],prelimRank[4]);
k[3] = &d;
seedRank.push_back(k[3]->getLoser());

//semi-finals (using winners of previous bouts)
Bout e(k[0] -> getWinner(),k[1] -> getWinner());
k[4] = &e;
seedRank.push_back(k[4]->getLoser());

Bout f(k[2] -> getWinner(),k[3] -> getWinner());
k[5] = &f;
seedRank.push_back(k[5]->getLoser());

//finals (using winners of semi-finals)
Bout g(k[4] -> getWinner(),k[5] -> getWinner());
k[6] = &g;
seedRank.push_back(k[6]->getLoser());
seedRank.push_back(k[6]->getWinner());
    
vector<Wrestler*> finalRank;
    
  //first 4 of bracket
  Bout a_final(seedRank[0],seedRank[7]);
  k[7] = &a_final;
  finalRank.push_back(k[7]->getLoser());
  
  Bout b_final(seedRank[1],seedRank[6]);
  k[8] = &b_final;
  finalRank.push_back(k[8]->getLoser());
  
  Bout c_final(seedRank[2],seedRank[5]);
  k[9] = &c_final;
  finalRank.push_back(k[9]->getLoser());
  
  Bout d_final(seedRank[3],seedRank[4]);
  k[10] = &d_final;
  finalRank.push_back(k[10]->getLoser());
  
  //semi-finals (using winners of previous bouts)
  Bout e_final(k[7] -> getWinner(),k[8] -> getWinner());
  k[11] = &e_final;
  finalRank.push_back(k[11]->getLoser());
  
  Bout f_final(k[9] -> getWinner(),k[10] -> getWinner());
  k[12] = &f_final;
  finalRank.push_back(k[12]->getLoser());
  
  //finals (using winners of semi-finals)
  Bout g_final(k[11] -> getWinner(),k[12] -> getWinner());
  k[13] = &g_final;
  finalRank.push_back(k[13]->getLoser());
  finalRank.push_back(k[13]->getWinner());
    return finalRank;
}

void Tournament::displayTop3(vector<Wrestler*> finalRank)
{
    cout << endl;
    cout << "Medalists From This Tournament"<<endl;
    cout << "Gold Metal " << "Wrestler id: ";
    finalRank[7] -> getIdString();
    cout<<endl;
    
    cout << "Silver Metal " << "Wrestler id: ";
    finalRank[6] -> getIdString();
    cout<<endl;
    
    cout << "Bronze Metal " << "Wrestler id: ";
    finalRank[5] -> getIdString();
    cout << endl;
    
    int rankCount = 1;
    for(int x = 7; x<finalRank.size();x--)
    {
    cout << endl;
        cout<< "Ranked #" << (rankCount)<<" id:";
        finalRank[x] -> getIdString();
        //cout<<endl;
    rankCount++;
    }
}
