/**************************************************************************************************
 *                                                                                                *
 *                                      AlienCaptain.cpp                                          *
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


#include "AlienCaptain.h"

AlienCaptain::AlienCaptain(
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

std::string AlienCaptain::getName() const
{
    return name;
}
