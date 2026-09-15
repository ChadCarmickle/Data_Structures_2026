/**************************************************************************************************
 *                                                                                                *
 *                                      Ally.h                                                    *
 *                                                                                                *
 *                                  Ally Class: Child                                             *
 **************************************************************************************************
 Program name: Midterm Text-Based Project.
 Author: Chad Carmickle & Christian Denning
 Date last updated: 9/11/26
 Purpose: Midterm Project.
*/

#ifndef ALLY_H
#define ALLY_H

#include "../Spaceship/Spaceship.h"

class Ally : public Spaceship
{
private:
    std::string name = "default_ally.h";
    std::string last = "default_ally.h"; 
    std::string title = "default_ally.h";
    bool joined = false;

public:
    Ally(
        const std::string& name = "default_ally.h",
        const std::string& last = "default_ally.h",
        const std::string& title = "default_ally.h", 
        const std::string& shipName = "default_ally.h",
        int health = 100,
        int attack = 10
    );

    std::string getName() const;
    std::string getlast() const; 
    std::string getTitle() const;
    void ShowRetreatMessage();

    void showStats() const;
    
    bool Joined() const;
    void setJoined(bool status);
};


extern Ally ally1;
extern Ally ally2;
extern Ally ally3;
extern Ally ally4;

#endif