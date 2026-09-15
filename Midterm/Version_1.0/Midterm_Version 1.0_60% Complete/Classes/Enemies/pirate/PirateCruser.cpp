/**************************************************************************************************
 *                                                                                                *
 *                                      PirateCruser.cpp                                          *
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

#include "pirateCruser.h"

PirateCruser::PirateCruser(
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

std::string PirateCruser::getName() const
{
    return name;
}