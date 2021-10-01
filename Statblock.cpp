#include "Statblock.h"

Statblock::Statblock(std::string fileName) {
	// Read file into statblockVector
	std::ifstream inMonster("Monsters\\" + fileName + ".txt");

	std::string readString;
	while (std::getline(inMonster, readString)) {
		if (readString.size() > 0) {
			statblockVector.push_back(readString);
		}
	}

	inMonster.close();

	iter = 0;
	
	//std::cout << statblockVector[iter] << std::endl;
	name = statblockVector[iter];
	iter++;

	//std::cout << statblockVector[iter] << std::endl;
	type = statblockVector[iter];
	iter++;

	//std::cout << statblockVector[iter] << std::endl;
	ac = statblockVector[iter];
	iter++;

	//std::cout << statblockVector[iter] << std::endl;
	hp = statblockVector[iter];
	iter++;

	//std::cout << statblockVector[iter] << std::endl;
	speed = statblockVector[iter];
	iter++;

	//std::cout << statblockVector[iter] << std::endl;
	strength = statblockVector[iter];
	iter++;

	//std::cout << statblockVector[iter] << std::endl;
	dexterity = statblockVector[iter];
	iter++;

	//std::cout << statblockVector[iter] << std::endl;
	constitution = statblockVector[iter];
	iter++;

	//std::cout << statblockVector[iter] << std::endl;
	intelligence = statblockVector[iter];
	iter++;

	//std::cout << statblockVector[iter] << std::endl;
	wisdom = statblockVector[iter];
	iter++;

	//std::cout << statblockVector[iter] << std::endl;
	charisma = statblockVector[iter];
	iter++;

	//std::cout << statblockVector[iter] << std::endl;
	skills = statblockVector[iter];
	iter++;

	//std::cout << statblockVector[iter] << std::endl;
	if (statblockVector[iter] != "#") { // possibly empty
		conditionImmunity = statblockVector[iter];
	}
	else {
		conditionImmunity = "";
	}
	iter++;
	
	//std::cout << statblockVector[iter] << std::endl;
	senses = statblockVector[iter];
	iter++;

	//std::cout << statblockVector[iter] << std::endl;
	if (statblockVector[iter] != "#") { // possibly empty
		languages = statblockVector[iter];
	}
	else {
		languages = "";
	}
	iter++;

	//std::cout << statblockVector[iter] << std::endl;
	cr = statblockVector[iter];
	iter++;

	//std::cout << statblockVector[iter] << std::endl;
	// Abilities can have more than one
	if (statblockVector[iter] != "Abilities") {
		std::cout << "\nERROR: No Abilities tag!\n";
	}
	else {
		iter++; // skip to first ability, or Actions
		while (statblockVector[iter] != "Actions") {
			abilityVector.push_back(statblockVector[iter]);
			iter++;
		}
	}
	//std::cout << abilityVector[0] << std::endl;

	//std::cout << statblockVector[iter] << std::endl;
	// Actions can have more than one
	if (statblockVector[iter] != "Actions") {
		std::cout << "\nERROR: No Actions tag!\n";
	}
	else {
		iter++; // skip to first action, or Legendary Actions
		while (statblockVector[iter] != "Legendary Actions") {
			actionVector.push_back(statblockVector[iter]);
			iter++;
		}
	}
	
	//std::cout << statblockVector[iter] << std::endl;
	// Legendary Actions can have more than one
	if (statblockVector[iter] != "Legendary Actions") {
		std::cout << "\nERROR: No Legendary Actions tag!\n";
	}
	else {
		iter++; // skip to first Legendary Action
		while (statblockVector[iter] != "endfile") {
			legendaryActionVector.push_back(statblockVector[iter]);
			iter++;
		}
	}
}