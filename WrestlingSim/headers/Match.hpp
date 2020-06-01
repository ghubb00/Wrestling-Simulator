//
//  Match.hpp
//  WrestlingSim
//
//  Created by Gregory Hubbard on 3/21/20.
//  Copyright © 2020 Gregory Hubbard. All rights reserved.
//

#ifndef Match_hpp
#define Match_hpp

#include <stdio.h>
#include "Team.hpp"
#include "Wrestler.hpp"

class Match
{
public:
    Match(Team *teamptr1, Team *teamptr2);
    int teamScores(Team *teamptr1, Team *teamptr2);
    void addWinLoss();
    void winner();
private:
    void doMatch();
    Team *t1;
    Team *t2;
    int t1Score;
    int t2Score;
};
#endif /* Match_hpp */
