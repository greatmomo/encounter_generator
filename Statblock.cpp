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

	if (statblockVector[iter] != "#") { // possibly empty
		savingThrows = statblockVector[iter];
	}
	else {
		savingThrows = "";
	}
	iter++;

	//std::cout << statblockVector[iter] << std::endl;
	if (statblockVector[iter] != "#") { // possibly empty
		skills = statblockVector[iter];
	}
	else {
		skills = "";
	}
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
	if (statblockVector[iter] != "#") { // possibly empty
		senses = statblockVector[iter];
	}
	else {
		senses = "";
	}
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

	if (statblockVector[iter] != "#") { // possibly empty
		proficiencyBonus = statblockVector[iter];
	}
	else {
		proficiencyBonus = "";
	}
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

void Statblock::Print() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(hConsole, 6);
	std::cout << name << std::endl;
	SetConsoleTextAttribute(hConsole, 7);

	std::cout << type << std::endl;

	std::cout << "Armor Class " << ac << std::endl;

	std::cout << "Hit Points " << hp << std::endl;

	std::cout << "Speed " << speed << std::endl;

	std::cout << "----------------------------------------\n";

	std::cout << "  STR       DEX       CON       INT       WIS       CHA\n";
	std::cout << strength << "   " << dexterity << "   " << constitution << "   " << intelligence << "   " << wisdom << "   " << charisma << std::endl;

	std::cout << "----------------------------------------\n";

	// std::cout << "Speed " << saving << std::endl; // need saving throws too

	if (savingThrows != "")
		std::cout << "Saving Throws " << savingThrows << std::endl;

	if (skills != "")
		std::cout << "Skills " << skills << std::endl;

	if (conditionImmunity != "")
		std::cout << "Immunities " << conditionImmunity << std::endl;

	if (senses != "")
		std::cout << "Senses " << senses << std::endl;

	if (languages != "")
		std::cout << "Languages " << languages << std::endl;

	std::cout << "Challenge " << cr; // this line is missing proficiency bonus

	if (proficiencyBonus != "")
		std::cout << "     Proficiency Bonus " << proficiencyBonus << std::endl;

	std::cout << "----------------------------------------\n";

	// TODO: Make ability, action, and legendary action names another color, and remove delimiters (only use the '.')

	for (auto element : abilityVector) {
		std::cout << element << std::endl;
	}

	std::cout << "Actions\n";
	std::cout << "----------------------------------------\n";
	for (auto element : actionVector) {
		std::cout << element << std::endl;
	}

	if (legendaryActionVector.size() != 0) {
		std::cout << "Legendary Actions\n";
		std::cout << "----------------------------------------\n";
		for (auto element : legendaryActionVector) {
			std::cout << element << std::endl;
		}
	}

	std::cout << std::endl << std::endl;
}