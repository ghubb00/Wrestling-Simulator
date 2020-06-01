//
//  Wrestler.cpp
//  WrestlingSim
//
//  Created by Gregory Hubbard on 1/27/20.
//  Copyright © 2020 Gregory Hubbard. All rights reserved.
//
#include <iostream>
#include <list>
#include <random>
#include <chrono>
#include "Wrestler.hpp"


Wrestler::Wrestler()
{
   // std::cout<<"wrestler created";
    injured = false;
}

Wrestler::Wrestler(int i)
{
    injured = false;
    id = i;
    //std::cout<<"wrestler created with iD: "<<id<<std::endl;
}


/*
 Each wrestler’s weight will be determined randomly with a mean of 152 and a standard deviation of 27
 normal_distribution<double> dist(mean, standard deviation);
 */

void Wrestler::setWeight()
{
    double mean = 152;
    double sd = 27;
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine eng(seed);  //creates random engine
    std::normal_distribution<double> dist(mean, sd);  //creates nom distr
    int sdweight = dist(eng);
    weight = sdweight;
};

/*
 Wrestlers also have a ability score mean = 100, std. div = 15. Each will also have a Boolean value “injured” by default will be set to false
 */
void Wrestler::setAbility()
{
    double mean = 100;
    double sd = 15;
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine eng(seed);  //creates random engine
    std::normal_distribution<double> dist(mean, sd);  //creates nom distr
    int sdAbility = dist(eng);
    ability = sdAbility;
};


void Wrestler::setInjured()
{
    injured = true;
}

/*
Wrestlers also have a win loss record. Not only the total wins and losses but the ID numbers of those they have lost to.
*/

void Wrestler::addWin(int id)
{
    wins.push_back(id);
}

void Wrestler::addLoss(int id)
{
    losses.push_back(id);
}

int Wrestler::getTeam()
{
    int team = id/100;
    return team;
}

void Wrestler::display()
{
    std::cout<<endl;
    std::cout <<"wrestler id:"<<id<<"with ability "<< ability<<std::endl;
}

void Wrestler::setAbility(int i)
{
    ability = i;
}

void Wrestler::getIdString()
{
    if(id < 0)
        cout<<"empty seed / DQ";
    else
        cout<<id;
}





