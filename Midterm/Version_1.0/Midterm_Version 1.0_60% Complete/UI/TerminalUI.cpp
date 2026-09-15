/**************************************************************************************************
 *                                                                                                *
 *                                    TerminalUI.cpp                                              *
 *                                                                                                *
 *                          Handles the game's terminal user interface                           *
 **************************************************************************************************
 Program name: Midterm Text-Based Project.
 Author: Chad Carmickle & Christian Denning
 Date last updated: 9/11/26
 Purpose: Handles dialogue boxes and terminal-based UI.
*/

#include "TerminalUI.h"

#include <iostream>
#include <limits>
#include <algorithm>
#include <sstream>
#include <vector>
#include <string>


// ================================================================================================
//                                    UI CONSTANTS
// ================================================================================================

const int BOX_WIDTH = 80;
const int MAX_DIALOGUE_LINES = 4;

// The dialogue has:
// 1 character for the left border
// 2 characters for indentation
// 1 character for the right border
//
// 80 - 1 - 2 - 1 = 76 characters available for dialogue text.
const int CONTENT_WIDTH = BOX_WIDTH - 4;


// ================================================================================================
//                                    WORD WRAPPING
// ================================================================================================

std::vector<std::string> wrapText(
    const std::string& text,
    int maxWidth
)
{
    std::vector<std::string> wrappedLines;

    std::istringstream words(text);

    std::string word;
    std::string currentLine;


    while (words >> word)
    {
        // If this is the first word on the line,
        // simply add it.
        if (currentLine.empty())
        {
            currentLine = word;
        }

        // Check if adding the next word would still
        // fit inside the dialogue box.
        else if (currentLine.length() + 1 + word.length() <= maxWidth)
        {
            currentLine += " " + word;
        }

        // The word would make the line too long.
        // Store the current line and start a new one.
        else
        {
            wrappedLines.push_back(currentLine);

            currentLine = word;
        }
    }


    // Add the final line.
    if (!currentLine.empty())
    {
        wrappedLines.push_back(currentLine);
    }


    // If an empty string was passed in,
    // preserve it as an empty dialogue line.
    if (wrappedLines.empty())
    {
        wrappedLines.push_back("");
    }


    return wrappedLines;
}


// ================================================================================================
//                                    SHOW DIALOGUE
// ================================================================================================

void showDialogue(
    const std::string& speaker,
    const std::vector<std::string>& lines,
    const std::string& title
)
{
    // --------------------------------------------------------------------------------------------
    // Convert all dialogue into physical display lines.
    //
    // Example:
    //
    // "This is a very long sentence that does not fit..."
    //
    // becomes:
    //
    // "This is a very long sentence that does not"
    // "fit..."
    //
    // This prevents text from being cut off by the box.
    // --------------------------------------------------------------------------------------------

    std::vector<std::string> wrappedLines;


    for (const std::string& line : lines)
    {
        std::vector<std::string> pieces =
            wrapText(line, CONTENT_WIDTH);

        wrappedLines.insert(
            wrappedLines.end(),
            pieces.begin(),
            pieces.end()
        );
    }


    // --------------------------------------------------------------------------------------------
    // Display the dialogue four physical lines at a time.
    // --------------------------------------------------------------------------------------------

    for (
        size_t start = 0;
        start < wrappedLines.size();
        start += MAX_DIALOGUE_LINES
    )
    {
        size_t end = std::min(
            start + MAX_DIALOGUE_LINES,
            wrappedLines.size()
        );


        // ========================================================================================
        //                                      TOP BORDER
        // ========================================================================================

        std::cout << "╔";

        for (int i = 0; i < BOX_WIDTH - 2; i++)
        {
            std::cout << "═";
        }

        std::cout << "╗\n";


        // ========================================================================================
        //                                      TITLE
        // ========================================================================================

        std::cout << "║";

        int leftPadding =
            (BOX_WIDTH - 2 - static_cast<int>(title.length())) / 2;

        for (int i = 0; i < leftPadding; i++)
        {
            std::cout << " ";
        }

        std::cout << title;

        for (
            int i = leftPadding + static_cast<int>(title.length());
            i < BOX_WIDTH - 2;
            i++
        )
        {
            std::cout << " ";
        }

        std::cout << "║\n";


        // ========================================================================================
        //                                      DIVIDER
        // ========================================================================================

        std::cout << "╠";

        for (int i = 0; i < BOX_WIDTH - 2; i++)
        {
            std::cout << "═";
        }

        std::cout << "╣\n";


        // ========================================================================================
        //                                      SPEAKER
        // ========================================================================================

        std::string speakerText = "  " + speaker;


        std::cout << "║";


        for (int i = 0; i < BOX_WIDTH - 2; i++)
        {
            if (i < static_cast<int>(speakerText.length()))
            {
                std::cout << speakerText[i];
            }
            else
            {
                std::cout << " ";
            }
        }


        std::cout << "║\n";


        // ========================================================================================
        //                                    BLANK LINE
        // ========================================================================================

        std::cout << "║";

        for (int i = 0; i < BOX_WIDTH - 2; i++)
        {
            std::cout << " ";
        }

        std::cout << "║\n";


        // ========================================================================================
        //                                  DIALOGUE TEXT
        // ========================================================================================

        for (size_t i = start; i < end; i++)
        {
            std::string message = "  " + wrappedLines[i];


            std::cout << "║";


            for (int j = 0; j < BOX_WIDTH - 2; j++)
            {
                if (j < static_cast<int>(message.length()))
                {
                    std::cout << message[j];
                }
                else
                {
                    std::cout << " ";
                }
            }


            std::cout << "║\n";
        }


        // ========================================================================================
        //                                  BOTTOM DIVIDER
        // ========================================================================================

        std::cout << "╠";

        for (int i = 0; i < BOX_WIDTH - 2; i++)
        {
            std::cout << "═";
        }

        std::cout << "╣\n";


        // ========================================================================================
        //                                  CONTINUE PROMPT
        // ========================================================================================

        std::string prompt;


        if (end < wrappedLines.size())
        {
            prompt = "[ PRESS ENTER -> CONTINUE ]";
        }
        else
        {
            prompt = "[ PRESS ENTER ]";
        }


        std::cout << "║";


        int promptPadding =
            (BOX_WIDTH - 2 - static_cast<int>(prompt.length())) / 2;


        for (int i = 0; i < promptPadding; i++)
        {
            std::cout << " ";
        }


        std::cout << prompt;


        for (
            int i = promptPadding + static_cast<int>(prompt.length());
            i < BOX_WIDTH - 2;
            i++
        )
        {
            std::cout << " ";
        }


        std::cout << "║\n";


        // ========================================================================================
        //                                    BOTTOM BORDER
        // ========================================================================================

        std::cout << "╚";

        for (int i = 0; i < BOX_WIDTH - 2; i++)
        {
            std::cout << "═";
        }

        std::cout << "╝\n";


        // ========================================================================================
        //                                  WAIT FOR ENTER
        // ========================================================================================

        std::cin.ignore(
            std::numeric_limits<std::streamsize>::max(),
            '\n'
        );
    }
}