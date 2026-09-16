/* Program name: Program name: Maze Solver
* Author: Chad
* Date last updated: 9/10/2026
* Purpose: Maze using linked lists. 
*/


#ifndef STACK_H
#define STACK_H

#include "node.h"
#include <stdexcept>


template <class t>
class Stack
{
private:
    Node<t> *topNode; // pointer to the top node of the stack
    int count;         // number of elements currently in the stack

public:
    Stack();  // Constructor 
    ~Stack();  // Deconsutrctor 

    void push(t data);       // Push new data. 
    t pop();                // Remove 
    t top() const;         // Check top 
    bool isEmpty() const; // Checks if stack is empty. 
    int size() const;    // Returns size of stack. 
};

// Constructor: stack starts empty
template <class t>
Stack<t>::Stack() : topNode(nullptr), count(0) {

}

// Destructor: must free every remaining node or we leak memory
template <class t>
Stack<t>::~Stack()
{
    while (!isEmpty())
    {
        pop();
    }
}

// TODO: push
// Steps:
// 1. Create a new Node<t> whose data is `data` and whose link points to
//    whatever topNode currently is (look at Node's constructor in node.h —
//    it takes (data, link) already, so this can be a one-liner).
// 2. Make topNode point to this new node.
// 3. Increment count.
template <class t>
void Stack<t>::push(t data)
{

    Node<t> *newNode = new Node<t>(data, topNode);
    
    topNode = newNode; 
    count++; 

}

template <class t>
t Stack<t>::pop()
{ 

    // Before removing anything we must first confirm that the stack is Not empty. 
   if (topNode == nullptr) { 
        throw std::runtime_error("Stack is empty"); // Throws error if it is empty. 
   }

   // Now that the stack has been confirmed to have a item we can proceeed. 

   // This makes a new variable called data which is assigned to t data type. This makes topNode point to the info that topNode has. 
   t data = topNode ->data; 

   // This creates a pointer used to point at whatever topNode is currently pointing at. 
   Node<t> *temp = topNode; 

   // We then set topNode to point at next item in the linkedlist. 
   topNode = topNode -> link; 

   // Remove the old pointer data to avoid memmory leak. 
   delete temp; 

   // Update stack size of the list. 
   count--; 

   // return the data we obtained from topNode. 
   return data; 

}

template <class t>
t Stack<t>::top() const
{

    // Checks if stack is empty. 
    if(isEmpty()) { 
        throw std::runtime_error("Stack is empty");
    }
    else { 
        return topNode->data; 
    }
}

// Checks if stack is empty. 
template <class t>
bool Stack<t>::isEmpty() const
{
return topNode == nullptr;
}

template <class t>
int Stack<t>::size() const
{
    return count; 
}

#endif