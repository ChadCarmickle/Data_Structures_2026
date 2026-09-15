/**************************************************************************************************
 *                                                                                                *
 *                                      AlienCaptain.h                                            *
 *                                                                                                *
 *                                 Spaceship Class: Child:Enemy                                   *
 **************************************************************************************************
 Program name: Midterm Text-Based Project.  
 Author: Chad Carmickle & Christian Denning
 Date last updated: 9/11/26
 Purpose: Midterm Project.
*/ 
//                                      Alien Captain
// Type:   Boss
// Speed:  Low 
// Damage: High
// Notes: Serves as a tutorial Boss. 


#ifndef ALIENCAPTAIN_H
#define ALIENCAPTAIN_H

#include "../../Spaceship/Spaceship.h"

class AlienCaptain : public Spaceship
{
private:
    std::string name = "Alien Captain";

public:
    AlienCaptain(
        const std::string& shipName = "Alien Captain",
        int health = 125,
        int attack = 20
    );

    std::string getName() const;
};

#endif
