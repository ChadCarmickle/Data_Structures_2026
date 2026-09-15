/**************************************************************************************************
 *
 *                                      Shop.cpp
 *
 *                              Spaceship Shop System
 **************************************************************************************************
 Program name: Midterm Text-Based Project.
 Author: Chad Carmickle & Christian Denning
 Date last updated: 9/12/26
 Purpose: Midterm Project.
*/

#include "Shop.h"
#include "../../Classes/Ally/Ally.h"
#include "../../Story/StoryUtils.h"
#include "../../UI/TerminalUI.h"

#include <iostream>
#include <string>
#include <limits>

// =================================================================================================
// Shop numeric input
// =================================================================================================
//
// The normal game uses PlayerInput, which only supports 1-4.
//
// The shop needs 1-5 and Heal Fleet needs 1-6, so the shop uses its own
// numeric input function instead of changing the game's normal input system.
// =================================================================================================

int getShopChoice(int minimum, int maximum)
{
    int input;

    while (true)
    {
        std::cout << "Choose " << minimum << "-" << maximum << ": ";

        if (std::cin >> input && input >= minimum && input <= maximum)
        {
            std::cin.ignore(
                std::numeric_limits<std::streamsize>::max(),
                '\n'
            );

            return input;
        }

        std::cin.clear();
        std::cin.ignore(
            std::numeric_limits<std::streamsize>::max(),
            '\n'
        );

        std::cout << "Invalid input. Please enter a number between "
                  << minimum << " and " << maximum << ".\n";
    }
}


// =================================================================================================
// Visit Shop
// =================================================================================================

void Visitshop(Player& player, int stage)
{
    bool inShop = true;

    // ---------------------------------------------------------------------------------------------
    // Stage-based prices
    // ---------------------------------------------------------------------------------------------

    int repairBotPrice = 100;
    int attackUpgradePrice = 300;
    int hullReinforcementPrice = 250;
    int fleetHealPrice = 50;

    switch (stage)
    {
        case 1:
            repairBotPrice = 100;
            attackUpgradePrice = 300;
            hullReinforcementPrice = 250;
            fleetHealPrice = 50;
            break;

        case 2:
            repairBotPrice = 125;
            attackUpgradePrice = 400;
            hullReinforcementPrice = 325;
            fleetHealPrice = 75;
            break;

        case 3:
            repairBotPrice = 150;
            attackUpgradePrice = 500;
            hullReinforcementPrice = 400;
            fleetHealPrice = 100;
            break;

        case 4:
            repairBotPrice = 175;
            attackUpgradePrice = 600;
            hullReinforcementPrice = 475;
            fleetHealPrice = 125;
            break;

        case 5:
            repairBotPrice = 200;
            attackUpgradePrice = 750;
            hullReinforcementPrice = 550;
            fleetHealPrice = 150;
            break;

        default:
            repairBotPrice = 100;
            attackUpgradePrice = 300;
            hullReinforcementPrice = 250;
            fleetHealPrice = 50;
            break;
    }


    // =============================================================================================
    // MAIN SHOP
    // =============================================================================================

    while (inShop)
    {
        std::cout << "\n";
        std::cout << "========================================\n";
        std::cout << "              SPACE SHOP                \n";
        std::cout << "========================================\n";

        std::cout << "Currency: $" << player.getCurrency() << "\n\n";

        std::cout << "1) Repair Bots          $" << repairBotPrice << "\n";
        std::cout << "2) Ship Upgrades        $" << attackUpgradePrice << "\n";
        std::cout << "3) Hull Reinforcement   $" << hullReinforcementPrice << "\n";
        std::cout << "4) Heal Fleet           $" << fleetHealPrice << "\n";
        std::cout << "5) Leave Shop\n";

        int selection = getShopChoice(1, 5);


        // =========================================================================================
        // 1. REPAIR BOTS
        // =========================================================================================

        if (selection == 1)
        {
            if (player.getCurrency() < repairBotPrice)
            {
                std::cout << "\nYou do not have enough currency.\n";
                continue;
            }

            player.removeCurrency(repairBotPrice);
            player.AddRepairBots(1);

            std::cout << "\nRepair Bot purchased!\n";
            std::cout << "Repair Bots: "
                      << player.getRepairBots()
                      << "\n";

            std::cout << "Currency remaining: $"
                      << player.getCurrency()
                      << "\n";
        }


        // =========================================================================================
        // 2. SHIP UPGRADES
        // =========================================================================================

        else if (selection == 2)
        {
            if (player.getCurrency() < attackUpgradePrice)
            {
                std::cout << "\nYou do not have enough currency.\n";
                continue;
            }

            player.removeCurrency(attackUpgradePrice);

            // Permanently increase player ship attack by 10.
            player.increaseAttack(10);

            std::cout << "\nShip weapon systems upgraded!\n";

            std::cout << "Attack Power: "
                      << player.getAttackPower()
                      << "\n";

            std::cout << "Currency remaining: $"
                      << player.getCurrency()
                      << "\n";
        }


        // =========================================================================================
        // 3. HULL REINFORCEMENT
        // =========================================================================================

        else if (selection == 3)
        {
            if (player.getCurrency() < hullReinforcementPrice)
            {
                std::cout << "\nYou do not have enough currency.\n";
                continue;
            }

            player.removeCurrency(hullReinforcementPrice);

            // Increase maximum health by 25.
            // Spaceship::increaseMaxHealth() also gives the player
            // the additional 25 HP immediately.
            player.increaseMaxHealth(25);

            std::cout << "\nHull reinforcement installed!\n";

            std::cout << "Maximum Health: "
                      << player.getMaxHealth()
                      << "\n";

            std::cout << "Current Health: "
                      << player.getHealth()
                      << "\n";

            std::cout << "Currency remaining: $"
                      << player.getCurrency()
                      << "\n";
        }


        // =========================================================================================
        // 4. HEAL FLEET
        // =========================================================================================

        else if (selection == 4)
        {
            bool inFleetMenu = true;

            while (inFleetMenu)
            {
                std::cout << "\n";
                std::cout << "========================================\n";
                std::cout << "              HEAL FLEET                \n";
                std::cout << "========================================\n";

                std::cout << "Currency: $"
                          << player.getCurrency()
                          << "\n\n";

                // -------------------------------------------------------------------------
                // Player Ship
                // -------------------------------------------------------------------------

                std::cout << "Player Ship - "
                          << player.getHealth()
                          << " / "
                          << player.getMaxHealth()
                          << " HP\n\n";


                // -------------------------------------------------------------------------
                // Build dynamic ally list
                // -------------------------------------------------------------------------
                //
                // Only allies that have joined the fleet are displayed.
                //
                // Example:
                //
                // Ally 1 has not joined
                // Ally 2 has joined
                // Ally 3 has joined
                //
                // The menu becomes:
                //
                // 1) Ally 2
                // 2) Ally 3
                // 3) Heal All Joined Allies
                // 4) Back
                //
                // This prevents the menu number from being tied directly
                // to ally1/ally2/ally3/ally4.
                // -------------------------------------------------------------------------

                int displayedAllies = 0;

                if (ally1.Joined())
                {
                    displayedAllies++;

                    std::cout << displayedAllies
                              << ") "
                              << ally1.getName()
                              << " - "
                              << ally1.getHealth()
                              << " / "
                              << ally1.getMaxHealth()
                              << " HP\n";
                }

                if (ally2.Joined())
                {
                    displayedAllies++;

                    std::cout << displayedAllies
                              << ") "
                              << ally2.getName()
                              << " - "
                              << ally2.getHealth()
                              << " / "
                              << ally2.getMaxHealth()
                              << " HP\n";
                }

                if (ally3.Joined())
                {
                    displayedAllies++;

                    std::cout << displayedAllies
                              << ") "
                              << ally3.getName()
                              << " - "
                              << ally3.getHealth()
                              << " / "
                              << ally3.getMaxHealth()
                              << " HP\n";
                }

                if (ally4.Joined())
                {
                    displayedAllies++;

                    std::cout << displayedAllies
                              << ") "
                              << ally4.getName()
                              << " - "
                              << ally4.getHealth()
                              << " / "
                              << ally4.getMaxHealth()
                              << " HP\n";
                }

                std::cout << "\n";


                // -------------------------------------------------------------------------
                // Menu numbers
                // -------------------------------------------------------------------------

                int healAllChoice = displayedAllies + 1;
                int backChoice = displayedAllies + 2;

                std::cout << healAllChoice
                          << ") Heal All Joined Allies\n";

                std::cout << backChoice
                          << ") Back\n";


                int healChoice = getShopChoice(1, backChoice);


                // -------------------------------------------------------------------------
                // BACK
                // -------------------------------------------------------------------------

                if (healChoice == backChoice)
                {
                    inFleetMenu = false;
                    continue;
                }


                // -------------------------------------------------------------------------
                // HEAL ALL
                // -------------------------------------------------------------------------

                if (healChoice == healAllChoice)
                {
                    if (displayedAllies == 0)
                    {
                        std::cout << "\nNo allies have joined your fleet yet.\n";
                        continue;
                    }

                    if (player.getCurrency() < fleetHealPrice)
                    {
                        std::cout << "\nYou do not have enough currency.\n";
                        continue;
                    }

                    player.removeCurrency(fleetHealPrice);

                    if (ally1.Joined())
                    {
                        ally1.heal(50);
                    }

                    if (ally2.Joined())
                    {
                        ally2.heal(50);
                    }

                    if (ally3.Joined())
                    {
                        ally3.heal(50);
                    }

                    if (ally4.Joined())
                    {
                        ally4.heal(50);
                    }

                    std::cout << "\nAll joined allies have been healed.\n";

                    std::cout << "Currency remaining: $"
                              << player.getCurrency()
                              << "\n";

                    continue;
                }


                // -------------------------------------------------------------------------
                // INDIVIDUAL ALLY
                // -------------------------------------------------------------------------
                //
                // We need to map the displayed number back to the correct ally.
                // -------------------------------------------------------------------------

                int currentAlly = 0;


                // Ally 1
                if (ally1.Joined())
                {
                    currentAlly++;

                    if (healChoice == currentAlly)
                    {
                        if (player.getCurrency() < fleetHealPrice)
                        {
                            std::cout << "\nYou do not have enough currency.\n";
                            continue;
                        }

                        player.removeCurrency(fleetHealPrice);
                        ally1.heal(50);

                        std::cout << "\n"
                                  << ally1.getName()
                                  << " has been healed.\n";

                        std::cout << "Health: "
                                  << ally1.getHealth()
                                  << " / "
                                  << ally1.getMaxHealth()
                                  << " HP\n";

                        std::cout << "Currency remaining: $"
                                  << player.getCurrency()
                                  << "\n";

                        continue;
                    }
                }


                // Ally 2
                if (ally2.Joined())
                {
                    currentAlly++;

                    if (healChoice == currentAlly)
                    {
                        if (player.getCurrency() < fleetHealPrice)
                        {
                            std::cout << "\nYou do not have enough currency.\n";
                            continue;
                        }

                        player.removeCurrency(fleetHealPrice);
                        ally2.heal(50);

                        std::cout << "\n"
                                  << ally2.getName()
                                  << " has been healed.\n";

                        std::cout << "Health: "
                                  << ally2.getHealth()
                                  << " / "
                                  << ally2.getMaxHealth()
                                  << " HP\n";

                        std::cout << "Currency remaining: $"
                                  << player.getCurrency()
                                  << "\n";

                        continue;
                    }
                }


                // Ally 3
                if (ally3.Joined())
                {
                    currentAlly++;

                    if (healChoice == currentAlly)
                    {
                        if (player.getCurrency() < fleetHealPrice)
                        {
                            std::cout << "\nYou do not have enough currency.\n";
                            continue;
                        }

                        player.removeCurrency(fleetHealPrice);
                        ally3.heal(50);

                        std::cout << "\n"
                                  << ally3.getName()
                                  << " has been healed.\n";

                        std::cout << "Health: "
                                  << ally3.getHealth()
                                  << " / "
                                  << ally3.getMaxHealth()
                                  << " HP\n";

                        std::cout << "Currency remaining: $"
                                  << player.getCurrency()
                                  << "\n";

                        continue;
                    }
                }


                // Ally 4
                if (ally4.Joined())
                {
                    currentAlly++;

                    if (healChoice == currentAlly)
                    {
                        if (player.getCurrency() < fleetHealPrice)
                        {
                            std::cout << "\nYou do not have enough currency.\n";
                            continue;
                        }

                        player.removeCurrency(fleetHealPrice);
                        ally4.heal(50);

                        std::cout << "\n"
                                  << ally4.getName()
                                  << " has been healed.\n";

                        std::cout << "Health: "
                                  << ally4.getHealth()
                                  << " / "
                                  << ally4.getMaxHealth()
                                  << " HP\n";

                        std::cout << "Currency remaining: $"
                                  << player.getCurrency()
                                  << "\n";

                        continue;
                    }
                }
            }
        }


        // =========================================================================================
        // 5. LEAVE SHOP
        // =========================================================================================

        else if (selection == 5)
        {
            std::cout << "\nLeaving shop...\n";
            inShop = false;
        }
    }
}
