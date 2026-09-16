#ifndef UNORDERED_H
#define UNORDERED_H
#include <stdexcept>
#include "linkedList.h"

template <class t>
class UnorderedLinkedList : public LinkedList<t>
{
public:
    enum class directionType
    {
        FORWARD,
        BACKWARD
    };
    UnorderedLinkedList(directionType = directionType::FORWARD);
    void insert(const t &newData);
    void deleteNode(const t &deleteItem);
    bool search(const t &searchItem);


    // Need to add the MergeSort Function. 
    // MergeSort will accept a function that takes two objects by references. 
    void MergeSort(int (*func)(t &, t &)); 



private:
    directionType direction;
    void insertFirst(Node<t> *newNode);
    void insertLast(Node<t> *newNode);

    /* 
        These will be tools that mergeSort will have access to. Using recursive functions. 
    SplitList -> Splits one list into two. 
    mergeList -> combine the two sorted lists. 
    mergeSortRecursive -> repeatedly split and merge. 
    
    */
    void splitList(Node<t> *source, Node<t> *&front, Node<t> *&back);
    Node<t> *mergeLists(Node<t> *front, Node<t> *back, int (*func)(t &, t &));
    Node<t> *mergeSortRecursive(Node<t> *head, int (*func)(t &, t &));
};

#endif


template <class t> 
inline void UnorderedLinkedList<t>::splitList(

    Node<t> *source, 
    Node<t> *&front, 
    Node<t> *&back) 
{ 
    Node<t> *slow; // This will move one node at a time. 
    Node<t> *fast; // This will move two node at a time. 
    // Because mergeList has issues finding the "middle" of an of a data structure. We use two pointers to locate that middle. 
    /* 
    Why do we do this: 
        Because mergeSort doesnt have a good method to find the middle of a collection of data, using slow lets us count by 1. 
        While fast lets us count by 2. This way when we reach the end of the list using fast the slow node is usally in the "middle-ish" 
        of the data. This lets us reliablily find the middle. 
    
    */

    // This assigns the starting points for the two pointers. 
    slow = source; 
    fast = source->link; 

    // Make a loop to repeat this action until fast is at the end of the list. 
    while (fast != nullptr) { 
        fast = fast->link; 

        if (fast != nullptr) { 
            slow = slow->link; 
            fast = fast->link; 
        }
    }

    // Once the fast has located the end of the data, slow is near the center. 
    // this points to the first half of the list. 
    front = source; 

    // This is pointing to the last node of the first half
    back = slow->link; 

    // This is pointing to the first node, of the second half of the data. 
    slow->link = nullptr; 

}



template <class t>
inline Node<t> *UnorderedLinkedList<t>::mergeLists(
    Node<t> *front,
    Node<t> *back,
    int (*func)(t &, t &))
{
      Node<t> *result;
      Node<t> *current;

    // Checks if the two lists are empty. 
    if (front == nullptr) { 
        return back; 
    }

    if (back == nullptr) { 
        return front; 
    }

    // Takes the two sorted lists compares their items and builds one sorted list of them. 
    if (func(front->data, back->data) <= 0)
    {
        // Sets the result to front we find. 
        result = front;

        // We then need to move "front" to the next node. 
        front = front->link; 
    }

    else { 
        // if 'front' does not come first we need back to come first then. 
        result = back; 

        // If front does not come first move the back pointer to the next node. 
        back = back->link;
    }
    // We Need a second pointer to keep track of while result is being used. We set it equal to it here. 
    current = result; 


    // Loops the front and back nodes. 
    while (front != nullptr && back != nullptr)
    {
        // If we find one: 
        if (func(front->data, back->data) <= 0)
        {
            // current is equal to front of the data list. 
            current->link = front;
            // Mode the node forward. 
            front = front->link;
            current = current->link;
        }
        else
        {
            // We cannot add front then add back instead. 
            // Move the node forward. 
            current->link = back; 
            back = back->link;
            current = current->link;
        }
    }

    // Attach any remaining nodes. 
    if (front != nullptr) { 
        current-> link = front; 
    }
    else { 
        current->link = back; 
    }
    return result; 


}





template <class t>
inline Node<t> *UnorderedLinkedList<t>::mergeSortRecursive(
    Node<t> *head,
    int (*func)(t &, t &))
{

    // Checks if the head is null or head's next pointer. 
    if (head == nullptr || head->link == nullptr)
    {
        return head;
    }

    // If not create two new nodes front and back. 
    Node<t> *front;
    Node<t> *back;

    // runs the function splitList to split up the list. 
    splitList(head, front, back);


    // We then merge the front and back. 
    front = mergeSortRecursive(front, func);
    back = mergeSortRecursive(back, func);
    


    // Merge the two sorted halves and return the beginning.
    return mergeLists(front, back, func);

}

template <class t>
inline void UnorderedLinkedList<t>::MergeSort(int (*func)(t &, t &))
{
    // Recives a function pointer, the function pointer then takes two 't' references and returns an int to them.
    this->head = mergeSortRecursive(this->head, func);

    // Mkaes tail point to the node head is now pointing at.
    this->tail = this->head;

    // Moves the tail to the end.
    while (this->tail != nullptr && this->tail->link != nullptr)
    {
        this->tail = this->tail->link;
    }
}


template <class t>
inline UnorderedLinkedList<t>::UnorderedLinkedList(directionType d) : direction(d)
{
}





template <class t>
inline void UnorderedLinkedList<t>::insert(const t &newData)
{
    Node<t> *newNode;
    newNode = new Node(newData);
    if (this->isEmptyList())
    {
        this->head = newNode;
        this->tail = newNode;
    }
    else if (direction == directionType::FORWARD)
    {
        insertLast(newNode);
    }
    else
    {
        insertFirst(newNode);
    }
    this->count++;
}

template <class t>
inline void UnorderedLinkedList<t>::deleteNode(const t &deleteItem)
{
    Node<t> *current;
    Node<t> *trailCurrent; // one behind current in the list
    bool found;
    if (this->isEmptyList())
    {
        throw std::out_of_range("Cannot delete from an empty list.");
    }
    if (this->head->data == deleteItem)
    {
        current = this->head;
        this->head = this->head->link; // move head node forward
        if (this->head == nullptr)
        {
            this->tail = nullptr;
        }
    }
    else
    {
        found = false;
        trailCurrent = this->head;
        current = this->head->link;
        while (current != nullptr && !found)
        {
            if (current->data != deleteItem)
            {
                trailCurrent = current;  // move the pointer trailing current ahead by 1
                current = current->link; // move current ahead by 1
            }
            else
            {
                found = true;
            }
        }
        if (found)
        {
            trailCurrent->link = current->link; // remove current from the navigation
            if (this->tail == current)
            {
                this->tail = trailCurrent;
            }
        }
        else
        {
            throw std::out_of_range("Item to be deleted is not found in the list");
        }
    }
    delete current;
    this->count--;
}

template <class t>
inline bool UnorderedLinkedList<t>::search(const t &searchItem)
{
    Node<t> *current;
    bool found = false;
    current = this->head;
    while (current != nullptr && !found)
    {
        if (current->data == searchItem)
        {
            found = true;
        }
        else
        {
            current = current->link;
        }
    }
    return found;
}

template <class t>
inline void UnorderedLinkedList<t>::insertFirst(Node<t> *newNode)
{
    newNode->link = this->head; // put new item on front of list
    this->head = newNode;       // moves the head to the new first node
}

template <class t>
inline void UnorderedLinkedList<t>::insertLast(Node<t> *newNode)
{
    this->tail->link = newNode; // put the new item on teh end of the list
    this->tail = newNode;       // move tail to the new last node
}