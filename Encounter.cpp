#include "Encounter.h"

Encounter::Encounter(Region r) {
	srand(int(time(NULL)));
	region = r;
	while (region == Region::Random) { // Random is not allowed, reroll
		region = Region(rand() % static_cast<int>(Region::Random));
	}

	// instantiate other classes
	description = new Description(this->enumToText());
	environment = new Environment(this->enumToText());
	highlight = new Highlight(this->enumToText());

	std::cout << "Generated \"" << this->enumToText() << "\" Biome:\n\n";

	descriptionText = description->getDescriptionVector()[rand() % description->getDescriptionVectorSize()];
	environmentText = environment->getEnvironmentVector()[rand() % environment->getEnvironmentVectorSize()];
	highlightText = highlight->getHighlightVector()[rand() % highlight->getHighlightVectorSize()];
	//highlightText = highlight->getHighlightVector()[5]; //Test with monsters

	// print random member of each vector
	if (description->getDescriptionVectorSize() > 0)
		std::cout << descriptionText << " ";
	if (environment->getEnvironmentVectorSize() > 0)
		std::cout << environmentText << " ";
	if (highlight->getHighlightVectorSize() > 0)
		std::cout << highlightText << std::endl << std::endl;

	std::cout << "This encounter has " << haveXMonsters(highlightText) << " monster types.\n\n";
	
	if (haveXMonsters(highlightText) >= 1) {
		monstersVector = getMonsters(highlightText);
		for (int i = 0; i < monstersVector.size(); i++) {
			std::cout << monstersVector[i] << "\n";
		}
	}

	std::cout << std::endl;
}

Encounter::Region Encounter::getRegion() {
	return region;
}

std::string Encounter::enumToText() {
	switch (region) {
	case Region::Plains:
		return "Plains";
		break;
	case Region::Forest:
		return "Forest";
		break;
	case Region::Hills:
		return "Hills";
		break;
	case Region::Mountains:
		return "Mountains";
		break;
	case Region::Marsh:
		return "Marsh";
		break;
	case Region::Desert:
		return "Desert";
		break;
	case Region::Underground:
		return "Underground";
		break;
	case Region::Aquatic:
		return "Aquatic";
		break;
	case Region::Underdark:
		return "Underdark";
		break;
	case Region::Abyss:
		return "Abyss";
		break;
	case Region::Nine_Hells:
		return "Nine Hells";
		break;
	case Region::Gehenna:
		return "Gehenna";
		break;
	case Region::Town:
		return "Town";
		break;
	case Region::Dungeon:
		return "Dungeons";
		break;
	default:
		return "Invalid";
		break;
	}
}

int Encounter::haveXMonsters(std::string line) {
	size_t pos;
	int count = 0;
	while (!line.empty()) {
		pos = line.find(monsterDelimiter);
		//std::cout << int(pos) << std::endl;
		if (pos > 0 && pos < line.length()) {
			line = line.substr(pos + 1, line.length());
			count++;
		}
		else {
			line = "";
		}
	}
	if (count > 1 && count % 2 == 0) {
		return count / 2;
	}
	else {
		return 0;
	}
}

std::vector<std::string> Encounter::getMonsters(std::string line) {
	size_t startPos = 0, endPos = 0;
	std::vector<std::string> monstersVector;

	while (!line.empty()) {
		startPos = line.find(monsterDelimiter);
		endPos = startPos + line.substr(startPos + 1, line.length()).find(monsterDelimiter) - startPos;

		if (endPos >= line.length())
			break;
		monstersVector.push_back(line.substr(startPos + 1, endPos));
		//std::cout << int(pos) << std::endl;

		if (endPos < line.length()) {
			line = line.substr(startPos + endPos + 2);
		}
		else {
			line = "";
		}
	}

	return monstersVector;
}