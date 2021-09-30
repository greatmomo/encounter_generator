#pragma once

#include <iostream>

class Statblock
{
public:
	Statblock(std::string);

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
	std::string skills;
	std::string conditionImmunity; // posibly empty
	std::string senses;
	std::string languages; // posibly empty
	std::string cr;
	std::string abilities;
	std::string actions;
	std::string legendaryActions; // posibly empty
};

