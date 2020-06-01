//
//  Bout.hpp
//  WrestlingSim
//
//  Created by Gregory Hubbard on 3/5/20.
//  Copyright © 2020 Gregory Hubbard. All rights reserved.
//

#ifndef Bout_hpp
#define Bout_hpp
#include "Wrestler.hpp"
#include <stdio.h>
class Bout
{
public:
    Bout(Wrestler *wptr1, Wrestler *wptr2);
    int awardPoints(int d);
    int getW1Point(){return w1Point;}
    int getW2Point(){return w2Point;}
    bool firstWon(){return first;}//true if first param is the winner
    Wrestler* getWinner();
    Wrestler* getLoser();
    
private:
    int diff;
    int w1Point;
    int w2Point;
    bool first;
    Wrestler* winner;
    Wrestler* loser;
    void addWinLoss(double s1, double s2, Wrestler* wptr1,Wrestler* wptr2);
};

#endif /* Bout_hpp */
