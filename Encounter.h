#ifndef ENCOUNTER_H
#define ENCOUNTER_H

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

class Encounter
{
public:
	enum class Region {
		Plains,
		Forest,
		Hills,
		Mountains,
		Marsh,
		Desert,
		Underground,
		Aquatic,
		Underdark,
		Abyss,
		Nine_Hells,
		Gehenna,
		Town,
		Dungeon,
		Random
	};

	Encounter() : Encounter(Region::Random){} // If no region is specified, instantiate with random.
	Encounter(Region);

	Region getRegion();
	std::string enumToText();

private:
	Region region = Region::Random;
};

#endif 