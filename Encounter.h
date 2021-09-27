#ifndef ENCOUNTER_H
#define ENCOUNTER_H

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <string>

#include "Description.h"
#include "Environment.h"
#include "Highlight.h"

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
	~Encounter() { delete description; delete environment; delete highlight; system("PAUSE"); };

	Region getRegion();
	std::string enumToText();

	int haveXMonsters(std::string);
	std::vector<std::string> getMonsters(std::string);

private:
	Region region = Region::Random;

	Description *description;
	Environment *environment;
	Highlight *highlight;

	std::string descriptionText;
	std::string environmentText;
	std::string highlightText;

	std::string monsterDelimiter = "#";
	std::vector<std::string> monstersVector;
};

#endif 