/**************************************************************************************************
 *                                                                                                *
 *                                      PirateScout.h                                             *
 *                                                                                                *
 *                                 Spaceship Class: Child:Enemy                                   *
 **************************************************************************************************
 Program name: Midterm Text-Based Project.  
 Author: Chad Carmickle & Christian Denning
 Date last updated: 9/11/26
 Purpose: Midterm Project.
*/ 
//                                      Pirate Scout
// Type:   Weak Enemy
// Speed:  high 
// Damage: Low
// Notes: Serves as an low challenge level. 

#ifndef PIRATESCOUT_H
#define PIRATESCOUT_H

#include "../../Spaceship/Spaceship.h"
#include <string>

class PirateScout : public Spaceship
{
private:
    std::string name = "Pirate Scout";

public:
    PirateScout(
        const std::string& shipName = "Pirate Scout",
        int health = 80,
        int attack = 12
    );

    std::string getName() const;
};

#endif