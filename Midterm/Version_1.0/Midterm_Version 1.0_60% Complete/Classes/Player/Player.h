/**************************************************************************************************
 *                                                                                                *
 *                                        Player.h                                                *
 *                                                                                                *
 *                                  Player Class: Child                                           *
 **************************************************************************************************
 Program name: Midterm Text-Based Project.
 Author: Chad Carmickle & Christian Denning
 Date last updated: 9/11/26
 Purpose: Player class derived from the Spaceship parent class.
*/



#ifndef PLAYER_H
#define PLAYER_H
#include <string>


#include "../Spaceship/Spaceship.h"

class Player : public Spaceship
{
    
private:
    // Player custom Name. 
    std:: string playerName; 

    // Player-specific resources
    int currency = 500;
    int repairBots = 0;

public:

      Player();

    void setPlayerName(const std::string& name);
    std::string getName() const;

    void setShipName(const std::string& name);


    int getCurrency() const;
    void addCurrency(int amount);
    void removeCurrency(int amount);
        
    int getRepairBots() const;
    void AddRepairBots(int amount); 
    void removeRepairbots(int amount); 

    std::string getBasicSpaceshipStats() const;
    std::string getDetailedSpaceshipStats() const;
};

#endif