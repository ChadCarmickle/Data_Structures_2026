/**************************************************************************************************
 *                                                                                                *
 *                                      PirateCaptain.h                                           *
 *                                                                                                *
 *                                 Spaceship Class: Child:Enemy                                   *
 **************************************************************************************************
 Program name: Midterm Text-Based Project.  
 Author: Chad Carmickle & Christian Denning
 Date last updated: 9/11/26
 Purpose: Midterm Project.
*/ 
//                                      Pirate Captain
// Type:   Boss
// Speed:  Low 
// Damage: High
// Notes: Serves as a tutorial Boss. 

#ifndef PIRATECAPTAIN_H
#define PIRATECAPTAIN_H

#include "../../Spaceship/Spaceship.h"

class PirateCaptain : public Spaceship
{
private:
    std::string name = "Pirate Captain";

public:
    PirateCaptain(
        const std::string& shipName = "Pirate Captain",
        int health = 135,
        int attack = 22
    );

    std::string getName() const;
};

#endif