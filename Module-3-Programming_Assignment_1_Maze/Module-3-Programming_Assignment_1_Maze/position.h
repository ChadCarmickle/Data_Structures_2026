/* Program name: jbtictactoe.cpp
* Author: Chad
* Date last updated: 9/10/2026
* Purpose: Maze using linked lists. 
*/
#ifndef POS_H
#define POS_H
struct Position
{
    int row;
    int col;
    bool operator==(Position oth) const { return row == oth.row && col == oth.col; };
    bool operator!=(Position oth) const { return !(*this == oth); };
};
#endif