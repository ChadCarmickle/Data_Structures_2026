/* Program name: CharacterInventory_Module1_DataStructures 
* Author: Chad Carmickle
* Date last updated: 8/27/26
* Purpose: Character and Inventory classes. 
*/

#include "character.h"
#include <ostream>
#include <sstream>

// setting a default constructor for the Character class, initializing member variables with default values
Character::Character()
    : characterName("No name assigned"),
      level(1),
      health(100),
      inventory(nullptr),
      inventorySize(0),
      inventoryCapacity(3)
{
    inventory = new Inventory[inventoryCapacity];   // allocate the initial array of size 3
}

// Parameterized constructor for the Character class, initializing member variables with provided values
Character::Character(std::string name, int characterLevel, int characterHealth)
    : characterName(name),
      level(characterLevel >= 1 ? characterLevel : 1),
      health(characterHealth >= 1 ? characterHealth : 100),
      inventory(nullptr),
      inventorySize(0),
      inventoryCapacity(3)
{
    inventory = new Inventory[inventoryCapacity];
}

Character::Character(const Character& other)
    : characterName(other.characterName),
      level(other.level),
      health(other.health),
      inventorySize(other.inventorySize),
      inventoryCapacity(other.inventoryCapacity)
{
    inventory = new Inventory[inventoryCapacity];
    for (int i = 0; i < inventorySize; ++i) {
        inventory[i] = other.inventory[i];
    }
}

// Destructor for the Character class, releasing the dynamically allocated memory for the inventory
Character::~Character()
{
    delete[] inventory;
}

// Assignment operator for the Character class, allowing assignment of one Character object to another
const Character& Character::operator=(const Character& other)
{
    if (this != &other) {
        delete[] inventory;               // free old array

        characterName     = other.characterName;
        level             = other.level;
        health            = other.health;
        inventorySize     = other.inventorySize;
        inventoryCapacity = other.inventoryCapacity;

        inventory = new Inventory[inventoryCapacity];
        for (int i = 0; i < inventorySize; ++i) {
            inventory[i] = other.inventory[i];
        }
    }
    return *this;
}


 // Getter methods for the Character class
std::string Character::getCharacterName() const { return characterName; }
int Character::getLevel() const { return level; }
int Character::getHealth() const { return health; }
int Character::getInventorySize() const { return inventorySize; }

void Character::setCharacterName(std::string name) { characterName = name; }

// Setter methods for the Character class, ensuring that level and health are set to valid values
void Character::setLevel(int characterLevel)
{
    if (characterLevel >= 1) {
        level = characterLevel;
    }
}

void Character::setHealth(int characterHealth)
{
    if (characterHealth >= 1) {
        health = characterHealth;
    }
}

// Methods for managing the inventory of the Character class, including adding and removing items, displaying the inventory, and resizing the inventory capacity
void Character::addItem(Inventory item)
{
    if (inventorySize >= inventoryCapacity) {
        resizeInventory();
    }
    inventory[inventorySize] = item;
    ++inventorySize;
}

// Remove an item from the inventory based on its index, ensuring that the index is valid
void Character::removeItem(int index)
{
    if (index < 0 || index >= inventorySize) {
        return;
    }
    for (int i = index; i < inventorySize - 1; ++i) {
        inventory[i] = inventory[i + 1];
    }
    --inventorySize;
}

// Display the inventory items of the Character class, returning a formatted string representation of the inventory
std::string Character::displayInventory() const
{
    std::ostringstream output;
    output << "Inventory:\n";
    for (int i = 0; i < inventorySize; ++i) {
        output << inventory[i].getItemName() << "\n";
    }
    return output.str();
}

// Resize the inventory capacity by doubling it | Assignment requirement. 
void Character::resizeInventory()
{
    int newCapacity = inventoryCapacity * 2;
    Inventory* newInventory = new Inventory[newCapacity];

    for (int i = 0; i < inventorySize; ++i) {
        newInventory[i] = inventory[i];
    }

    delete[] inventory;
    inventory = newInventory;
    inventoryCapacity = newCapacity;
}

// Overloaded output stream operator for the Character class
std::ostream& operator<<(std::ostream& outputStream,
                         const Character& characterToPrint)
{
    outputStream << "Character information\n" 
                 << "Character Name: " << characterToPrint.characterName << '\n'
                 << "Level: " << characterToPrint.level << '\n'
                 << "Health: " << characterToPrint.health << '\n'
                 << characterToPrint.displayInventory();
    return outputStream;
}