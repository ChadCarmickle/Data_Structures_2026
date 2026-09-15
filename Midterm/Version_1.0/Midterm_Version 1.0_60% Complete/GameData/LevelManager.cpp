/**************************************************************************************************
 *                                                                                                *
 *                              LevelManager.cpp                                                  *
 *                                                                                                *
 *                                                                                                *
 **************************************************************************************************
 Program name: Midterm Text-Based Project.
 Author: Chad Carmickle & Christian Denning
 Date last updated: 9/11/26
 Purpose: Midterm Project.
*/
#include "LevelManager.h"
#include <iostream>
using namespace std;


LinkedList locations;
Node::Node(string value) : data(value), next(nullptr) {}

// ============================================================
// LinkedList constructor
// ============================================================
LinkedList::LinkedList() : head(nullptr) {}


// ============================================================
// LinkedList destructor
// ============================================================
LinkedList::~LinkedList()
{
    Node* current = head;

    while (current != nullptr)
    {
        Node* next = current->next;
        delete current;
        current = next;
    }

    head = nullptr;
}


// Adds a new node to the END of the list.
void LinkedList::add(string value) {
    Node* newNode = new Node(value);

    // Case 1: list is empty, so the new node becomes the head
    if (head == nullptr) {
        head = newNode;
        return;
    }

    // Case 2: list already has nodes, walk to the last one
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next; // move forward one node at a time
    }
    temp->next = newNode; // attach the new node after the last one
}

// Walks the whole list from head to tail, printing each node.
void LinkedList::display() {
    Node* temp = head;

    int stage = 1;
    int level = 1;

    while (temp != nullptr && stage <= 6) {
        cout << stage << "." << level << ": "
             << temp->data << endl;

        temp = temp->next;

        if (level == 4) {
            cout << endl;  // Blank line after .4

            level = 1;
            stage++;
        } else {
            level++;
        }
    }
}


// Returns true if a value exists anywhere in the list.
bool LinkedList::contains(string value) {
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->data == value) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

std::string LinkedList::getAt(int stage, int level) {
    if (stage < 1 || level < 1) return "";

    // Each stage has 4 locations (except the very end)
    // Stage 1 → positions 1-4
    // Stage 2 → positions 5-8
    // Stage 3 → positions 9-12
    // Stage 4 → positions 13-16
    // Stage 5 → positions 17-19 (+ optional shop at 20)

    int position = (stage - 1) * 4 + level;

    // Safety: don't go past the end of the list
    Node* temp = head;
    int current = 1;

    while (temp != nullptr) {
        if (current == position) {
            return temp->data;
        }
        temp = temp->next;
        current++;
    }
    return "";   // not found
}

// Optional helper so you can write getAt("2.4")
std::string LinkedList::getAt(const std::string& code) {
    size_t dot = code.find('.');
    if (dot == std::string::npos) return "";

    int stage = std::stoi(code.substr(0, dot));
    int level = std::stoi(code.substr(dot + 1));
    return getAt(stage, level);
}

std::string getLevelname(int stage, int level) {
    return locations.getAt(stage, level);
}
