/*
 * Program name: Sudoku.h
 * Author: Chad Carmickle
 * Date last updated: 9/15/2026
 * Purpose: Defines the Sudoku class used to load, display, validate,
 *          and solve a 9x9 Sudoku puzzle.
 */
#ifndef SUDOKU_H
#define SUDOKU_H

// Class used for display and strings. 
#include <iostream>
#include <string>


class Sudoku
{
private:
    // creates a 9x9 grid. 
    int grid[9][9];

    // Function made to check each row, col or 3x3 box of it. 
    // Future improvement is to combine these 3, for testing / debugging I made them seperate. 
    // This philosophy is followed by the Clean Code book where each function Only does one task. 
    bool isValidRow(int row, int num);
    bool isValidColumn(int col, int num);
    bool isValidBox(int row, int col, int num);

public:
    // Class constructor. 
    Sudoku();

    // Retruns bool is grid is loaded from file. 
    bool loadGrid(const std::string& filename);

    // Checks if entry of number into a empty slot (0) is valid. 
    bool isValid(int row, int col, int num);

    // checks if grid was solved. 
    bool solveGrid();

    // Output. 
    friend std::ostream& operator<<(std::ostream& out, const Sudoku& sudoku);
};

#endif
