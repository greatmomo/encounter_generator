#pragma once

#include "Object.h"

class Statblock
{
private:
	std::string name;
	std::string type;
	std::string ac;
	std::string hp;
	std::string speed;
	std::string strength;
	std::string dexterity;
	std::string constitution;
	std::string intelligence;
	std::string wisdom;
	std::string charisma;
	std::string savingThrows; // possibly empty
	std::string skills;
	std::string damageResistances; // possibly empty
	std::string damageImmunity; // possibly empty
	std::string conditionImmunity; // possibly empty
	std::string senses;
	std::string languages; // possibly empty
	std::string cr;
	std::string proficiencyBonus; // possibly empty
	std::string abilities;
	std::string actions;
	std::string legendaryActions; // possibly empty

	std::vector<std::string> statblockVector;
	int iter;

	std::vector<std::string> abilityVector;
	std::vector<std::string> actionVector;
	std::vector<std::string> legendaryActionVector;

public:
	Statblock(std::string);
	void Print();
};

