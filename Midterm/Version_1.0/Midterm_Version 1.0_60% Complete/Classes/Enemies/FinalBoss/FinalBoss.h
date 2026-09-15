/**************************************************************************************************
 *                                                                                                *
 *                                      FinalBoss.h                                               *
 *                                                                                                *
 *                                 Spaceship Class: Child:Enemy                                   *
 **************************************************************************************************
 Program name: Midterm Text-Based Project.  
 Author: Chad Carmickle & Christian Denning
 Date last updated: 9/11/26
 Purpose: Midterm Project.
*/ 


#ifndef FINALBOSS_H
#define FINALBOSS_H

#include "../../Spaceship/Spaceship.h"

class FinalBoss : public Spaceship
{
private:
    std::string name = "Final Boss";

public:
    FinalBoss(
        const std::string& shipName = "Final Boss",
        int health = 200,
        int attack = 25
    );

    std::string getName() const;
};

#endif