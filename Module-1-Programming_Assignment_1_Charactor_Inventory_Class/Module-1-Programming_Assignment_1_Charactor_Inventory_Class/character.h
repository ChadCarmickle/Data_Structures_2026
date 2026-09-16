/* Program name: CharacterInventory_Module1_DataStructures 
* Author: Chad Carmickle
* Date last updated: 8/27/26
* Purpose: Character and Inventory classes. 
*/

#ifndef CHARACTER_H
#define CHARACTER_H

#include <iosfwd>
#include <string>
#include "inventory.h"

// Character class definition
/* 
Purpose : The Character class represents a character in a game, encapsulating the character's name, level, health, and inventory. It provides constructors for creating characters, as well as getter and setter methods for accessing and modifying the character's attributes. The class also includes methods for managing the character's inventory, such as adding and removing items, displaying the inventory, and resizing the inventory capacity.
*/
class Character {
private:
	std::string characterName;
	int level;
	int health;
	Inventory* inventory;
	int inventorySize;
	int inventoryCapacity;

public:
// Constructors, destructor, and assignment operator
	Character();
	Character(std::string name, int level, int health);
	Character(const Character& other);
	~Character();
	const Character& operator=(const Character& other);

	std::string getCharacterName() const;
	int getLevel() const;
	int getHealth() const;
	int getInventorySize() const;

	void setCharacterName(std::string name);
	void setLevel(int level);
	void setHealth(int health);

	void addItem(Inventory item);
	void removeItem(int index);
	std::string displayInventory() const;
	void resizeInventory();

	// Friend is a c++ only keyword allowing a function to access private members of a class. In this case, the overloaded output stream operator is declared as a friend of the Character class, allowing it to access private members for printing character information.
	// Overloaded output stream operator for printing character information
	friend std::ostream& operator<<(std::ostream& outputStream,
									const Character& characterToPrint);
};

#endif