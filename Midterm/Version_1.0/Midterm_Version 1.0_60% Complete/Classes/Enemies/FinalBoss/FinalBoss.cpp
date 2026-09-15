/**************************************************************************************************
 *                                                                                                *
 *                                      FinalBoss.cpp                                             *
 *                                                                                                *
 *                                 Spaceship Class: Child:Enemy                                   *
 **************************************************************************************************
 Program name: Midterm Text-Based Project.  
 Author: Chad Carmickle & Christian Denning
 Date last updated: 9/11/26
 Purpose: Midterm Project.
*/ 
//                                      Final Boss
// Type:   Extreme Enemy
// Speed:  Extreme
// Damage: Extreme
// Notes: Final Boss, Hardest challenge player must face. 



#include "FinalBoss.h"

FinalBoss::FinalBoss(
    const std::string& shipName,
    int health,
    int attack
)
    : Spaceship(shipName)
{
    this->health = health;
    this->maxHealth = health;
    this->attackPower = attack;
}

std::string FinalBoss::getName() const
{
    return name;
}