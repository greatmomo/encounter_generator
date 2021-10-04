// encounter_generator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Encounter.h"
#include "Statblock.h"
#include "AvailableStatblocks.h"

int main()
{
    Encounter generatedEncounter = Encounter(Encounter::Region::Plains); // test with plains before implementing others

    /*std::vector<std::string> monstersVector = generatedEncounter.getMonsters(generatedEncounter.getHighlight());
    for (int i = 0; i < monstersVector.size(); i++) {
        Statblock forPrint = Statblock(monstersVector[i]);
        forPrint.Print();
    }*/

    AvailableStatblocks aS("\Monsters");
    std::vector<std::string> availableStatblocks = aS.GetAvailableStatblocks();

    for (auto entry : availableStatblocks) {
        std::cout << entry << std::endl;
    }
}

// Use that scan information to search the highlight string for any available statblocks, and instead remove the '#' delimiters
// 
// find out how to make windows (I have a bookmark)
// add traps?
// add obstacles or other things with DCs?
// figure out how to make monster/trap names bold
// 
// allow input of custom entries that are then saved to the proper files?