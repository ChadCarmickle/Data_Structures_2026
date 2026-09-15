#ifndef GAME_OVER_H
#define GAME_OVER_H

#include "../../Classes/Player/Player.h"

// Enum alows the player to skip the Intro Keeping their name & shipname. 
enum class GameOverChoice
{
    ReloadSkipIntro,
    FullRestart
};

GameOverChoice gameOver(Player& player);

#endif