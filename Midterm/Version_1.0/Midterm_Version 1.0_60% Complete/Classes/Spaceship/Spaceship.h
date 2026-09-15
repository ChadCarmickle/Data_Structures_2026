/**************************************************************************************************
 *                                                                                                *
 *                                      Spaceship.h                                               *
 *                                                                                                *
 *                                 Spaceship Class: Parent                                        *
 **************************************************************************************************
 Program name: Midterm Text-Based Project.  
 Author: Chad Carmickle & Christian Denning
 Date last updated: 9/11/26
 Purpose: Midterm Project.
*/ 


#ifndef SPACESHIP_H
#define SPACESHIP_H

#include <string>

class Spaceship
{
protected:
    std::string shipName = "Default";

    int health = 100;
    int maxHealth = 100;
    int attackPower = 10;
    int attackSpeed = 5;

    bool isActiveShip = false;

public:
    Spaceship(const std::string& name);

    void setShipName(const std::string& name);
    std::string getShipName() const;

    int getHealth() const;
    int getMaxHealth() const;
    int getAttackPower() const;
    int getAttackSpeed() const;
    bool getIsActiveShip() const;

    void heal(int amount);
    void increaseMaxHealth(int amount);
    void increaseAttack(int amount);
    

    void attack();
    void takeDamage(int damage);
    bool isDefeated() const;
};

#endif