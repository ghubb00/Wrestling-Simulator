//
//  Wrestler.hpp
//  WrestlingSim
//
//  Created by Gregory Hubbard on 1/27/20.
//  Copyright © 2020 Gregory Hubbard. All rights reserved.
//

#ifndef Wrestler_hpp
#define Wrestler_hpp

#include <stdio.h>
#include <list>
using namespace std;

class Wrestler
{
public:
    Wrestler(int);
    Wrestler();
    void setWeight();
    int getWeight() {return weight;}
    int getAbility() {return ability;}
    int getId(){return id;}
    int getTeam();
    void setAbility();
    void setAbility(int); //for null wrestlers
    void setInjured();
    void addWin(int id);
    void addLoss(int id);
    void display();
    void getIdString();

    
    
private:
    int weight;
    int ability;
    int injured;
    int id;
    std::list<int> wins;
    std::list<int> losses;
};


#endif /* Wrestler_hpp */

