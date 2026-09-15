/**************************************************************************************************
 *                                                                                                *
 *                                      PirateCruser.h                                            *
 *                                                                                                *
 *                                 Spaceship Class: Child:Enemy                                   *
 **************************************************************************************************
 Program name: Midterm Text-Based Project.  
 Author: Chad Carmickle & Christian Denning
 Date last updated: 9/11/26
 Purpose: Midterm Project.
*/ 
//                                      Pirate Cruser
// Type:   Strong Enemy
// Speed:  Med 
// Damage: Med
// Notes: Serves as an mediunm challenge level. 

#ifndef PIRATECRUSER_H
#define PIRATECRUSER_H

#include "../../Spaceship/Spaceship.h"

class PirateCruser : public Spaceship
{
private:
    std::string name = "Pirate Cruser";

public:
    PirateCruser(
        const std::string& shipName = "Pirate Cruser",
        int health = 110,
        int attack = 17
    );

    std::string getName() const;
};

#endif