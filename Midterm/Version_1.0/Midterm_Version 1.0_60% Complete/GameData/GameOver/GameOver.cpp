/**************************************************************************************************
 *                                                                                                *
 *                                    GameOver.cpp                                                *
 *                                                                                                *
 *                              Handles the game's Game Over system                              *
 **************************************************************************************************
 Program name: Midterm Text-Based Project.
 Author: Chad Carmickle & Christian Denning
 Date last updated: 9/11/26
 Purpose: Handles the Game Over screen and restart options.
*/

#include "GameOver.h"

#include "../../UI/TerminalUI.h"
#include "../../Story/StoryUtils.h"

#include <iostream>

extern bool stage1CurrencyLocationVisited;
extern bool stage2CurrencyLocationVisited;
extern bool stage3CurrencyLocationVisited;
extern bool stage4CurrencyLocationVisited;

GameOverChoice gameOver(Player& player)
{
    showDialogue(
        "SYSTEM ALERT: CRITICAL DAMAGE! ",
        {
            "The " + player.getShipName() + " has been defeated in battle.",
            "Jet: I'm..*Cough*...sorry commander I failed you.",
            "*Jet pulls out a photo and kisses it, your eyes fade to black..."
        },
        "*** GAME OVER ***"
    );

    showDialogue(
        "The journey is not yet over...",
        {
            "1) Reload - Skip Intro",
            "2) Full Restart"
        },
        "*** GAME OVER ***"
    );

    std::cout << "\n";
    std::cout << "1) Reload - Skip Intro\n";
    std::cout << "2) Full Restart\n";

    PlayerInput selection = askGameOver();

    switch (selection)
    {
        case PlayerInput::A:
            return GameOverChoice::ReloadSkipIntro;

        case PlayerInput::B:
            stage1CurrencyLocationVisited = false;
            stage2CurrencyLocationVisited = false;
            stage3CurrencyLocationVisited = false;
            stage4CurrencyLocationVisited = false;

            return GameOverChoice::FullRestart;
    }
}