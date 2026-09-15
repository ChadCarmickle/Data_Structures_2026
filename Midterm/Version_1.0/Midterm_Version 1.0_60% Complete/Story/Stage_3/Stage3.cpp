/**************************************************************************************************
 *
 *                                      Stage3.cpp
 *
 *                        Display All Story Text for Stage 3, Levels 1-4
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

#include "Stage3.h"
#include "../../GameData/LevelManager.h"
#include "../StoryUtils.h"
#include "../../UI/TerminalUI.h"
#include "../../GameData/Shop/Shop.h"
#include "../../GameData/GameOver/GameOver.h"
#include "../../Classes/Ally/Ally.h"


bool stage3CurrencyLocationVisited = false;

void EnterStage3(Player& player)
{

        showDialogue(
        "",
        {
            "Due to the pirate attacks many of humanity forces are spread thin.",
            "The Zorvax have launched an attack on human-controlled sectors.",
            "Talks of peace have resulted in both parties carrying weapons.", 
            "Can commander " + player.getName() + " keep the peace?",
        }, 
        "Stage 3 *** The Zorvax Invasion ***"
    );



    PlayerInput PlayerSelection = PlayerInput::A;

        showDialogue(
        "HEADQUARTERS:",
        {
            "!! Come in all available fleets !! ",
            "CO: This is Chief Officer Jet of the " + player.getShipName(),
            ally1.getShipName() + " Standing by.", 
            ally2.getShipName() + " receiving orders.", 

        }, 
        "*** Incoming Transmission! ***"
    );

        showDialogue(
        "HEADQUARTERS:",
        {
            "Calling all forces " + player.getShipName() + ", " + ally1.getShipName() + ", " + ally2.getShipName() + ".", 
            "The Zorvax have begun an assult on multiple sectors requesting aid", 
            "CO: Understood all ships depart at once!",  
        }, 
        "*** Incoming Transmission! ***"
    );

            showDialogue(
        ally2.getName() + " " + ally2.getlast() + " Warbinger of the " + ally2.getShipName() + ":",
        {
            "Commander, have you all fought the Zorvaxs before?", 
            "CO: I never seen one up close only read about them in the academy. ", 
            ally1.getName() + ": likewise, they are a private kind of people..", 
        }, 
        ally2.getShipName() 
    );


while (PlayerSelection != PlayerInput::D) 
{ 
    say("1) What do you know about the Zorvax"); 
    say("2) Why are they attacking us. "); 
    say("3) Are they all hostile?"); 
    say("4) Continue"); 
 
    PlayerSelection = askPlayer(); 
 
    switch (PlayerSelection) 
    { 
        case PlayerInput::A: 
            showDialogue( 
                "", 
                { 
                    "They are some of the most feared warriors i've met. ", 
                    "Their origins are unknown but they are similar to fish-men", 
                    "All of their ships are flooded with Glacial Water, extremely cold liquid", 
                    "However its unlikely for them to attack so bold like this...", 
                },
                ally2.getName() 
            ); 
            break; 
 
        case PlayerInput::B: 
            showDialogue( 
                "", 
                { 
                    "apologies commander, I do not have that answer.", 
                    "Last time they attacked it was due to a civil war amongst them", 
                    "Decades before my time, my grandfather spoke of them", 
                    "He said they attack to show witness to their strength ", 
                },
                ally2.getName() 
            ); 
            break; 
 
        case PlayerInput::C: 
            showDialogue( 
                "", 
                { 
                    "Negative commander, there are quite a few who respect us.", 
                    "Not all of them are openly hostile to us they may even trade",
                    "However don't let that dull your senses if a vessel is near",  
                    "They wont hesitate to attack us.",  
                },
                ally2.getName()
            ); 
            break; 
 
        case PlayerInput::D: 
            showDialogue( 
                "", 
                { 
                    "Understood Commander let us drive them out of our lands"
                },
                ally2.getName()
            ); 
            break; 
    } 
}

            showDialogue( 
                "", 
                { 
                    "Plotting locations sent from headquarters now sir.", 
                    "All locations are now displayed please select where to go.", 
                    ally2.getShipName() + " Awaiting your command", 
                    ally1.getShipName() + " Systems green our ship is ready Commander," + player.getName(), 
                } 
            ); 

    PlayerSelection = PlayerInput::A;

    while (PlayerSelection != PlayerInput::D) 
    { 
        say("1) " + getLevelname(3, 1)); 
        say("2) " + getLevelname(3, 2)); 
        say("3) " + getLevelname(3, 3)); 
        say("4) " + getLevelname(3, 4)); 
    
        PlayerSelection = askPlayer(); 
    
        switch (PlayerSelection) 
        { 
            case PlayerInput::A:

                if (!stage3CurrencyLocationVisited) { 


                showDialogue(
                    "Chief Officer Jet:",
                    {
                       "No signs of life here sir.", 
                       "This planet seems to have once been popular for the Zorvax people.",
                       "It seems they have moved their fleet else-where.",
                       "We did locate some lost Cargo (+400 Credits)",
                    },
                    getLevelname(3,1) + "."
                );

                    player.addCurrency(400);
                    say("$" + std::to_string(player.getCurrency()));
                    stage3CurrencyLocationVisited = true;
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
    
            case PlayerInput::B: 
    
                showDialogue( 
                    "Chief Officer Jet:", 
                    { 
                        "Now setting course to...",
                        "Computer: DANGER DANGER DANGER", 
                        ally2.getShipName() + " We have been attacked! requesting aid!", 
                        ally1.getShipName() + " We're in position and ready to assist.", 
                    }, 
                    getLevelname(3, 2) + "." 
                ); 
                
                say("COMBAT-"); 
    
                if (player.isDefeated()) 
                { 
                    gameOver(player); 
                    return; 
                } 
    
                break; 
    
    
            case PlayerInput::C: 
    
                showDialogue( 
                    "Chief Officer Jet:", 
                    { 
                        "Commander we have reached a Signal Relay, It appears to be a Zorvax base.", 
                        "Permission has granted to restock here commander.", 
                        ally1.getName() + ": I wonder if they sell fish...Would they see that as disrespectful?", 
                        ally2.getName() + ": I am no salesman, I seek the thrill of battle not coin."
                    }, 
                    getLevelname(3, 3) + "." 
                ); 
                
                Visitshop(player, 3); 
                
                break; 
    
    
            case PlayerInput::D: 
    
                showDialogue( 
                    "Chief Officer Jet:", 
                    { 
                      "Mayday! Mayday! This is " + ally3.getShipName() + " Requesting Support!", 
                      "Sir..Sir! Thats a whole Platoon, an invasion force!", 
                      ally2.getName() + ": Get the guns ready! Show them no Mercy!",
                      ally1.getName() + ": Providing covering fire on that allied ship!!", 
                    },  
                    getLevelname(3, 4) + "." 
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
            "A whole platoon...defeated like that...",
            "Commander, I'm glad i'm on your side.",
            ally2.getName() + " A worthy battle well done Commander",
            ally1.getShipName() + " Minimal damage reported, starting repairs now."  
        },
        "The dust settles on a battle..."
    );

        
    showDialogue(
    ally3.getName() + " " +  ally3.getlast() + " of " + ally3.getTitle() + "s, Captain of the " + ally3.getShipName() + " spaceship", 
    
      {
            "This is " + ally3.getName() + " " + ally3.getlast() + " You saved our hides.",
            "Without your help my ship the " + ally3.getShipName() + " would have met a terrible fate..",
            "Due to extreme damage our ship is in terrible a state, permission to", 
            "accompany you until repairs. CO: Permission Granted."  
        },
        "????"
    );


    say("*******************************************************************************************"); 
    say("*******************************************************************************************"); 
    say("Congratulations, You have completed Stage 3: The Zorvax Invasion "                          ); 
    say("A new Ally has Joined your Fleet! \n"); 
    ally3.showStats(); 
    say("A warrior to an ancient order of assassins, his blade will fight alongside you Commander   ");
    say("*******************************************************************************************"); 
    say("*******************************************************************************************"); 
    ally3.setJoined(true);
    showDialogue(
      "",
     {
        "More challenges await in stage 4! The unexplored sectors." ,  
    },
    "Start Stage 4?"
    );
    return;

 } // end of Stage3