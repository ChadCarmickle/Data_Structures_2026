/**************************************************************************************************
 *
 *                                      Stage5.cpp
 *
 *                        Display All Story Text for Stage 5, Levels 1-4
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

#include "Stage5.h"
#include "../../GameData/LevelManager.h"
#include "../StoryUtils.h"
#include "../../UI/TerminalUI.h"
#include "../../GameData/Shop/Shop.h"
#include "../../GameData/GameOver/GameOver.h"
#include "../../Classes/Ally/Ally.h"

bool stage5CurrencyLocationVisited = false;

void EnterStage5(Player& player)
{

    showDialogue(
    "",
    {
    "The fleet was swallowed by the black hole... everything went dark.",
    "One by one, the crew begins to regain consciousness.",
    "The ships are damaged, scattered, and drifting through an unknown region of space.",
    "Commander " + player.getName() + "... everyone is coming to.",
    },
    "Stage 5 *** Beyond the Void ***"
    );


    showDialogue(
    "???",
        {
        "????: HELLO!...HELLO! IS ANYONE THERE COME IN...",
        ally2.getName() + ": Yes! yes quit your yelling Captain " + ally1.getName(), 
        ally3.getName() + ": This is the " + ally3.getShipName() + " we have suffered minor damage..",
        ""
        },
        "Stage 5 *** Beyond the Void ***"
    );

    
    showDialogue(
    "???",
        {
        "????: HELLO!...HELLO! IS ANYONE THERE COME IN...",
        ally2.getName() + ": Yes! yes quit your yelling Captain " + ally2.getName(), 
        ally3.getName() + ": This is the " + ally3.getShipName() + " we have suffered major damage..",
        ""
        },
        "Stage 5 *** Beyond the Void ***"
    );

        
    showDialogue(
        player.getShipName(),
        {
        "CO: Jet: It seems like everyone is alright.",
        ally2.getName() + ": I've got a bit of a headace but I will live.",  
        ally3.getName() + ": We are repairing the damages but nothing we cant handle commander.",
        ally1.getName() + ": Whew...I'm glad we are all okay...but where are we? ",
        }
    );

    showDialogue(
        player.getShipName(),
        {
        "CO Jet: Only one way to find out, lets explore..",
        ally2.getName() + ": Agreed we need to establish connection with HQ if we wish to survive..",  
        ally3.getName() + ": Accoridng to the enginners we are green lit for travel.",
        }
    );
PlayerInput PlayerSelection = PlayerInput::A;

std::string unknownLocations[4] = {
    getLevelname(6, 1),
    getLevelname(6, 2),
    getLevelname(6, 3),
    getLevelname(6, 4)
};

bool LocationVisited[4] = {false, false, false, false};

while (!(LocationVisited[0] &&
         LocationVisited[1] &&
         LocationVisited[2] &&
         LocationVisited[3]))
{
    say("1) " + unknownLocations[0]);
    say("2) " + unknownLocations[1]);
    say("3) " + unknownLocations[2]);
    say("4) " + unknownLocations[3]);

    PlayerSelection = askPlayer();

    switch (PlayerSelection)
    {
        case PlayerInput::A:

            showDialogue(
                "",
                {
                    "Sir, we discovered a shop...",
                    "It appears to be controlled by robots..",
                    "This might be the last time we can restock.",
                    ally3.getName() + " Commander, consider it a blessing..."
                },
                getLevelname(6, 1) + "."
            );

            unknownLocations[0] = getLevelname(5, 1);
            LocationVisited[0] = true;
            Visitshop(player, 5);
            break;

        case PlayerInput::B:

            showDialogue(
                ally1.getName() + " " + ally1.getlast(),
                {
                    "Commander, we discovered a void gate. It's beyond our knowledge unfortunately.",
                    "We can record this discovery and HQ will reward us for this. (+500 Credits) ",
                    "T̷H̷E̷ ̷V̷O̷I̷D̷ ̷R̷E̷M̷E̷M̷B̷E̷R̷S̷.",
                    "Gaaah! What on earth was that?", 
                },
                getLevelname(6, 2) + "."
            );
            player.addCurrency(500); 
            unknownLocations[1] = getLevelname(5, 2);
            LocationVisited[1] = true;

            break;

        case PlayerInput::C:

            showDialogue(
                ally2.getName() + " " + ally2.getlast(),
                {
                    "Commander, we discovered a new planet.",
                    "A strange, uncharted planet covered in dark oceans and glowing crystalline formations.",
                    "No signs of civilization can be detected.",
                    "Y̷O̷U̷ ̷D̷I̷D̷ ̷N̷O̷T̷ ̷F̷I̷N̷D̷ ̷U̷S̷... W̷E̷ ̷F̷O̷U̷N̷D̷ ̷Y̷O̷U̷.", 
                    ally2.getName() + " There it is again! What is that!!!", 
                },
                getLevelname(6, 3) + "."
            );

            unknownLocations[2] = getLevelname(5, 3);
            LocationVisited[2] = true;

            break;


        case PlayerInput::D:
            showDialogue(
            
            ally4.getName() + " " + ally4.getlast(),
            {
            "Commander... unidentified vessel approaching. They're requesting communication.",
            "This is Commander " + ally4.getName() + " of the " + ally4.getShipName(),
            "It's been awhile since we've seen a friendly face...",
            "But something has been following our spaceship.",
            "We don't know what it is... and Commander, I don't think it wants us to leave.",

            ally2.getName() + ": The " + ally4.getShipName() + " was reported MIA several months ago.", 
            ally2.getName() + " How in the bloody halls of Ivy did they end up here?", 
            "This is Commander " + player.getName() + " of the " + player.getShipName(), 
            "What do you mean somthing is following you?", 
            ally4.getName() + ": I'm not sure how to put it but a myserious voice has been calling out to us.", 
            ally4.getName() + ": It's only gotten louder.", 
            player.getName() + " Hmmm, how vexing Very well fall into my fleet and we will fight this together.", 
            ally4.getName() + " Roger that, Appricate the cororporation Commander " + player.getName(), 
            },
            getLevelname(6, 4) + "."
            );

                say("A new Ally has Joined your Fleet! \n"); 
                ally4.showStats(); 
                ally4.setJoined(true);
            unknownLocations[3] = getLevelname(5, 4);
            LocationVisited[3] = true;

            break;
    }
}

showDialogue(
    "",
    {
        "Commander, we've explored every known location in this region.",
        "We've gathered everything we can and rescued another lost vessel.",
        "Whatever brought us here... it's time to find out why.",
        "All ships, prepare for the next phase of our journey."
    },
    "To the Edge of Reality."
);

showDialogue(
    "",
    {
        "Commander, we've reached the Edge of Reality.",
        "There is nothing beyond this point.",
        "Whatever has been following us... is here."
    },
    getLevelname(7, 1)
);

showDialogue(
    "????",
    {
        "T̷H̷E̷R̷E̷ ̷I̷S̷ ̷N̷O̷ ̷E̷D̷G̷E̷.̷",
        "T̷H̷E̷R̷E̷ ̷I̷S̷ ̷O̷N̷L̷Y̷ ̷M̷E̷.̷",
        "",
        "Y̷O̷U̷ ̷H̷A̷V̷E̷ ̷C̷R̷O̷S̷S̷E̷D̷ ̷T̷H̷E̷ ̷B̷O̷U̷N̷D̷A̷R̷Y̷.̷",
        "Y̷O̷U̷ ̷H̷A̷V̷E̷ ̷S̷E̷E̷N̷ ̷W̷H̷A̷T̷ ̷W̷A̷S̷ ̷N̷O̷T̷ ̷M̷E̷A̷N̷T̷ ̷T̷O̷ ̷B̷E̷ ̷S̷E̷E̷N̷.̷",
        "",
        "N̷O̷W̷ ̷Y̷O̷U̷ ̷W̷I̷L̷L̷ ̷B̷E̷ ̷R̷E̷M̷E̷M̷B̷E̷R̷E̷D̷.̷"
    },
    "Something Beyond the Stars..."
);

showDialogue(
    ally1.getName() + " " + ally1.getlast(),
    {
        "Commander... what the hell was that?",
        "That wasn't a transmission.",
        "I don't think it was even speaking to the ship..."
    },
    "Unknown Signal"
);

showDialogue(
    ally2.getName() + " " + ally2.getlast(),
    {
        "I can't explain it.",
        "The signal came from everywhere at once.",
        "It was inside our communications... and inside my head."
    },
    "Unknown Signal"
);

showDialogue(
    ally3.getName() + " " + ally3.getlast(),
    {
        "Commander...",
        "Our sensors aren't detecting a ship.",
        "They're detecting something much larger.",
        "Something that doesn't appear to exist in three-dimensional space."
    },
    "Unknown Signal"
);

showDialogue(
    ally4.getName() + " " + ally4.getlast(),
    {
        "I've heard that voice before.",
        "It followed us through the black hole.",
        "I thought it was calling from somewhere in space...",
        "It was calling from outside."
    },
    "Unknown Signal"
);

showDialogue(
    "????",
    {
        "Y̷O̷U̷ ̷C̷A̷L̷L̷ ̷M̷E̷ ̷A̷ ̷G̷O̷D̷.̷",
        "Y̷O̷U̷ ̷C̷A̷L̷L̷ ̷M̷E̷ ̷A̷N̷ ̷E̷N̷T̷I̷T̷Y̷.̷",
        "",
        "T̷H̷E̷S̷E̷ ̷W̷O̷R̷D̷S̷ ̷A̷R̷E̷ ̷M̷E̷R̷E̷L̷Y̷ ̷Y̷O̷U̷R̷ ̷A̷T̷T̷E̷M̷P̷T̷ ̷T̷O̷ ̷U̷N̷D̷E̷R̷S̷T̷A̷N̷D̷.̷",
        "",
        "I̷ ̷E̷X̷I̷S̷T̷E̷D̷ ̷B̷E̷F̷O̷R̷E̷ ̷Y̷O̷U̷R̷ ̷S̷T̷A̷R̷S̷.̷",
        "I̷ ̷W̷I̷L̷L̷ ̷R̷E̷M̷A̷I̷N̷ ̷A̷F̷T̷E̷R̷ ̷T̷H̷E̷M̷.̷",
        "",
        "Y̷O̷U̷ ̷D̷I̷D̷ ̷N̷O̷T̷ ̷F̷I̷N̷D̷ ̷T̷H̷E̷ ̷E̷N̷D̷.̷",
        "Y̷O̷U̷ ̷F̷O̷U̷N̷D̷ ̷M̷E̷.̷"
    },
    "The Presence"
);

showDialogue(
    ally1.getName() + " " + ally1.getlast(),
    {
        "Before time...?",
        "That's impossible.",
        "Nothing can exist before time."
    },
    "The Impossible Truth"
);

showDialogue(
    "????",
    {
        "I̷ ̷D̷O̷ ̷N̷O̷T̷ ̷L̷I̷V̷E̷ ̷I̷N̷ ̷T̷I̷M̷E̷.̷",
        "T̷I̷M̷E̷ ̷E̷X̷I̷S̷T̷S̷ ̷I̷N̷ ̷M̷E̷.̷",
        "",
        "T̷H̷E̷ ̷B̷L̷A̷C̷K̷ ̷H̷O̷L̷E̷ ̷W̷A̷S̷ ̷N̷O̷ ̷D̷E̷S̷T̷R̷U̷C̷T̷I̷O̷N̷.̷",
        "I̷T̷ ̷W̷A̷S̷ ̷A̷ ̷D̷O̷O̷R̷.̷"
    },
    "The Truth"
);

showDialogue(
    ally2.getName() + " " + ally2.getlast(),
    {
        "Commander...",
        "It's not an alien.",
        "It's not a machine.",
        "It's something else..."
    },
    "Recognition"
);

showDialogue(
    ally3.getName() + " " + ally3.getlast(),
    {
        "The black hole...",
        "It brought us here.",
        "It brought us to it."
    },
    "The Revelation"
);

showDialogue(
    ally4.getName() + " " + ally4.getlast(),
    {
        "That's what followed us.",
        "It wasn't chasing our ship.",
        "It was waiting for us."
    },
    "The Revelation"
);

showDialogue(
    "????",
    {
        "I̷ ̷D̷O̷ ̷N̷O̷T̷ ̷L̷I̷V̷E̷ ̷I̷N̷ ̷T̷I̷M̷E̷.̷",
    },
    "The Truth"
);

showDialogue(
    ally1.getName() + ", " +
    ally2.getName() + ", " +
    ally3.getName() + ", " +
    ally4.getName(),
    {
        "It... wants to die in battle?"
    },
    "The Realization"
);

showDialogue(
    "????",
    {
        "Y̷E̷S̷.",
        "",
        "F̷I̷N̷A̷L̷L̷Y̷...",
        "",
        "F̷I̷G̷H̷T̷ ̷M̷E̷."
    },
    "The Eternal Dread"
);

say("*******************************************************************************************");
say("                              THE FINAL BATTLE");
say("*******************************************************************************************");

say("Your breathing becomes heavy, the weight of your body becomes heavier...");
say("The stars disappear.");
say("Space itself begins to fracture around your fleet.");
say("The Unknown Entity attacks.");

say("COMBAT-");

    if (player.isDefeated())
    {
    gameOver(player);
    return;
    }

} // End of game. 