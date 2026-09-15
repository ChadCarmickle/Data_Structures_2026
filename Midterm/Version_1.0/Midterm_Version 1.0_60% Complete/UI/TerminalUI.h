/**************************************************************************************************
 *                                                                                                *
 *                                    TerminalUI..                                                *
 *                                                                                                *
 *                          Handles the game's terminal user interface                            *
 **************************************************************************************************
 Program name: Midterm Text-Based Project.
 Author: Chad Carmickle & Christian Denning
 Date last updated: 9/11/26
 Purpose: Handles dialogue boxes and terminal-based UI.
*/


#ifndef TERMINAL_UI_H
#define TERMINAL_UI_H

#include <string>
#include <vector>

void showDialogue(
    const std::string& speaker,
    const std::vector<std::string>& lines,
    const std::string& title = "DIALOGUE"
);

#endif