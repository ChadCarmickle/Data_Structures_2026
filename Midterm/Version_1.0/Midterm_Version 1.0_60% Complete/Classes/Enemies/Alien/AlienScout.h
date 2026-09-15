/**************************************************************************************************
 *                                                                                                *
 *                                      AlienScout.h                                              *
 *                                                                                                *
 *                                 Spaceship Class: Child:Enemy                                   *
 **************************************************************************************************
 Program name: Midterm Text-Based Project.  
 Author: Chad Carmickle & Christian Denning
 Date last updated: 9/11/26
 Purpose: Midterm Project.
*/ 
//                                      Alien Scout
// Type:   Weak Enemy
// Speed:  high 
// Damage: Low
// Notes: Serves as an low challenge level. 

#ifndef ALIENSCOUT_H
#define ALIENSCOUT_H

#include "../../Spaceship/Spaceship.h"

class AlienScout : public Spaceship
{
private:
    std::string name = "Alien Scout";

public:
    AlienScout(
        const std::string& shipName = "Alien Scout",
        int health = 75,
        int attack = 10
    );

    std::string getName() const;
};

#endif