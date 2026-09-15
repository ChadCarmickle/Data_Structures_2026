/**************************************************************************************************
 *                                                                                                *
 *                                      Ally.cpp                                                  *
 *                                                                                                *
 *                                  Ally Class: Child                                              *
 **************************************************************************************************
 Program name: Midterm Text-Based Project.
 Author: Chad Carmickle & Christian Denning
 Date last updated: 9/11/26
 Purpose: Midterm Project.
*/
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>



#include "Ally.h"

Ally::Ally(
    const std::string& name,
    const std::string& last, 
    const std::string& title,
    const std::string& shipName,
    int health,
    int attack
)
    : Spaceship(shipName)
{
    this->name = name;
    this->last = last; 
    this->title = title;
    this->health = health;
    this->maxHealth = health;
    this->attackPower = attack;
}

std::string Ally::getName() const
{
    return name;
}

std::string Ally::getlast() const 
{ 
    return last; 
}

std::string Ally::getTitle() const
{
    return title;
}


void Ally::showStats() const
{
    std::cout << "Name: " << getName()  << " " << getlast() << '\n';
    std::cout << "Title: " << getTitle() << '\n';
    std::cout << "Ship: " << getShipName() << '\n';
    std::cout << "Health: " << getHealth() << '\n';
    std::cout << "Attack: " << getAttackPower() << '\n';
}

bool Ally::Joined() const
{
    return joined;
}

void Ally::setJoined(bool status)
{
    joined = status;
}


// First Name, Last Name, Title, Ship Name, Health, Attack.

Ally ally1(
    "Kael",
    "Sunstrider",
    "Flame Sorcerer",
    "Phoenix",
    100,
    20
);

Ally ally2(
    "Darius",
    "Noxus",
    "Combat Specialist",
    "Noxian Guillotine",
    100,
    40
);

Ally ally3(
    "Ezio",
    "Auditore",
    "Infiltration Specialist",
    "Brotherhood",
    120,
    15
);

Ally ally4(
    "Alex",
    "",
    "Redstone Engineer",
    "Ender Dragon",
    90,
    25
);


// Unique Retreat messages. 
void Ally::ShowRetreatMessage()
{
    std::vector<std::string> messages =
    {
        getName() + ": We've taken a direct hit! I'm breaking away!",
        getShipName() + ": can't maneuver their attacks! I'm retreating!",
        getName() + ": I need to get out before we lose the ship!",
        getName() + ": I'm out of options! Pulling back now!",
        getShipName() + ": Repairs has failed! I'm withdrawing!",
        getName() + ": I'm losing too much power! Falling back!",
        getName() + ": That last hit nearly tore us apart! I'm disengaging!",
        getName() + ": We can't survive another exchange! Retreating!",
        getShipName() + " is heavily damaged! I'm heading for friendly lines!",
        getName() + ": I'm abandoning the attack run! Breaking off!",
        getShipName() + ": I can't keep the enemy off us! I'm pulling back!",
        getName() + ": We're crippled and exposed! I have to withdraw!",
        getShipName() + ": Our defenses are gone! I'm retreating!",
        getName() + ": Damage is spreading through the ship! Disengaging!",
        getName() + ": The ship's barely responding! I'm falling back!",
        getShipName() + " has lost combat capability! Returning to safety!",
        getName() + ": We need a repair dock before this gets worse!",
        "Commander, I'm cutting losses! " + getShipName() + " is retreating!",
        getName() + ": The enemy has us boxed in! Breaking through and withdrawing!",
        getShipName() + ": Emergency repairs are failing! I'm pulling away!",
        getName() + ": We're running out of time! Disengaging now!",
        getShipName() + "Commander, cover our escape! We're too damaged to continue!",
        getName() + ": I can't bring weapons or engines online! Withdrawing!",
        getShipName() + " is in no condition to fight! I'm heading home!"
    };

    static std::vector<bool> used(messages.size(), false);
    static int messagesUsed = 0;

    // Reset once every message has been used.
    if (messagesUsed == static_cast<int>(messages.size()))
    {
        std::fill(used.begin(), used.end(), false);
        messagesUsed = 0;
    }

    int choice;

    // Keep generating until we find an unused message.
    do
    {
        choice = std::rand() % messages.size();
    }
    while (used[choice]);

    used[choice] = true;
    messagesUsed++;

    std::cout << messages[choice]
              << '\n';
}
