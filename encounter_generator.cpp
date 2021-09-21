// encounter_generator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "Encounter.h"

int main()
{
    Encounter generatedEncounter = Encounter(Encounter::Region::Plains); // test with plains before implementing others



    system("PAUSE");
}

// Needed classes: Encounter, "Objects"
// Lots of this file needs to be moved into Encounter class probably
// Also move Description/Environment/Encounter stuff into their own classes that all derive from a parent Object class