/* Program name: CharacterInventory_Module1_DataStructures 
* Author: Chad Carmickle
* Date last updated: 8/27/26
* Purpose: Character and Inventory classes. 
*/

#include "inventory.h"

// setting a default constructor for the Inventory class, initializing member variables with default values
Inventory::Inventory() : itemName(""), rarity(""), value(0) {}

Inventory::Inventory(std::string name, std::string itemRarity, int itemValue)
	: itemName(name), rarity(itemRarity), value(itemValue >= 0 ? itemValue : 0) {}


// Getter and setter methods for the Inventory class
std::string Inventory::getItemName() const
{
	return itemName;
}

std::string Inventory::getRarity() const
{
	return rarity;
}

int Inventory::getValue() const
{
	return value;
}

void Inventory::setItemName(std::string name)
{
	itemName = name;
}

void Inventory::setRarity(std::string itemRarity)
{
	rarity = itemRarity;
}

void Inventory::setValue(int itemValue)
{
	if (itemValue >= 0) {
		value = itemValue;
	}
}