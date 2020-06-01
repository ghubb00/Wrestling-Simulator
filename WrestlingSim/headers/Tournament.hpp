//
//  Tournament.hpp
//  WrestlingSim
//
//  Created by Gregory Hubbard on 3/26/20.
//  Copyright © 2020 Gregory Hubbard. All rights reserved.
//

#ifndef Tournament_hpp
#define Tournament_hpp

#include <stdio.h>
#include <vector>
#include "Bout.hpp"
#include "Team.hpp"
#include "Wrestler.hpp"
class Tournament
{
public:
    Tournament(Team* [32]);
    Tournament(Team* [8], bool);
    void getParticipants(); //gets atleast 2 teams per league
    vector<Wrestler*> prelimRanking(Team* allTeams[], int i);
    vector<Wrestler*> doTournament(vector<Wrestler*> prelimRank, Bout *k[14]);
    void displayTop3(vector<Wrestler*>);
    void displayRanking(vector<Wrestler*>);
private:
    int participants[8];
    int i;
    //vector<Wrestler*> finalRank;

};
#endif /* Tournament_hpp */
