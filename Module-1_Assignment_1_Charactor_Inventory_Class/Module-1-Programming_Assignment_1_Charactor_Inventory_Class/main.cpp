/* Program name: CharacterInventory_Module1_DataStructures 
* Author: Chad Carmickle
* Date last updated: 8/27/26
* Purpose: Character and Inventory classes. 

Program complete: 
classroom50 autograde: 6/8
Test	            Result	Score
setup	            PASS	0 / 0
Compile	            PASS	1 / 1
PyTest Unit Test	FAIL	0 / 2 -Advised this will change during grading. 
Comment test	    PASS	1 / 1
Heading Test	    PASS	1 / 1
IO Test 1	        PASS	1 / 1
Error Test	        PASS	1 / 1
Valgrind	        PASS	1 / 1
*/

#include "character.h"
#include <iostream>
#include <limits>

// Function to read a positive number from user input
bool readPositiveNumber(const char* prompt, int& value)
{
    while (true) {
        std::cout << prompt;
        if (std::cin >> value && value > 0) {
            return true;
        }
        if (std::cin.eof()) {
            return false;
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Input Error: Please enter a number greater than 0\n";
    }
}

// Main function to create a character and manage its inventory
int main()
{
    std::string name;
    int level;
    int health;

    std::cout << "Create a character\n";
    std::cout << "Character name: ";
    std::getline(std::cin >> std::ws, name);
    if (!readPositiveNumber("Level: ", level) ||
        !readPositiveNumber("Health: ", health)) {
        return 0;
    }

    Character myCharacter(name, level, health);

    char choice;
    do {
        std::string itemName;
        std::string rarity;
        int value;

        std::cout << "Add an inventory item\n";
        std::cout << "Item name: ";
        std::getline(std::cin >> std::ws, itemName);
        std::cout << "Rarity: ";
        std::getline(std::cin >> std::ws, rarity);
        if (!readPositiveNumber("Value: ", value)) {
            return 0;
        }
        myCharacter.addItem(Inventory(itemName, rarity, value));

        std::cout << "Add another item? (y/n): ";
        std::cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    std::cout << myCharacter;

    return 0;

}