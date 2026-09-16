/* Program name: maze.h
* Author: Chad
* Date last updated: 9/10/2026
* Purpose: Maze using linked lists. 
*/


#ifndef MAZE_H
#define MAZE_H

#include <string>
#include "position.h"
#include "stack.h"

class Maze
{
private:
    char **grid;      // 2D dynamic array of maze characters
    bool **visited;   // 2D dynamic array, parallel to grid
    int numRows;
    int numCols;
    Position start;
    Position end;
    Stack<Position> solutionPath;

public:
    Maze();
    ~Maze();

    void loadMaze(const std::string &filename);
    bool solveMaze();
    void printMaze() const;
    void printSolution() const;
};

inline Maze::Maze() : grid(nullptr), visited(nullptr), numRows(0), numCols(0)
{
}

inline Maze::~Maze()
{
    for (int i = 0; i < numRows; i++)
    {
        delete[] grid[i];
    }
    delete[] grid;

    for (int i = 0; i < numRows; i++)
    {
        delete[] visited[i];
    }
    delete[] visited;
}

#endif