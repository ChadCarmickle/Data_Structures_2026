/* Program name: jbtictactoe.cpp
* Author: Chad
* Date last updated: 9/10/2026
* Purpose: Maze using linked lists. 
* Already submited but submitting again in-case. 
*/

#include <iostream>
#include "maze.h"

int main()
{
    Maze maze; // Load maze, 
    maze.loadMaze("maze.txt"); // Loads the file 

    maze.printMaze(); // Prints maze. 

    std::cout << "\n";

    // If Solution print.  
    if (maze.solveMaze())
    {
        maze.printSolution();
    }

    return 0;
}