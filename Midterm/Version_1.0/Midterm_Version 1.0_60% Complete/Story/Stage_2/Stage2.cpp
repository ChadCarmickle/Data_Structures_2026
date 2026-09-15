/**************************************************************************************************
 *
 *                                      Stage2.cpp
 *
 *                        Display All Story Text for Stage 2, Levels 1-4
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

#include "Stage2.h"
#include "../../GameData/LevelManager.h"
#include "../StoryUtils.h"
#include "../../UI/TerminalUI.h"
#include "../../GameData/Shop/Shop.h"
#include "../../GameData/GameOver/GameOver.h"
#include "../../Classes/Ally/Ally.h"


bool stage2CurrencyLocationVisited = false;
void EnterStage2(Player& player)
{

        showDialogue(
        "",
        {
            "Local pirate attacks have been on the rise,",
            "Civilans are scared for their lifes...",
            "Will the " + player.getShipName() + " and commander " + player.getName(), 
            "Fight off this new threat or fall to their might..."
        }, 
        "Stage 2 *** Chaos in the Void ***"
    );



        PlayerInput PlayerSelection = PlayerInput::A;

        showDialogue(
        "HEADQUARTERS:",
        {
            player.getShipName() +  " Come in " + player.getShipName() + " Do you Copy?", 
            "This is Chief Officer Jet of the " + player.getShipName(), 
            "HQ: Multiple distress signals from locations in your sector.", 
            "We are requesting you support and investigate."
        }, 
        "*** Incoming Transmission! ***"
    );

        showDialogue(
        "HEADQUARTERS:",
        {
            "CO: Do we know the purpose of these distress signals?",
            "HQ: Afraid not " + player.getShipName() + " we suspect pirates. processed with caution", 
            ally1.getName() + ": Filthy pirates, they would sell their own mothers for a coin.", 
            "CO: Understood we will report our findings soon. ", 
        }, 
        "*** Incoming Transmission! ***"
    );

    
        showDialogue(
        "CO:",
        {
            "Well Commander " + player.getName() + " it looks like we might be fighting pirates.",
            "Before we head out do you have any questions?", 
            "Let me know when you're ready, I will give the order. ", 
        }, 
        "Dialogue"
    );
    

    while (PlayerSelection != PlayerInput::D)
    {
        say("1) 'Who are these Pirates?'");
        say("2) 'What damage can they cause?'");
        say("3) 'Can we negotiate peace?'");
        say("4) 'Continue'  ");

        PlayerSelection = askPlayer();

        switch (PlayerSelection)
        {
            case PlayerInput::A:
                    showDialogue(
                    "Chief Officer Jet:",
                    {
                        "Pirates are ruthless villains " + player.getName(), 
                        "They steal, kidnap and rob anything not nailed down.", 
                        "They work in small forces making it harder", 
                        "for our larger forces to pin them down.",
                    }
                );
                break;

            case PlayerInput::B:
                    showDialogue(
                    "Chief Officer Jet:",
                    {
                        "I've only seen the aftermath of their raids... ",
                        "Commander, they are not pretty...", 
                        "I saw them take a baby bed, who does that? Savages I tell you!", 
                    }
                );
                break;

            case PlayerInput::C:
                    showDialogue(
                    "Chief Officer Jet:",
                    {
                        "Commander " + player.getName() + " you should lay off the ale.",
                        "A pirate will only surrender to later steal you blind commander.", 
                        "Its better to take them prisoner and let HQ handle it", 
                    }
                );
                break;

            case PlayerInput::D:
                    showDialogue(
                    "Chief Officer Jet:",
                    {
                        "Very well commander, ",
                        "Attention all crew members prepare for travel.", 
                        "I'm going to check the mess hall, I heard they had cinnamon biscuits today.", 
                        "I got a bit of a sweet tooth, got it from my daughter I guess.", 
                    }
                );
                break;
        }
    }


    showDialogue(
        "Chief Officer Jet:",
        {
            "Now setting course to the Novaris Sector",
            "Commander it sounds like we are heading into pirate territory. ",
            "Keep your wits about you sir.",
            "Where shall we explore first?"
        }
    );
    
    PlayerSelection = PlayerInput::A;

    while (PlayerSelection != PlayerInput::D)
    {
        say("1) " + getLevelname(2, 1));
        say("2) " + getLevelname(2, 2));
        say("3) " + getLevelname(2, 3));
        say("4) " + getLevelname(2, 4));

        PlayerSelection = askPlayer();

        switch (PlayerSelection)
        {
            case PlayerInput::A:

                showDialogue(
                    "Chief Officer Jet:",
                    {
                        "Setting destination to: " + getLevelname(2, 1),
                        "Commander! A pirate ship is attacking that medical transport", 
                        ally1.getShipName() + " awaiting order commander " + player.getName(), 
                        "Enemy Forces have spotted us and started their attack!"
                    },
                    getLevelname(2,1) + "."
                );

                say("COMBAT-");

                if (player.isDefeated())
                {
                    gameOver(player);
                    return;
                }

                break;

            case PlayerInput::B:

                if (!stage2CurrencyLocationVisited) { 


                showDialogue(
                    "Chief Officer Jet:",
                    {
                        "Setting destination to: " + getLevelname(2, 2) + ".",
                        "Commander, we have reached the Nebula Passage.",
                        "Nothing particular to note here. However we found lost cargo.(+200 Credits)", 
                        "System tells this location was discovered 71 years ago by a Dr. Eggman", 
                    },
                    getLevelname(2,2) + "."
                );

                    player.addCurrency(200);
                    say("$" + std::to_string(player.getCurrency()));
                    stage2CurrencyLocationVisited = true;
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



            case PlayerInput::C:

                showDialogue(
                    "Chief Officer Jet:",
                    {
                        "Setting destination to: " + getLevelname(2, 3) + ".",
                        "Commander we have arrived at a Shop, their prices may be higher.",
                    },
                    getLevelname(2,3) + "."
                );
                
                Visitshop(player, 2);
                
                break;


            case PlayerInput::D:

                showDialogue(
                    "Chief Officer Jet:",
                    {
                        "This must be what HQ told us about! A " + getLevelname(2, 4) + ".",
                        ally1.getName() + " reporting in, Permission to engage Commander,",
                        "They spotted us, Prepare for battle! This is Not a drill! ",
                        ally1.getName() + ": A pirate Captain! this will be a tough battle.."
                    }, 
                    " Pirate Captain (Boss!) "
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
            "The pirate captain has been defeated.",
            "Excellent work, Commander." + player.getName(),
            "Sir I'm picking up another unknown signal!"
        },
        "After the Battle"
    );

    showDialogue(
        "???",
        {
            "You got guts kid,",
            "We watched your battle Commander" + player.getName(),
            "It would be an honor to fight alongside a worthy brother in arms."
        },
        "A New Threat?"
    );


    showDialogue(
        ally2.getName() + " " +  ally2.getlast() + " The " + ally2.getTitle() + ", of the mightly " + ally2.getShipName(), 
        {
            ally2.getName() + " I command the " + ally2.getShipName(),
            "We watched your battle Commander " + player.getName(),
            "Your ruthless fighting for pirates pleases me and the " + ally2.getShipName(), 
            "Let us put an end to all threats of humanity. ", 
        },
        "A New Ally?"
    );

        showDialogue(
         ally1.getName() + " " +  ally1.getlast() + ", Starship Captain of the " + ally1.getShipName(), 
        {
            "Commander did I hear that correctly? The " + ally2.getName(), 
            "They are one of the strongest forces in the universe ",
            "With their firepower we will be a extreme threat!",  
        },
        "Ally: " + ally1.getShipName() 
    );

    say("*******************************************************************************************"); 
    say("*******************************************************************************************"); 
    say("Congragulations, You have complected Stage 2: Chaos in the void " + player.getShipName()); 
    say("A new Ally has Joined your Fleet! \n"); 
    ally2.showStats(); 
    say("A researcher who searches for the answers of an old lost civilization. ");
    say("*******************************************************************************************"); 
    say("*******************************************************************************************"); 
    ally2.setJoined(true);
    showDialogue(
      "",
     {
        "More challenges await in stage 3! The Zorvax Dominion" ,  
    },
    "Start Stage 3?"
    );
    return;
 }

