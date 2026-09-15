#ifndef STORY_UTILS_H
#define STORY_UTILS_H

#include <string>

// Print a line of story text
void say(const std::string& text);

// Name helpers
std::string SetPlayerName();
std::string SetPlayerSpaceshipName();

// Player choice (1-4)
enum class PlayerInput
{
    A = 1,
    B = 2,
    C = 3,
    D = 4
};

PlayerInput askPlayer();
PlayerInput askGameOver();

#endif