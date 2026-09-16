/* Program name: CharacterInventory_Module1_DataStructures 
* Author: Chad Carmickle
* Date last updated: 8/27/26
* Purpose: Character and Inventory classes. 
*/
#ifndef INVENTORY_H
#define INVENTORY_H

#include <string>

// Inventory class definition 
/* 
Purpose: The Inventory class represents an item in a character's inventory, encapsulating the item's name, rarity, and value. It provides constructors for creating inventory items, as well as getter and setter methods for accessing and modifying the item's attributes. The class ensures that the value of the item is non-negative through validation in the constructor and setter method.
*/

class Inventory {
private:
	std::string itemName;
	std::string rarity;
	int value;

public:
	Inventory();
	Inventory(std::string name, std::string rarity, int value);

	std::string getItemName() const;
	std::string getRarity() const;
	int getValue() const;

	void setItemName(std::string name);
	void setRarity(std::string rarity);
	void setValue(int value);
};

#endif