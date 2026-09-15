/*
 * Program name: Sudoku.h
 * Author: Chad Carmickle
 * Date last updated: 9/15/2026
 * Purpose: Defines the Sudoku class used to load, display, validate,
 *          and solve a 9x9 Sudoku puzzle.
 */

#include "sudoku.h"
#include <fstream>

// Class Constructor
// Two loops ( Outer loops handles the row, the inner loop handles the column, It populates each one with a 0 to construct the grid.)
Sudoku::Sudoku()
{

    for (int row = 0; row < 9; row++)
    {
        for (int col = 0; col < 9; col++)
        {
            grid[row][col] = 0;
        }
    }
};


// Loads the grid using double loops. 
bool Sudoku::loadGrid(const std::string& filename)
{
    std::ifstream file(filename);

    if (!file)
    {
        return false;
    }

    for (int row = 0; row < 9; row++)
    {
        for (int col = 0; col < 9; col++)
        {
            if (!(file >> grid[row][col]))
            {
                return false;
            }
        }
    }

    file.close();

    return true;
}

// Checks if a Row is a valid #. 
bool Sudoku::isValidRow(int row, int num)
{
    for (int col = 0; col < 9; col++)
    {
        if (grid[row][col] == num)
        {
            return false;
        }
    }

    return true;
}

// Checks if Column is a valid #. 
bool Sudoku::isValidColumn(int col, int num)
{
    for (int row = 0; row < 9; row++)
    {
        if (grid[row][col] == num)
        {
            return false;
        }
    }

    return true;
}

// Checks the 3x3 area around the number. 
bool Sudoku::isValidBox(int row, int col, int num)
{
    // We create a starting row and column to compare using row divided by 3 then * 3. 
    //Example: [4][7] 
    // The box starts at row: 3, Column 6. We then check: the numbers near by this. 
/* Example 3x3 Nearby 4,7. 
    (3,6) (3,7) (3,8)
    (4,6) (4,7) (4,8)
    (5,6) (5,7) (5,8)  
*/

    int startingRow = (row / 3) * 3;
    int startingColumn = (col / 3) * 3;

    for (int currentRow = startingRow; currentRow < startingRow + 3; currentRow++)
    {
        for (int currentColumn = startingColumn; currentColumn < startingColumn + 3; currentColumn++)
        {
            if (grid[currentRow][currentColumn] == num)
            {
                return false;
            }
        }
    }

    return true;
}

// Function that checks the other three prior functions made. 
bool Sudoku::isValid(int row, int col, int num)
{
    return isValidRow(row, num)
        && isValidColumn(col, num)
        && isValidBox(row, col, num);
}

// A loop > Loop > Logic check > Loop > Logic check > Logic check 
// Attempts to solve the grid. 
bool Sudoku::solveGrid()
{
    // Check each row.
    for (int row = 0; row < 9; row++)
    {
        // Check each column.
        for (int col = 0; col < 9; col++)
        {
            // Look for an empty cell.
            if (grid[row][col] == 0)
            {
                // Try numbers 1 through 9.
                for (int num = 1; num <= 9; num++)
                {
                    // Check if the number is valid.
                    if (isValid(row, col, num))
                    {
                        // Temporarily place the number.
                        grid[row][col] = num;

                        // Recursively try to solve the rest of the grid.
                        if (solveGrid())
                        {
                            return true;
                        }

                        // The choice did not work, so undo it.
                        grid[row][col] = 0;
                    }
                }

                // No number from 1-9 worked for this empty cell.
                return false;
            }
        }
    }

    // No empty cells remain, so the Sudoku is solved.
    return true;
}

// Displays the table correctly according to project example. 
std::ostream& operator<<(std::ostream& out, const Sudoku& sudoku)
{
    out << "+-----------+-----------+-----------+\n";

    for (int row = 0; row < 9; row++)
    {
        out << "| ";

        for (int col = 0; col < 9; col++)
        {
            out << sudoku.grid[row][col];

            if (col == 2 || col == 5)
            {
                out << " | ";
            }
            else if (col == 8)
            {
                out << " ";
            }
            else
            {
                out << "   ";
            }
        }

        out << "|\n";

        if (row == 2 || row == 5 || row == 8)
        {
            out << "+-----------+-----------+-----------+\n";
        }
    }

    return out;
}