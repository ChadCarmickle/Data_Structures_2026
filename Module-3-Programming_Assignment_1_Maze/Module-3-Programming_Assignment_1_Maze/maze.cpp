/* Program name: maze.cpp
* Author: Chad
* Date last updated: 9/10/2026
* Purpose: Maze using linked lists. 
*/
#include "maze.h"
#include <fstream>
#include <iostream>
#include <vector>

void Maze::loadMaze(const std::string &filename)
{
    std::ifstream infile(filename);
    if (!infile)
    {
        std::cerr << "Could not open maze file: " << filename << std::endl;
        return;
    }

    infile >> numRows >> numCols;
    infile.ignore();

    grid = new char *[numRows];
    for (int i = 0; i < numRows; i++)
        grid[i] = new char[numCols];

    visited = new bool *[numRows];
    for (int i = 0; i < numRows; i++)
    {
        visited[i] = new bool[numCols];
        for (int j = 0; j < numCols; j++)
            visited[i][j] = false;
    }

    for (int i = 0; i < numRows; i++)
    {
        std::string line;
        std::getline(infile, line);

        for (int j = 0; j < numCols; j++)
        {
            char c = (j < (int)line.size()) ? line[j] : ' ';
            grid[i][j] = c;

            if (c == 'S') { start.row = i; start.col = j; }
            else if (c == 'E') { end.row = i; end.col = j; }
        }
    }

    infile.close();
}

bool Maze::solveMaze()
{
    if (grid == nullptr) return false;

    const int dRow[4] = {-1, 1, 0, 0};
    const int dCol[4] = {0, 0, -1, 1};

    solutionPath.push(start);
    visited[start.row][start.col] = true;

    while (!solutionPath.isEmpty())
    {
        Position current = solutionPath.top();

        if (current == end) return true;

        bool moved = false;
        for (int dir = 0; dir < 4; dir++)
        {
            int newRow = current.row + dRow[dir];
            int newCol = current.col + dCol[dir];

            if (newRow < 0 || newRow >= numRows || newCol < 0 || newCol >= numCols) continue;
            if (grid[newRow][newCol] == '#') continue;
            if (visited[newRow][newCol]) continue;

            Position next{newRow, newCol};
            solutionPath.push(next);
            visited[newRow][newCol] = true;
            moved = true;
            break;
        }

        if (!moved) solutionPath.pop(); // dead end, backtrack
    }

    return false;
}

void Maze::printMaze() const
{
    for (int i = 0; i < numRows; i++)
    {
        for (int j = 0; j < numCols; j++)
            std::cout << grid[i][j];
        std::cout << std::endl;
    }
}

void Maze::printSolution() const
{
    if (solutionPath.isEmpty())
    {
        std::cout << "No solution found." << std::endl;
        return;
    }

    char **display = new char *[numRows];
    for (int i = 0; i < numRows; i++)
    {
        display[i] = new char[numCols];
        for (int j = 0; j < numCols; j++)
            display[i][j] = grid[i][j];
    }

    Stack<Position> &path = const_cast<Stack<Position> &>(solutionPath);

    std::vector<Position> temp;
    while (!path.isEmpty())
    {
        Position p = path.pop();
        temp.push_back(p);
        if (display[p.row][p.col] == ' ')
            display[p.row][p.col] = '.';
    }

    for (int i = (int)temp.size() - 1; i >= 0; i--)
        path.push(temp[i]);

    for (int i = 0; i < numRows; i++)
    {
        for (int j = 0; j < numCols; j++)
            std::cout << display[i][j];
        std::cout << std::endl;
    }

    for (int i = 0; i < numRows; i++)
        delete[] display[i];
    delete[] display;
}