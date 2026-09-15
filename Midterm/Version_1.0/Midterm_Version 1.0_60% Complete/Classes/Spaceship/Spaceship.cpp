/**************************************************************************************************
 *                                                                                                *
 *                                      Spaceship.cpp                                             *
 *                                                                                                *
 *                                 Spaceship Class: Parent                                        *
 **************************************************************************************************
 Program name: Midterm Text-Based Project.  
 Author: Chad Carmickle & Christian Denning
 Date last updated: 9/11/26
 Purpose: Midterm Project.
*/ 


#include "Spaceship.h"


// Constructor
Spaceship::Spaceship(const std::string& name)
    : shipName(name)
{
}



void Spaceship::setShipName(const std::string& name) 
{ 
    shipName = name; 
}

// Returns the name of the ship
std::string Spaceship::getShipName() const
{
    return shipName;
}

// Returns current health
int Spaceship::getHealth() const
{
    return health;
}


// Returns maximum health
int Spaceship::getMaxHealth() const
{
    return maxHealth;
}


// Returns attack power
int Spaceship::getAttackPower() const
{
    return attackPower;
}


// Returns attack speed
int Spaceship::getAttackSpeed() const
{
    return attackSpeed;
}


// Returns whether the ship is currently active
bool Spaceship::getIsActiveShip() const
{
    return isActiveShip;
}


// Basic attack function
void Spaceship::attack()
{
    // Combat functionality will be developed later.
}


// Reduces the ship's health by the specified amount
void Spaceship::takeDamage(int damage)
{
    // Prevents negitive damage inputs that could heal the ship. 
    if (damage > 0)
    {
        health -= damage;
    }

    // Prevent health from going below zero
    if (health < 0)
    {
        health = 0;
    }
}

// Determines whether the ship has been defeated
bool Spaceship::isDefeated() const
{
    return health <= 0;
}


void Spaceship::heal(int amount)
{
    if (amount > 0)
    {
        health += amount;
    }

    if (health > maxHealth)
    {
        health = maxHealth;
    }
}

void Spaceship::increaseMaxHealth(int amount)
{
    if (amount > 0)
    {
        maxHealth += amount;
        health += amount;
    }
}

void Spaceship::increaseAttack(int amount)
{
    if (amount > 0)
    {
        attackPower += amount;
    }
}
