/* Program name: main.cpp
* Author: Chad Carmickle 
* Date last updated: 9/4/2026
* Purpose: Programming Assignment 2. Module 2 
*/



#include <iostream>
#include <string>
#include "orderedLinkedList.h"
#include "person.h"

using std::string;
using std::cin;
using std::cout;

int main() {

    // Create a ordered list object. 
    OrderedLinkedList<Person> list;

    // Create a loop for 5 objects. 
    for (int i = 0; i < 5; i++) {

        // Define name and age for a Person Object. 
        string name;
        int age;

        // Collect the data. 
        if (!(cin >> name >> age)) {
            break;
        }

        // Insert person as new person with name and age. 
        Person newPerson(name, age);
        // Call list.insert to place them into the object. 
        list.insert(newPerson);
    }

    // Display results. 
    cout << "Ordered list of people (by age):" << std::endl;
    list.print(cout, "\n");

    return 0;
}