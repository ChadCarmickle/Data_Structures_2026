/**************************************************************************************************
 *                                                                                                *
 *                                       Player.cpp                                               *
 *                                                                                                *
 *                                  Player Class: Child                                           *
 **************************************************************************************************
 Program name: Midterm Text-Based Project.
 Author: Chad Carmickle & Christian Denning
 Date last updated: 9/11/26
 Purpose: Player class derived from the Spaceship parent class.
*/
#include "Player.h"

Player::Player()
    : Spaceship("Default ship Name."),
      playerName("Default Player Name.")
{
}

void Player::setPlayerName(const std::string& name)
{
    playerName = name;
}

std::string Player::getName() const
{
    return playerName;
}

void Player::setShipName(const std::string& name)
{
    Spaceship::setShipName(name);
}

int Player::getCurrency() const
{
    return currency;
}

void Player::addCurrency(int amount)
{
    if (amount > 0)
    {
        currency += amount;
    }
}
void Player::removeCurrency(int amount)
{
    if (amount > 0 && amount <= currency)
    {
        currency -= amount;
    }
}


int Player::getRepairBots() const
{
    return repairBots;
}


void Player::AddRepairBots(int amount)
{
    if (amount > 0)
    {
        repairBots += amount;
    }
}

void Player::removeRepairbots(int amount)
{
    if (amount > 0 && amount <= repairBots)
    {
        repairBots -= amount;
    }
}

std::string Player::getBasicSpaceshipStats() const
{
    std::string stats;

    stats += "========== SHIP STATS ==========\n";
    stats += "Commander: " + playerName + "\n";
    stats += "Currency: " + std::to_string(currency) + "\n";
    stats += "Repair Bots: " + std::to_string(repairBots) + "\n";

    return stats;

}


std::string Player::getDetailedSpaceshipStats() const
{

    std::string stats;
    stats += "Health: " + std::to_string(getHealth()) + "\n";
    stats += "Damage: " + std::to_string(getAttackPower()) + "\n";
    stats += "Attack Speed: " + std::to_string(getAttackSpeed()) + "\n";

    return stats;

    
}