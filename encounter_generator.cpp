// encounter_generator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Encounter.h"
#include "Statblock.h"
#include "AvailableStatblocks.h"
#include "AvailableDirectories.h"

int main()
{
    AvailableDirectories aD("\RegionData");
    std::vector<std::string> availableRegions = aD.GetAvailableDirectories();

    AvailableStatblocks aS("\Monsters");
    std::vector<std::string> availableStatblocks = aS.GetAvailableStatblocks();

    Encounter* generatedEncounter;

    bool repeat = false;
    do {
        generatedEncounter = new Encounter(availableRegions);

        for (auto entry : availableStatblocks) {
            size_t pos = generatedEncounter->getHighlight().find(entry);

            if (pos != std::string::npos) {
                Statblock forPrint = Statblock(entry);
                forPrint.Print();
            }
        }

        // TODO: make this throw out invalid input
        std::cout << "Do you want to generate another encounter? Y/N...";
        char exitQuery;
        exitQuery = std::cin.get();
        while (1) {
            if (exitQuery == 'Y' || exitQuery == 'y') {
                repeat = true;
                break;
            } else if (exitQuery == 'N' || exitQuery == 'n') {
                repeat = false;
                break;
            }
            else {
                exitQuery = std::cin.get();
            }
        }
        delete generatedEncounter;
        system("cls");
        std::cin.clear();
        std::cin.ignore(INT_MAX, '\n');
    } while (repeat);
}

// find out how to make windows (I have a bookmark) - it's impossible for some reason
// add traps?
// add obstacles or other things with DCs?
//
// Search TODO