//
//  Match.cpp
//  WrestlingSim
//
//  Created by Gregory Hubbard on 3/21/20.
//  Copyright © 2020 Gregory Hubbard. All rights reserved.
//

#include "Match.hpp"
#include "Wrestler.hpp"
#include "Team.hpp"
#include "Bout.hpp"
#include <iostream>



Match::Match(Team *teamptr1, Team *teamptr2)
{
    t1 = teamptr1;
    t2 = teamptr2;
    t1Score = 0;
    t2Score = 0;
    doMatch();
    addWinLoss();
    winner();
};

void Match::doMatch()
{
    for(int i =0; i<14; i++)
    {
        Bout *bptr;
        
        //checks for null wrestlers
        if(((t1->getWrestler(i)) == nullptr)|| (t2->getWrestler(i)==nullptr))
        {
        continue;
        }
        
        else
        {
        bptr = new Bout(t1 -> getWrestler(i), t2 -> getWrestler(i));
        t1Score += bptr -> getW1Point();
        t2Score += bptr -> getW2Point();
        }
    }
    
}
//returns the winner of the Match
void Match::winner()
{
    if (t1Score >= t2Score)
    {
        std::cout<<std::endl;
        //std::cout<<"team: "<<  t2 -> getId() <<" won with: "<< t1Score<<std::endl;
    }
    else
        std::cout<<std::endl;
        //std::cout<<"team: "<<  t2 -> getId() <<" lost with: "<< t2Score<<std::endl;
}

void Match::addWinLoss()
{
    if (t1Score >= t2Score)
    {
        t1 -> addWin(t2 -> getId());
        t2 -> addLoss(t2 -> getId());
    }
    else

        t2 -> addWin(t1 -> getId());
        t1 -> addLoss(t2 -> getId());
}
