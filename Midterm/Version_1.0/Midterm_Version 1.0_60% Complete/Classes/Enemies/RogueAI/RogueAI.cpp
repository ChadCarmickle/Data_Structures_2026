/**************************************************************************************************
 *                                                                                                *
 *                                          RogueAI.cpp                                          *
 *                                                                                                *
 *                                 Spaceship Class: Child:Enemy                                   *
 **************************************************************************************************
 Program name: Midterm Text-Based Project.  
 Author: Chad Carmickle & Christian Denning
 Date last updated: 9/11/26
 Purpose: Midterm Project.
*/ 
//                                      Rogue AI
// Type:   Boss
// Speed:  med-high
// Damage: med-high
// Notes: Stage 4 boss. 

#include "RogueAI.h"

RogueAI::RogueAI(
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

std::string RogueAI::getName() const
{
    return name;
}