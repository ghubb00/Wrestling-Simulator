//
//  Bout.cpp
//  WrestlingSim
//
//  Created by Gregory Hubbard on 3/5/20.
//  Copyright © 2020 Gregory Hubbard. All rights reserved.
//

#include "Bout.hpp"
#include "Wrestler.hpp"
#include <iostream>
#include <list>
#include <random>
#include <chrono>

Bout::Bout(Wrestler *wptr1, Wrestler *wptr2)
{
    
    w1Point = 0;
    w2Point = 0;
    
    int a1 = wptr1 -> getAbility();
    int a2 = wptr2 -> getAbility();

    
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine eng(seed);
    //uncertainty is based on wrestler ability as mean and deviation of 15
    std::normal_distribution <double> dist1(a1, 15);
    std::normal_distribution <double> dist2(a2, 15);
    
    //new ability
    double s1 = dist1(eng);
    double s2 = dist2(eng);
    
    //add to win/loss record
    addWinLoss(s1,s2,wptr1,wptr2);
    
};

void Bout::addWinLoss(double s1, double s2, Wrestler* wptr1,Wrestler* wptr2)
{
    if(s1 > s2)
    {
        //std::cout<<"FIRST IS WINNER"<<std::endl;
        wptr1 -> addWin(wptr2 -> getId());
        wptr2 -> addWin(wptr1 -> getId());
        w1Point = awardPoints(s1-s2);
        first = true;
        winner = wptr1;
        loser = wptr2;
    }
    //if wrestler1 ability is greater than wrestler2, add wrestler2 iD to wrestler1's winlist
    else
    {
        //std::cout<<"SECOND IS WINNER"<<std::endl;
        wptr2 -> addWin(wptr1 -> getId());
        wptr1 -> addLoss(wptr2 -> getId());
        w2Point = awardPoints(s2-s1);
        first = false;
        winner = wptr2;
        loser = wptr1;
    }
}


/*
Win by 1 to 7    3 points
Win by 8 to 14  4 points
Win by 15 to 19 5 points (technical fall)
Win by 20+    6 points win by fall (pin)
 
Returns the number of points the team should have after Bout
*/
int Bout::awardPoints(int d)
{
    if((d > 1) && (d <= 7))
       return 3;
    if((d > 8) && (d <= 14))
       return 4;
    if((d > 15) && (d <= 19))
       return 5;
    if(d > 20)
       return 6;
    else
        return 0;
}


Wrestler* Bout::getWinner()
{
    return winner;
}
Wrestler* Bout::getLoser()
{
    return loser;
}
