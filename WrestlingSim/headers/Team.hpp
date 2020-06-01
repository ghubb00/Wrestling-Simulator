//
//  Team.hpp
//  WrestlingSim
//
//  Created by Gregory Hubbard on 3/5/20.
//  Copyright © 2020 Gregory Hubbard. All rights reserved.
//

#ifndef Team_hpp
#define Team_hpp

#include <stdio.h>
#include <vector>
#include <queue>
#include "Wrestler.hpp"

class Team
{
public:
    Team();
    Team(int);
    void generateTeamSize();
    void populateTeam();
    void fillTeam(Wrestler* []);
    int activeWrestlers();
    Wrestler* getWrestler(int weightclass); //returns the top wrestler of given weightclass
    void addLoss(int);
    void addWin(int);
    void displayWins();
    void displayLoss();
    int getId() {return id;}


    
private:
    int id;
    std::vector<int> wins;
    std::vector<int> losses;
    int teamSize;
    std::priority_queue<Wrestler*> weightclass[14];

};


#endif /* Team_hpp */
