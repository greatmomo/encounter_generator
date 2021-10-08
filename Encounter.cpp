#include "Encounter.h"

#include <algorithm>

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
	if (highlight->getHighlightVectorSize() > 0) {
		std::vector<std::string> resultVector = highlightSubstrings(highlightText);

		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		bool golden = false;
		for (auto entry : resultVector) {
			if (golden) {
				SetConsoleTextAttribute(hConsole, 6);
				std::cout << entry;
				golden = false;
			}
			else {
				SetConsoleTextAttribute(hConsole, 7);
				std::cout << entry;
				golden = true;
			}
		}
		std::cout << std::endl << std::endl;
	}

	// TODO: Gnoll and Gnoll Pack Lord are still causing issues, otherwise the resultVector looks good

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

std::string Encounter::getDescription() {
	return descriptionText;
}

std::string Encounter::getEnvironment() {
	return environmentText;
}

std::string Encounter::getHighlight() {
	return highlightText;
}

std::vector<std::string> Encounter::highlightSubstrings(std::string str) {
	int pos;
	std::vector<std::string> result;

	std::vector<std::vector<int>> posLengthVector;

	AvailableStatblocks aS("\Monsters");
	std::vector<std::string> availableStatblocks = aS.GetAvailableStatblocks();

	for (auto entry : availableStatblocks) {
		pos = str.find(entry);
		if (pos != std::string::npos) {
			posLengthVector.push_back(std::vector<int>{ pos, (int)entry.length() });
		}
	}

	if (posLengthVector.size() == 0)
		return result;
	// put in position order for substringing
	sort(posLengthVector.begin(), posLengthVector.end());

	result.push_back(str.substr(0, posLengthVector[0][0]));
	pos = posLengthVector[0][1];

	for (size_t i = 0; i < posLengthVector.size(); i++) {
		result.push_back(str.substr(posLengthVector[i][0], posLengthVector[i][1]));

		if (i == posLengthVector.size() - 1) {
			result.push_back(str.substr(posLengthVector[i][0] + posLengthVector[i][1]));
		}
		else {
			result.push_back(str.substr(posLengthVector[i][0] + posLengthVector[i][1], posLengthVector[i + 1][0] - (posLengthVector[i][0] + posLengthVector[i][1])));
		}
	}

	return result;
}