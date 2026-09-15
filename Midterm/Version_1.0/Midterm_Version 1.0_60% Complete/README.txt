================================================================================
                Venture Into The Void - MIDTERM TEXT-BASED GAME
================================================================================

Authors:          Chad Carmickle & Christian Denning
Course:           CSCI 202 - Data Structures
Instructor:       Angela Venable
Project Type:     Midterm Programming Project

================================================================================
                              GAME OVERVIEW
================================================================================

Venture Into The Void (VITV) is a text-based space exploration and combat game.

You play as a starship commander who awakens with fragmented memories after
suffering a serious head injury. Guided by your loyal First Mate, you must
lead your fleet across five dangerous stages of the galaxy.

Your goals are to:
  - Explore points of interest in each stage
  - Gather resources and credits
  - Upgrade your ship with repair bots, weapon upgrades, and hull reinforcements
  - Survive combat encounters against pirates, aliens, and other threats
  - Reach the Edge of Reality and complete the final mission

The game is entirely console-based (text only). There is no graphical interface.

================================================================================
                           HOW TO BUILD AND RUN
================================================================================

Requirements:
  - A C++17 compatible compiler (g++)
  - Linux, macOS, or Windows with WSL / similar environment

Build the game:
  make

Run the game:
  ./main

Clean build files:
  make clean

================================================================================
                              HOW TO PLAY
================================================================================

The game is completely menu-driven. You interact by typing numbers that
correspond to the choices shown on the screen.

----------------------------------------
1. Starting the Game
----------------------------------------

When you launch the program:

  1. You are greeted by your First Mate.
  2. You are asked to enter your Commander name.
     - Use letters only (maximum 10 characters).
     - Press Enter to accept the default name.
  3. You are asked to name your flagship.
     - Press Enter to accept the default name (USS Narwhal).
  4. A short tutorial introduces the basic systems of the game.

----------------------------------------
2. Exploration
----------------------------------------

The game is divided into 5 stages. Each stage contains exactly 4 locations
(points of interest).

At each location you will see:
  - A short story description from your First Mate
  - A numbered list of choices (usually 1 to 4)

Typical location types:

  - Shop              Spend credits on repair bots, weapon upgrades, hull reinforcements, and fleet healing
  - Resource/Currency Gain credits or temporary bonuses
  - Combat / Ambush   Fight enemy ships
  - Boss              Harder combat encounter that usually ends the stage

Simply type the number of the option you want and press Enter.

----------------------------------------
3. Combat System (Turn-Based)
----------------------------------------

When you enter a combat location the battle system activates.

How combat works:

  - Enemies are managed using a Stack.
    The newest enemies appear first and must be dealt with first.

  - Turns are managed using a Queue.
    Only the top enemy from the stack participates in the current battle.

  - On your turn you can typically:
      - Attack the enemy
      - Use repair bots to restore health
      - View your current status

  - Defeat the current enemy to move to the next one in the stack.
  - If your entire fleet reaches 0 HP, the game ends (Game Over).

----------------------------------------
4. Ship and Fleet Management
----------------------------------------

You can view your status at many points in the game. Important information
includes:

  - Commander Name
  - Flagship Name
  - Current Health / Maximum Health
  - Attack Power
  - Attack Speed
  - Number of Repair Bots
  - Credits (currency)

As the story progresses, allies may join your fleet and increase your
overall strength.

----------------------------------------
5. Winning and Losing
----------------------------------------

Victory:
  Successfully complete all five stages and defeat the final threat
  at the Edge of Reality.

Defeat:
  Your flagship and all allied ships reach 0 HP.
  The current Game Over menu offers a restart that skips the intro or a full restart.

================================================================================
                             GAME STRUCTURE
================================================================================

Stage 1 - Awakening & First Contact
  Locations include:
    - Planet Orbit (Shop)
    - Abandoned Station
    - Crowded Continent / Resource areas
    - Distress Signal (Boss)

Stage 2 - Pirate Territory
  Locations include:
    - Cargo Wreck (Combat)
    - Nebula Passage
    - Black Market Station (Shop)
    - Pirate Outpost (Boss)

Stage 3 - Frozen Frontiers
  Locations include:
    - Ice Moon
    - Debris Field
    - Signal Relay (Shop)
    - Corrupted Terrain (Boss)

Stage 4 - Ancient Dangers
  Locations include:
    - Ancient Ruins (Shop)
    - Asteroid Field (Combat)
    - Spaceship Graveyard
    - Black Hole Outskirts (Boss)

Stage 5 - Edge of Reality
  Locations include:
    - dark abyss (Shop)
    - Void Gate (Currency)
    - Unknown Planet (Lore)
    - Unknown Signal (Boss)

  After all four Stage 5 locations are completed, the story proceeds to the
  Edge of Reality and the final boss encounter.

All stages and locations are stored in a custom singly linked list.
The game uses stage completion checks to control campaign progression.

================================================================================
                            CONTROLS SUMMARY
================================================================================

  1, 2, 3, or 4     Select a menu option or location
  Enter             Confirm name entry or continue dialogue

There are no free-text commands. Always choose from the numbered options
that appear on the screen.

================================================================================
                         TIPS FOR NEW COMMANDERS
================================================================================

  - Visit shops early and buy Repair Bots. They are very useful in combat.
  - Pay close attention to your First Mate's dialogue. It often contains
    useful hints about upcoming dangers.
  - Boss locations usually appear as the fourth point of interest in a stage.
  - Manage your health carefully. The current version of the game does not
    have mid-stage checkpoints.
  - Completing stages can attract additional allied ships to your fleet.

================================================================================
                        DATA STRUCTURES USED
================================================================================

This project intentionally implements the following custom data structures.
The C++ Standard Library versions of list, stack, and queue are not used.

  - Singly Linked List
      Stores all stages and their locations.
      Used to track player progression through the campaign.

  - Stack
      Manages enemy encounters.
      Newest enemies must be dealt with first (LIFO order).

  - Queue
      Manages turn order during combat.
      Controls the sequence of actions in battle (FIFO order).

================================================================================
                                CREDITS
================================================================================

Developed by Chad Carmickle and Christian Denning
for the CSCI 202 Midterm Project under Instructor Angela Venable.

================================================================================
                         Enjoy the journey, Commander.
                         The galaxy is waiting.
================================================================================
