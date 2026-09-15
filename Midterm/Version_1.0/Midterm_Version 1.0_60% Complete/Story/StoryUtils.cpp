#include "StoryUtils.h"

#include <iostream>
#include <limits>
#include <cctype>

void say(const std::string& text)
{
    std::cout << text << '\n';
}



std::string SetPlayerName()
{
    const std::string defaultName = "Commander";

    while (true)
    {
        say("Do you remember your name? ");

        std::string name;
        std::getline(std::cin, name);

        if (name.empty())
        {
            say("Player name set as: " + defaultName);
            return defaultName;
        }

        bool valid = name.length() <= 10;

        for (char character : name)
        {
            if (!std::isalpha(static_cast<unsigned char>(character)))
            {
                valid = false;
                break;
            }
        }

        if (valid)
        {
            name[0] = std::toupper(
                static_cast<unsigned char>(name[0])
            );

            return name;
        }

        std::cout << "Invalid name. Use only letters and no more than 10 characters.\n";
    }
}

std::string SetPlayerSpaceshipName()
{
    const std::string defaultShip = "USS Narwhal";

    while (true)
    {
        say("Do you remember the Spaceship name? ");

        std::string name;
        std::getline(std::cin, name);

        if (name.empty())
        {
            say("Ship name set as: " + defaultShip);
            return defaultShip;
        }

        // Allow letters, numbers, and spaces.
        // Maximum length: 25 characters.
        bool valid = name.length() <= 25;

        for (char character : name)
        {
            if (!std::isalnum(static_cast<unsigned char>(character))
                && character != ' ')
            {
                valid = false;
                break;
            }
        }

        if (valid)
        {
            return name;
        }

        std::cout << "Invalid ship name. Use only letters, "
                     "numbers, spaces, and no more than 25 characters.\n";
    }
}

// Primary menu list. 
PlayerInput askPlayer()
{
    int input = 0;

    while (true)
    {
        std::cout << "Choose 1-4: ";

        if (std::cin >> input && input >= 1 && input <= 4)
        {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            switch (input)
            {
                case 1:
                    return PlayerInput::A;

                case 2:
                    return PlayerInput::B;

                case 3:
                    return PlayerInput::C;

                case 4:
                    return PlayerInput::D;
            }
        }

        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::cout << "Invalid input. Please enter a number between 1 and 4.\n";
    }
}

// Seperate game over menu only 2 choices. 
PlayerInput askGameOver()
{
    int input = 0;

    while (true)
    {
        std::cout << "Choose 1-2: ";

        if (std::cin >> input && input >= 1 && input <= 2)
        {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            switch (input)
            {
                case 1:
                    return PlayerInput::A;

                case 2:
                    return PlayerInput::B;
            }
        }

        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::cout << "Invalid input. Please enter 1 or 2.\n";
    }
}