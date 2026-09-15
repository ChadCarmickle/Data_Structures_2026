/**************************************************************************************************
 *                                                                                                *
 *                                      Stage1.cpp                                                *
 *                                                                                                *
 *                        Display All Story Text for Stage 1, Levels 1-4                         *
 **************************************************************************************************
 Program name: Midterm Text-Based Project.
 Author: Chad Carmickle & Christian Denning
 Date last updated: 9/11/26
 Purpose: Midterm Project.
*/

#include <limits>
#include <iostream>
#include <string>
#include <cctype>


#include "Stage1.h"
#include "../../GameData/LevelManager.h"
#include "../StoryUtils.h"
#include "../../UI/TerminalUI.h"
#include "../../GameData/Shop/Shop.h"
#include "../../GameData/GameOver/GameOver.h"
#include "../../Classes/Ally/Ally.h"

void intro(Player& player)
{


    showDialogue(
    "",
      {
        "1337 years since mankind took its first step into space",
        "A new battle unravels in the dark cold depths of space.",
        "With threats looming in all corners of the galaxy",  
        "Is there a hero who man make this galaxy a paradise?",

        }, 
        "Stage 1 *** Rise of a Commander ***"
    );






    showDialogue(
        "Unknown:",
        {
            "Commander, you're finally awake.",
            "Whoa, take it easy there, commander!",
            "Commander, you hit your head pretty hard.",
            "Do you remember your name and the spaceship?"
        }
    );

    std::string NewplayerName = SetPlayerName();
    player.setPlayerName(NewplayerName);

    std::string NewspaceshipName = SetPlayerSpaceshipName();
    player.setShipName(NewspaceshipName);

    int NewPlayerCurrency = player.getCurrency();
    int NewPlayerRepairBots = player.getRepairBots();

    #ifdef _WIN32
    system("cls");
    #else
    system("clear");
    #endif

    tutorial(player);


    showDialogue(
        "Unknown:",
        {
            "Good, glad to hear you're still with us, Commander " +
                player.getName() + ".",

            "We lost contact from Headquarters about 2 hours ago.",

            "We've been drifting since. Those asteroids hit us."
        }
    );
}


void tutorial(Player& player)
{
    showDialogue(
        "Unknown:",
        {
            "It's good to have you with us, Commander " +
                player.getName() + ".",

            "The doctor said we should start off slow.",
            "Let's address any elephants in the room."
        }
    );

    say("\n| To make a selection Enter the number. |\n");

    say("1) 'Where am I?'");
    say("2) 'Who are you?'");
    say("3) 'Did you say commander?'");
    say("4) *Skip Tutorial / Next*");


    PlayerInput PlayerSelection = askPlayer();


    while (PlayerSelection != PlayerInput::D)
    {
        switch (PlayerSelection)
        {
            case PlayerInput::A:

                showDialogue(
                    "Chief Officer Jet:",
                    {
                        "We are currently in the medic bay of the grand spaceship: " +
                            player.getShipName() + "."
                    }
                );

                break;


            case PlayerInput::B:

                showDialogue(
                    "Chief Officer Jet:",
                    {
                        "I am your Chief Officer, Jet Black, at your service Commander.",
                        "You give the order and I see it's done."
                    }
                );

                break;


            case PlayerInput::C:

                showDialogue(
                    "Chief Officer Jet:",
                    {
                        "Correct. You are the commander of the " +
                            player.getShipName() + ".",

                        "We receive orders from HQ and carry out exploration missions."
                    }
                );

                break;


            case PlayerInput::D:
                break;
        }

        PlayerSelection = askPlayer();
    }


    showDialogue(
        "Officer:",
        {
            "Greetings Commander " + player.getName() +
                " and Chief Officer Jet.",
            "Headquarters has requested your attention.",
            "Thank you officer, We will handle it.",
            "Commander a word please."
        }
    );

    showDialogue(
        "Chief Officer Jet:",
        {
            "I have a feeling HQ will have us relocate,", 
            "do you have any more questions?",
            "I'd rather not get caught with my pants down out there!"
        }
    );


    PlayerSelection = PlayerInput::A;


    while (PlayerSelection != PlayerInput::D)
    {
        say("1) 'Tell me about: Shops'");
        say("2) 'Tell me about: Combat'");
        say("3) 'Tell me about: Ship Upgrades'");
        say("4) 'See what HQ wants.'");


        PlayerSelection = askPlayer();


        switch (PlayerSelection)
        {
            case PlayerInput::A:

                showDialogue(
                    "Chief Officer Jet:",
                    {
                        "Shops are located all around the Galaxy.",
                        "As long as you have coin, they have the goods.",
                        "Repair Bots allow us to repair during combat.",
                        "Spaceship Upgrades increase health or Damage",
                    }
                );

                break;


            case PlayerInput::B:

                showDialogue(
                    "Chief Officer Jet:",
                    {
                        "Combat is straightforward.",
                        "If we engage a faster enenmy they attack first",
                        "If we are faster we attack first.", 
                        "Combat is then made into a turn-based. We can do:",

                    }
                );

                
                showDialogue(
                    "Chief Officer Jet:",
                    {
                        "Attack:     Attacks the closest enemy.",
                        "Repair:     Repairs any damage caused.",
                        "Status      Report: Provides detailed stats of our vessel.",
                        "Flee:       Order a full on retreat."
                    }
                );
                break;


            case PlayerInput::C:

                showDialogue(
                    "Chief Officer Jet:",
                    {
                        "We can discover or purchase upgrades:",
                        "Weapon Upgrades: Increase Damage.",
                        "Shield Upgrades: Increase Health.",
                        "Ship Modules: Rare and sought-after upgrades", 
  
                    }
                );

                break;

            case PlayerInput::D:
                break;
        }
    }


    showDialogue(
        "Chief Officer Jet:",
        {
            "Very well, Commander " + player.getName() + "."
            "Let's hope HQ has a raise for us haha."
        }
    );
}



bool stage1CurrencyLocationVisited = false;

void EnterStage1(Player& player)
{

    PlayerInput PlayerSelection = PlayerInput::A;


    showDialogue(
        "HEADQUARTERS:",
        {
            "Greetings Commander " + player.getName() + ".",
            "We are getting readings of unknown vessels in your sector.",
            "Please investigate. That is all for now. *Click*"
        }, 
        "*** Incoming Transmission! ***"
    );


    showDialogue(
        "Chief Officer Jet:",
        {
            "Well Commander, as Superman once said:",
            " 'The never ending battle for Truth, Justice and the American Way.' ",
            "I'll let the crew know we are moving out",
            "Where do you want to set course to?"
        }
    );


    while (PlayerSelection != PlayerInput::D)
    {
        say("1) " + getLevelname(1, 1));
        say("2) " + getLevelname(1, 2));
        say("3) " + getLevelname(1, 3));
        say("4) " + getLevelname(1, 4));


        PlayerSelection = askPlayer();


        switch (PlayerSelection)
        {
            case PlayerInput::A:

                showDialogue(
                    "Chief Officer Jet:",
                    {
                        "Setting destination to: " + getLevelname(1, 1),
                        "Commander, we have arrived at a Shop."
                    }
                );

                Visitshop(player, 1);

                break;


            case PlayerInput::B:

                showDialogue(
                    "Chief Officer Jet:",
                    {
                        "Setting destination to: " + getLevelname(1, 2),
                        "Commander, Pirate Scout Detected!",
                        "Engaging combat."
                    }
                );

                say("COMBAT-"); 

                if (player.isDefeated())
                {
                    gameOver(player);
                    return;
                }

                break;


            case PlayerInput::C:

                if (!stage1CurrencyLocationVisited) { 

                    showDialogue(
                        "Chief Officer Jet:",
                        {
                            "Setting destination to: " + getLevelname(1, 3),
                            "It appears to be a damaged civilian ship.",
                            "I will send aid to them now!", 
                            "Reward: 200 Credits"
                        }
                    );
                    player.addCurrency(200);
                    say("$" + std::to_string(player.getCurrency()));
                    stage1CurrencyLocationVisited = true;
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
                    "Chief Officer Jet:",
                    {
                        "Now appraching the distress signal",
                        "It says: 'help us...help us...'",
                        "The message repeats commander.",
                        "I got a bad feeling about this..."
                    }, 
                    " Distress Signal. "
                );

                showDialogue(
                    "Chief Officer Jet:",
                    {
                        "Blast our communcations are down!", 
                        "We are sitting ducks out here! ",
                        "Bad news Commander " + player.getName() + ".", 
                        "Enemy Ships detected, All crew memebers prepare for battle!", 
                    },
                    "*  Communication Systems Offline! ** "
                );

                say("COMBAT-");

                if (player.isDefeated())
                {
                    gameOver(player);
                    return;
                }

                break;
        }
    }


    showDialogue(
     "Chief Officer Jet:",
      {
        "Fantastic work Commander " + player.getName(), 
        "Ol " + player.getShipName() + " may be old but she is a reliable vessal.",
        "We should report this to HQ", 
        "*** Reward: 125 Credits ***"
      }
    );
    player.addCurrency(125); 
        
    showDialogue(
      "Headquarters:",
     {
        "Greetings commander " + player.getName(), 
        "We've recived your report about the pirates. ",
        "Unfortunately, we've detected more activity in sector Novaris", 
        "We are renforcing you with an addional Spaceship.", 
    },
     "* Incoming Tramsmission "
    );

    showDialogue(
      "Cheif Officer Jet:",
     {
        "A new spaceship? That will improve our chances in combat.",
        "Commander " + player.getName() + " I wouldn't celebrate too much...", 
        "That means HQ is sending us into more dangerous locations..",
        "Commander " + player.getName() + " lets contact our new ally.", 
    },
    "DIALOGUE"
    );


    showDialogue(
    ally1.getName() + " " +  ally1.getlast() + " The " + ally1.getTitle() + ", Starship Captain of the " + ally1.getShipName(), 
     {
        "Greetings commander " + player.getName(), 
        "I am " + ally1.getName() + " " + ally1.getlast() + " at your service.",
        "It seems HQ has requested our forces to combine",  
        "The " + ally1.getShipName() +  " is at your command.", 
    },
     "* Contacting New Ally "
    );
    say("*******************************************************************************************"); 
    say("*******************************************************************************************"); 
    say("Congragulations, You have complected Stage 1: Rise of the Commander " + player.getShipName()); 
    say("A new Ally has Joined your Fleet! \n"); 
    ally1.showStats(); 
    say("A vetern of the 2nd and 3rd Galaxy war, a fearsome foe to fight due to his brtuality in  battle.");
    say("*******************************************************************************************"); 
    say("*******************************************************************************************"); 
    ally1.setJoined(true);
    showDialogue(
      "",
     {
        "More challenges await in stage 2! Chaos in the void" ,  
    },
    "Start Stage 2?"
    );
    return;
}