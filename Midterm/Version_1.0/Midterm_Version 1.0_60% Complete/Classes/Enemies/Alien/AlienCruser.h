/**************************************************************************************************
 *                                                                                                *
 *                                      AlienCruser.h                                             *
 *                                                                                                *
 *                                 Spaceship Class: Child:Enemy                                   *
 **************************************************************************************************
 Program name: Midterm Text-Based Project.  
 Author: Chad Carmickle & Christian Denning
 Date last updated: 9/11/26
 Purpose: Midterm Project.
*/ 
//                                      Alien Cruser
// Type:   Strong Enemy
// Speed:  Med 
// Damage: Med
// Notes: Serves as an mediunm challenge level. 


#ifndef ALIENCRUSER_H
#define ALIENCRUSER_H

#include "../../Spaceship/Spaceship.h"

class AlienCruser : public Spaceship
{
private:
    std::string name = "Alien Cruser";

public:
    AlienCruser(
        const std::string& shipName = "Alien Cruser",
        int health = 100,
        int attack = 15
    );

    std::string getName() const;
};

#endif
