/* Program name: jbtictactoe.cpp
* Author: Chad
* Date last updated: 9/10/2026
* Purpose: Maze using linked lists. 
*/
#ifndef NODE_H
#define NODE_H

template <class t>
struct Node
{
    t data;
    Node<t> *link;

    Node(t data, Node<t> *link = nullptr);
};

template <class t>
Node<t>::Node(t d, Node<t> *link) : data(d)
{
    this->link = link;
}
#endif