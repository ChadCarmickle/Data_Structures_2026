#ifndef OLLIST_H
#define OLLIST_H

#include "linkedList.h" 

// Creating a template under a class t. 
template <class t> 

// This is the class we will be using and working with. 
class OrderedLinkedList : public LinkedList<t> { 


// The methods used are listed below. 
// Insert will insert new data, DeleteNode will remove a linked list entry and search will filter and search for a specific item. 
public:
    void insert(const t &newInfo);
    void deleteNode(const t &deleteItem);
    bool search(const t &searchItem) const;

}; 

// Insert new data. 
template <class t>
void OrderedLinkedList<t>::insert(const t &newInfo) {

/* 
First we delcare three new nodes. 
newnode will create a new node using new infomation given. 
Current records what the current item we are looking at in the node. 
Because this is a ordered and not doubly linked list we use a trailer to trace behind the current to keep track of it. 
*/
Node<t> *newnode = new Node<t>(newInfo);
Node<t> *current = this->head;
Node<t> *trailer = nullptr;


// Before we place data we check if the head node has any pointers it is linking too. 
if(this->head == nullptr) { 
	// If so we declare a new head and tail. 
	this->head = newnode; 
	this->tail = newnode; 

	// Increase the count to tell the class increase size +1. 
	this->count++; 
	return; 
}

// Next we check if the data we are added is less than what head is currently seeing. 
// This allows us to "order" the data in a sense. 
if (newInfo < this->head->data) { 
	// If the data is less than what head is pointing too 
	// Then we point a newnode to the next entry and equal that to head. 
	newnode ->link = this->head; 
	this-> head = newnode; 
	this-> count++; 
	return; 
}

// Here we create a look to check if the current pointer is Not null and the current data is less than our new entry. 
while (current != nullptr && current->data < newInfo) {
	//If true we set trailer to the current and current to current's link pointer. 
		trailer = current;
		current = current->link;
		// this will repeat until the whole list is checked. 
	}

	// We then declare a new node to link to current in the list 
	// We move trailer to the next entry over. 
	newnode->link = current;
	trailer->link = newnode;

	// This checks if current is a nullptr meaning its at the end of the list. 
	if (current == nullptr) {
		// If it is we set tail to a newnode. 
		this->tail = newnode;
	}
	// Because we had a new node we increase the count. 
	this->count++;
}

// Delete old data. 
template <class t>
void OrderedLinkedList<t>::deleteNode(const t &deleteItem) {

	// Check if node is empty. 
	if(this->head == nullptr ) { 
		return; 
	}
	
	// checks if head data is equal to what is being deleted. 
	if(this->head->data == deleteItem) { 
		Node<t> *temp = this->head; // temp value to store the node. 
		this->head = this->head->link; // Link head to new link. 
		delete temp; // Delete temp. 
		this->count--; // Decrease counter. 

		if (this->head == nullptr) {
			this->tail = nullptr;
		}
		return;
	}

	Node<t> *trailer = this->head;
	Node<t> *current = this->head->link;

	while (current != nullptr && current->data != deleteItem) {
		trailer = current;
		current = current->link;
	}

	if (current == nullptr) {
		return;
	}

	trailer->link = current->link;

	if (current == this->tail) {
		this->tail = trailer;
	}

	delete current;
	this->count--;
}

// Saearch the orderedlist for matches. 
template <class t>
bool OrderedLinkedList<t>::search(const t &searchItem) const {

Node<t> *current = this->head;

while (current != nullptr) {
    if (current->data == searchItem) {
        return true;
    }
    if (current->data > searchItem) {
        return false;   
    }
    current = current->link;
}

return false;


}
			
#endif