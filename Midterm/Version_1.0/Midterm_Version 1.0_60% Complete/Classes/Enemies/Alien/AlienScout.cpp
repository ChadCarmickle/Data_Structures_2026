/**************************************************************************************************
 *                                                                                                *
 *                                      AlienScout.cpp                                            *
 *                                                                                                *
 *                                 Spaceship Class: Child:Enemy                                   *
 **************************************************************************************************
 Program name: Midterm Text-Based Project.  
 Author: Chad Carmickle & Christian Denning
 Date last updated: 9/11/26
 Purpose: Midterm Project.
*/ 
//                                      Alien Scout
// Type:   Weak Enemy
// Speed:  high 
// Damage: Low
// Notes: Serves as an low challenge level. 


#include "AlienScout.h"

AlienScout::AlienScout(
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

std::string AlienScout::getName() const
{
    return name;
}