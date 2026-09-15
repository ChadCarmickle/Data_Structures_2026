/**************************************************************************************************
 *
 *                                      Stage4.cpp
 *
 *                        Display All Story Text for Stage 4, Levels 1-4
 **************************************************************************************************
 Program name: Midterm Text-Based Project.
 Author: Chad Carmichael & Christian Denning
 Date last updated: 9/11/26
 Purpose: Midterm Project.
*/

#include <limits>
#include <iostream>
#include <string>
#include <cctype>

#include "Stage4.h"
#include "../../GameData/LevelManager.h"
#include "../StoryUtils.h"
#include "../../UI/TerminalUI.h"
#include "../../GameData/Shop/Shop.h"
#include "../../GameData/GameOver/GameOver.h"
#include "../../Classes/Ally/Ally.h"

bool stage4CurrencyLocationVisited = false;
void EnterStage4(Player& player)
{
    showDialogue(
        "",
        {
            "With the forces of Zorvax defeated humanity begins to repair.",
            "In search for new planets and resources Humanity begins to explore",
            "further than prior spaceships could.", 
            "The great unknown awaits commander " + player.getName(), 
        }, 
        "Stage 4 *** The Lost Civilization.  ***"
    );

    PlayerInput PlayerSelection = PlayerInput::A;

        showDialogue(
        "HEADQUARTERS:",
        {
            "Requesting Commander " + player.getShipName(), 
            player.getShipName() + " with and allies standing",
            "We are sending you and your forces on a scouting mission.",  
            "Due to the unknown threats, be on your guard..",
        }, 
        "*** Incoming Transmission! ***"
    );

        showDialogue(
        "",
        {
            ally1.getName() + ": Exploration of new planets, this is a rare request comander.", 
            ally2.getName() + ": We should be prepared for anything that lies in store for us.", 
            ally3.getName() + ": We will stand with you commander until the very end.", 
            "CO Jet: Setting course to explore the unknown comander.",

        },
        ally1.getName() + ", " + ally2.getName() + ", " + ally3.getName() + ", "
    );


PlayerSelection = PlayerInput::A;

while (PlayerSelection != PlayerInput::D)
{
    say("1) " + getLevelname(4, 1));
    say("2) " + getLevelname(4, 2));
    say("3) " + getLevelname(4, 3));
    say("4) " + getLevelname(4, 4));

    PlayerSelection = askPlayer();

    switch (PlayerSelection)
    {
        case PlayerInput::A:

            showDialogue(
                ally2.getName() + " " + ally2.getlast(),
                {
                    "Commander it appears some merchants have set up camp here.",
                    "My translation skills are a tad rusty, but it appears they want to trade.",

                },
                getLevelname(4, 1) + "."
            );
                            
            Visitshop(player, 4);

            break;


        case PlayerInput::B:

            showDialogue(
                ally3.getName() + ": ",
                {
                    "Pirate forces detected on the outskirts!",
                    "They are approaching fast!",
                    ally2.getName() + ": So this is where they were hiding",
                    ally1.getName() + ": Makes sense for outlaws to hide here."
                },
                getLevelname(4, 2) + "."
            );

            say("COMBAT-");

            if (player.isDefeated())
            {
                gameOver(player);
                return;
            }

            break;

        case PlayerInput::C:

                if (!stage4CurrencyLocationVisited) { 


                showDialogue(
                    "Chief Officer Jet:",
                    {
                        "Commander there are multiple damaged ships here.",
                        "It seems many of them were left un-salvaged.",
                        "Sending a team now to recover any resources.",
                        "Reward 400 credits.", 
                    },
                    getLevelname(4,3) + "."
                );

                    player.addCurrency(400);
                    say("$" + std::to_string(player.getCurrency()));
                    stage4CurrencyLocationVisited = true;
                }
                else { 

                showDialogue(
                    "Chief Officer Jet:",
                    {
                    "Commander, " + player.getName() + " we've explored this location already.", 
                    }
                );
                }
                break;
    








    case PlayerInput::D:

        showDialogue(
            "",
            {
                "Commander, I'm reading a spaceship 300 clicks North-West.",
                "Strange... there doesn't seem to be any life detected...",
                ally3.getName() + ": That...that's no abandoned ship! It's an Oblivion Vessal!!!",
                ally1.getName() + ": An Oblivion!!! It's a Rogue AI cruiser! They shoot to kill!!"
            },
            getLevelname(4, 4) + "."
        );

        say("COMBAT-");

        if (player.isDefeated())
        {
            gameOver(player);
            return;
        }
    }
 } // end of Stage3

         // Boss defeated — Stage 4 complete
        showDialogue(
            "CO Jet:",
            {
                "Commander, we defeated the Rogue AI... but we have a bigger problem!",
                "Due to the damage we've taken, our fleets is drifting into a black hole!",
                "EVERYONE, PREPARE YOURSELVES!"
            },
            "Out of the Frying Pan, Into the Fire"
        );

        showDialogue(
            "????",
            {
                "It's T̷I̷M̷E̷... W̷E̷ ̷F̷I̷G̷H̷T̷.̷.̷",
                "Commander... did you hear that?",
                "That transmission didn't come from any ship in our fleet...",
                "* Everything fades to black *",
            },
            "An unknown voice fills your mind..."
        );

        say("*******************************************************************************************");
        say("*******************************************************************************************");
        say("Congratulations! You have completed Stage 4: The Lost Civilization");
        say("*******************************************************************************************");
        say("*******************************************************************************************");

        return; 
 } // end of Stage