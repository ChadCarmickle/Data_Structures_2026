/**************************************************************************************************
 *                                                                                                *
 *                                      Rogue AI    .h                                            *
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

#ifndef ROGUEAI_H
#define ROGUEAI_H

#include "../../Spaceship/Spaceship.h"

class RogueAI : public Spaceship
{
private:
    std::string name = "Rogue AI";

public:
    RogueAI(
        const std::string& shipName = "Rogue AI",
        int health = 100,
        int attack = 10
    );

    std::string getName() const;
};

#endif