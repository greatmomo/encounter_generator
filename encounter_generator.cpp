// encounter_generator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <fstream>
#include <string>

#include "Encounter.h"

int main()
{
    Encounter generatedEncounter = Encounter(Encounter::Region::Plains); // test with plains before implementing others

    std::string encounterName = generatedEncounter.enumToText();
    encounterName[0] = tolower(encounterName[0]);
    std::cout << "encounterName = " << encounterName << std::endl << std::endl;

    // open all files
    std::ifstream inDescription("RegionData\\" + encounterName + "\\description.txt");
    std::ifstream inEnvironment("RegionData\\" + encounterName + "\\environment.txt");
    std::ifstream inEncounter("RegionData\\" + encounterName + "\\encounter.txt");

    std::vector<std::string> encounterDescription;
    std::vector<std::string> encounterEnvironment;
    std::vector<std::string> encounterEncounter;

    // read files line by line into vectors
    std::string readString;
    while (std::getline(inDescription, readString)) {
        if (readString.size() > 0) {
            encounterDescription.push_back(readString);
        }
    }
    while (std::getline(inEnvironment, readString)) {
        if (readString.size() > 0) {
            encounterEnvironment.push_back(readString);
        }
    }
    while (std::getline(inEncounter, readString)) {
        if (readString.size() > 0) {
            encounterEncounter.push_back(readString);
        }
    }

    inDescription.close();
    inEnvironment.close();
    inEncounter.close();

    srand(time(NULL));
    // print random member of each vector
    if (encounterDescription.size() > 0)
        std::cout << encounterDescription[rand() % encounterDescription.size()] << " ";
    if (encounterEnvironment.size() > 0)
        std::cout << encounterEnvironment[rand() % encounterEnvironment.size()] << " ";
    if (encounterEncounter.size() > 0)
        std::cout << encounterEncounter[rand() % encounterEncounter.size()] << std::endl << std::endl;

    system("PAUSE");
}

// Needed classes: Encounter, "Objects"
// Lots of this file needs to be moved into Encounter class probably
// Also move Description/Environment/Encounter stuff into their own classes that all derive from a parent Object class