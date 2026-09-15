
/*
 * Program name: Sudoku.h
 * Author: Chad Carmickle
 * Date last updated: 9/15/2026
 * Purpose: Defines the Sudoku class used to load, display, validate,
 *          and solve a 9x9 Sudoku puzzle.

                                    ******************************************************
                                    *       Module 4 Programming Assignment 1            *
                                    ******************************************************
    You will create a class Sudoku that will hold a 9x9 Sudoku grid. You will have a function loadGrid that reads the starting grid from sudoku.txt. 
The unknown values will be filled in with 0. You will also have a function solveGrid, that uses backtracking and recursion to solve the Sudoku grid.
Backtracking means you place digits until you encounter a conflict, then you backtrack to try a different value. 
There will also be an override for the output operator.

For the main program create a sudoku object, load the grid, and print the starting state.
Then invoke the solveGrid function and print the final solved state of the grid.
If the grid cannot be solved, display "No solution exists for the given Sudoku."


      classroom50 autograde: 8/8
Test	                Result	Score
Compile Test	        PASS	1 / 1
Heading Test	        PASS	1 / 1
Comment Test	        PASS	1 / 1
Valgrind	            PASS	1 / 1
Functionality Test 1	PASS	1 / 1
Functionality Test 2	PASS	1 / 1
Functionality Test 3	PASS	1 / 1
Functionality Test 4	PASS	1 / 1
Status: classroom50 autograde: 8/8 (all tests passed)

*/

#include <iostream>
#include "sudoku.h"

int main()
{
    Sudoku grid;

    if (!grid.loadGrid("sudoku.txt"))
    {
        std::cout << "Failed to load Sudoku grid.\n";
        return 1;
    }

    std::cout << grid;

    // Checks if the grid can be solved. 
    if (grid.solveGrid())
    {
        // Solution found. 
        std::cout << "Solved Sudoku:\n"; 
        std::cout << grid;
    }
    else
    {
        // No solution can be found. 
        std::cout << "No solution exists for the given Sudoku.\n";
    }

    return 0;
}