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

#include "GameFlow.h"

// Stage files
#include "../Story/Stage_1/Stage1.h"
#include "../Story/Stage_2/Stage2.h"
#include "../Story/Stage_3/Stage3.h"
#include "../Story/Stage_4/Stage4.h"
#include "../Story/Stage_5/Stage5.h"

// Game systems
#include "../GameData/LevelManager.h"
#include "../GameData/LoadLevels/LoadLevels.h"
#include "../GameData/GameOver/GameOver.h"
#include "../Story/StoryUtils.h"

// C++ Libraries 
#include <iostream>
#include <cctype>

using std::cout;


GameFlow::GameFlow()
    : currentStage(1),
      gameRunning(true)
{
}

// Stores the result of running a stage.
enum class StageFlowResult
{
    Completed,
    ReloadSkipIntro,
    FullRestart
};


// Checks if player died and doesnt allow them to move to next stage then. 
StageFlowResult runStage(void (*stage)(Player&), Player& player)
{
    stage(player);

    if (!player.isDefeated())
    {
        return StageFlowResult::Completed;
    }

    GameOverChoice choice = gameOver(player);

    if (choice == GameOverChoice::ReloadSkipIntro)
    {
        return StageFlowResult::ReloadSkipIntro;
    }

    return StageFlowResult::FullRestart;
}


void GameFlow::run()
{
    Player player;

    buildlevels();
    intro(player);

    StageFlowResult result = StageFlowResult::Completed;

    while (gameRunning)
    {
        switch (currentStage)
        {
            case 1:
                result = runStage(EnterStage1, player);
                break;

            case 2:
                result = runStage(EnterStage2, player);
                break;

            case 3:
                result = runStage(EnterStage3, player);
                break;

            case 4:
                result = runStage(EnterStage4, player);
                break;

            case 5:
                result = runStage(EnterStage5, player);
                break;

            default:
                gameRunning = false;
                break;
        }

        switch (result)
        {
            case StageFlowResult::Completed:
                currentStage++;
                break;

            case StageFlowResult::ReloadSkipIntro:
                player = Player();
                currentStage = 1;
                break;

            case StageFlowResult::FullRestart:
                player = Player();
                currentStage = 1;
                intro(player);
                break;
        }
    }
}



