//
//  Team.cpp
//  WrestlingSim
//
//  Created by Gregory Hubbard on 3/5/20.
//  Copyright © 2020 Gregory Hubbard. All rights reserved.
//

#include "Team.hpp"
#include "Wrestler.hpp"
#include <iostream>
#include <queue>
#include <random>
#include <array>

using namespace std;


Team::Team()
{
    
}

Team::Team(int i)
{
    id = i*100;
    //std::cout<<"team created with iD: "<<id<<<std::endl;
}


/*
 Generates the number of wrestlers on a team based on a mean of 28 and a std div of 5
 */
void Team::generateTeamSize()
{
    double mean = 28;
    double sd = 5;
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine eng(seed);  //creates random engine
    std::normal_distribution<double> dist(mean, sd);  //creates nom distr
    int teamsize = dist(eng);
    teamSize = teamsize;
}


/*
 number of wrestlers in team after population in weight classes.
 'due to the fact that some generated wrestlers wont fint into a weight class
 */
int Team::activeWrestlers()
{
    int teamsize = 0;
    for(int i = 0; i< 14; i++)
    {
        cout<<"size of weightclass " << i << "="<<weightclass[i].size()<<endl;
        teamsize += weightclass[i].size();
        cout<<"total team size "<< teamsize<<endl;
    }
    return teamsize;
}

/*
 returns the top wrestler in the queue.  If the queue is empty, a wrestler from the weight class below will wrestle instead.
 */

Wrestler* Team::getWrestler(int i)
{
    if(!(weightclass[i].empty()))
    {
        return weightclass[i].top();
    }
    
    if(weightclass[i].empty() && !(weightclass[i-1].empty()) && i != 0)
    {
        return weightclass[i-1].top();
    }
    /*
    if(weightclass[i].empty() && i == 0)
    {
        return nullptr;
    }
    
    if(weightclass[i].empty() && weightclass[i-1].empty() && i != 0)
    {
        return nullptr;
    }
    */
   else
   {
    Wrestler * aptr; //pointer
    aptr = new Wrestler(-100);//creating an object
    //change 100 based on team id
    aptr -> setAbility(0);
    aptr -> setWeight();
    return aptr;
   }
}


void Team::populateTeam()
{
    //creates an array of wrestlers with ability and weight based on generated team size
    Wrestler* array[teamSize];
    for(int x = 0; x < teamSize; x++)
    {
        array[x] = new Wrestler(x+id);  //change 100 based on team id
        array[x] -> setAbility();
        array[x] -> setWeight();
    }
    
    //organizes the wrestlers in an array of priority queues
    //array index = weight class
    //priority queue =  wrestlers in the weight class
    
    for(int x = 0; x < teamSize; x++)
    {
        int wT = array[x] -> getWeight();
        
        if((wT >= 87) && (wT < 106))
        {
            weightclass[0].push(array[x]);
        }
        
        if((wT >= 106) && (wT < 113))
        {
            weightclass[1].push(array[x]);
        }
        
        if((wT >= 113) && (wT < 120))
        {
            weightclass[2].push(array[x]);
        }
        
        if((wT >= 120) && (wT < 126))
        {
            weightclass[3].push(array[x]);
        }
        
        if((wT >= 126) && (wT < 132))
        {
            weightclass[4].push(array[x]);
        }
        
        if((wT >= 132) && (wT < 138))
        {
            weightclass[5].push(array[x]);
        }
        
        if((wT >= 138) && (wT < 145))
        {
            weightclass[6].push(array[x]);
        }
        
        if((wT >= 145) && (wT < 152))
        {
            weightclass[7].push(array[x]);
        }
        
        if((wT >= 152) && (wT < 160))
        {
            weightclass[8].push(array[x]);
        }
        
        if((wT >= 160) && (wT < 170))
        {
            weightclass[9].push(array[x]);
        }
        
        if((wT >= 170) && (wT < 182))
        {
            weightclass[10].push(array[x]);
        }
        
        if((wT >= 182) && (wT < 195))
        {
            weightclass[11].push(array[x]);
        }
        
        if((wT >= 195) && (wT < 220))
        {
            weightclass[12].push(array[x]);
        }
        
        if((wT >= 220) && (wT < 285))
        {
            weightclass[13].push(array[x]);
        }
        
    }
}
    void Team::addWin(int id)
    {
        wins.push_back(id);
    }

    void Team::addLoss(int id)
    {
        losses.push_back(id);
    }
    
void Team::displayWins()
{
    for(int x =0; x < wins.size(); x++)
    {
        cout<< wins[x] << "," ;
    }
}

    


