// encounter_generator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Encounter.h"
#include "Statblock.h"
#include "AvailableStatblocks.h"

int main()
{
    Encounter generatedEncounter = Encounter(Encounter::Region::Plains); // test with plains before implementing others

    AvailableStatblocks aS("\Monsters");
    std::vector<std::string> availableStatblocks = aS.GetAvailableStatblocks();

    for (auto entry : availableStatblocks) {
        size_t pos = generatedEncounter.getHighlight().find(entry);

        if (pos != std::string::npos) {
            Statblock forPrint = Statblock(entry);
            forPrint.Print();
        }
    }
}

// find out how to make windows (I have a bookmark)
// add traps?
// add obstacles or other things with DCs?
// 
// allow input of custom entries that are then saved to the proper files?