#include <iostream>
#include <cctype>
#include <chrono>
#include <thread>
#include <limits>

#include "../LevelManager.h"
#include "../../Classes/Ally/Ally.h"


using std::cin;
using std::cout;

std::string PlayerName;


// Creating the levels object for linked list. | extern tells c++ this exists someone else but im using it here. 
extern LinkedList locations;

void buildlevels() {

    // Stage 1
    locations.add("Planet Orbit (Shop)");
    locations.add("Abandoned Station (Lore)");
    locations.add("Crowded Continent (Currency)");
    locations.add("Unknown Distress Signal (Boss)");

    // Stage 2
    locations.add("Cargo Wreck (Combat)");
    locations.add("Nebula Passage (Lore)");
    locations.add("Black Market Station (Shop)");
    locations.add("Pirate Outpost (Boss)");

    // Stage 3
    locations.add("Ice Moon (Currency)");
    locations.add("Debris Field (combat)");
    locations.add("Signal Relay (shop)");
    locations.add("Corrupted Terrain (Boss)");

    // Stage 4
    locations.add("Ancient Ruins (Shop)");
    locations.add("Asteroid Field (Combat)");
    locations.add("Spaceship Graveyard (Currency)");
    locations.add("Black Hole Outskirts (Boss)");

    // Stage 5
    locations.add("dark abyss (Shop)"); 
    locations.add("Void Gate (Currency)");
    locations.add("Unknown Planet (Lore)");
    locations.add("Unknown Signal (Boss)");

    locations.add("??????"); 
    locations.add("??????");
    locations.add("??????");
    locations.add("??????");

    // Final Boss
    locations.add("Edge of Reality (Boss)");

}; 

