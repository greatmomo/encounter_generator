// encounter_generator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Encounter.h"

#include "Statblock.h"

int main()
{
    Encounter generatedEncounter = Encounter(Encounter::Region::Plains); // test with plains before implementing others

    for (int i = 0; i < generatedEncounter.haveXMonsters(); i++) {

    }

    Statblock wolfStats = Statblock("Wolf");
    wolfStats.Print();
}

// find out how to make windows (I have a bookmark)
// make syntax for standardized monster/trap/etc reading (ex. everything between two '#' symbols)
// figure out how to make monster/trap names bold
// implement reading out of which monsters or traps should be posted
// create monster and trap classes that post stat blocks
// 
// allow input of custom entries that are then saved to the proper files?