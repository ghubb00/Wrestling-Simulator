//
//  NonLeagueSchedule.hpp
//  WrestlingSim
//
//  Created by Gregory Hubbard on 3/27/20.
//  Copyright © 2020 Gregory Hubbard. All rights reserved.
//

#ifndef NonLeagueSchedule_hpp
#define NonLeagueSchedule_hpp
#include "Team.hpp"
#include <stdio.h>
class NonLeagueSchedule
{
public:
    NonLeagueSchedule(Team* []);
    void doMatch(int t1, int t2, Team* []);
private:
    int count = 0;
};
#endif /* NonLeagueSchedule_hpp */
