/**************************************************************************************************
 *                                                                                                *
 *                              LevelManager.h                                                    *
 *                                                                                                *
 *                                                                                                *
 **************************************************************************************************
 Program name: Midterm Text-Based Project.
 Author: Chad Carmickle & Christian Denning
 Date last updated: 9/11/26
 Purpose: Midterm Project.
*/

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <string> 
using std::string; 


// Creates a struct to store the stage/levels. 
struct Node { 

    string data; // Stores the infomation. 
    Node* next;  // pointer to the next node, or nullptr. 

    Node(string value); 
}; 

class LinkedList {
private:
    Node* head; // points to the first node, or nullptr if the list is empty
 
public:
    LinkedList();               // constructor declaration
   ~LinkedList();              // Destructor
    void add(string value);     // add a node to the end
    void display();             // print every node
    bool contains(string value); // search for a value
    std::string getLevelname(int stage, int level);


    std::string getAt(int stage, int level);
    std::string getAt(const std::string& code);
};

// Global helper functions
std::string getLevelname(int stage, int level);

#endif