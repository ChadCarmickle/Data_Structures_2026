
/**************************************************************************************************
 *                                                                                                *
 *                                      Gameflow.cpp                                              *
 *                                                                                                *
 *                                 Spaceship Class: Child:Enemy                                   *
 **************************************************************************************************
 Program name: Midterm Text-Based Project.  
 Author: Chad Carmickle & Christian Denning
 Date last updated: 9/11/26
 Purpose: Midterm Project.
*/ 
// Controls the overall flow and progression of the game by presenting player choices and coordinating the different game systems.


#ifndef GAMEFLOW_H
#define GAMEFLOW_H

class GameFlow
{
private:
    int currentStage;
    const int finalStage = 5;
    bool gameRunning;

public:
    GameFlow();

    void run();
};

#endif