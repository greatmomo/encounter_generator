#ifndef ENCOUNTER_H
#define ENCOUNTER_H

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <string>
#include <random>

#include "Description.h"
#include "Environment.h"
#include "Highlight.h"
#include "AvailableStatblocks.h"

class Encounter
{
public:
	//Encounter() : Encounter("Random") {} // If no region is specified, instantiate with random.
	Encounter(std::vector<std::string>);
	~Encounter() { delete description; delete environment; delete highlight;};

	std::string getRegion();

	int haveXMonsters(std::string);

	std::string getDescription();
	std::string getEnvironment();
	std::string getHighlight();

	std::vector<std::string> highlightSubstrings(std::string);

private:
	std::string region = "Random";

	Description *description;
	Environment *environment;
	Highlight *highlight;

	std::string descriptionText;
	std::string environmentText;
	std::string highlightText;

	std::string monsterDelimiter = "#";

	bool validInput;
};

#endif 