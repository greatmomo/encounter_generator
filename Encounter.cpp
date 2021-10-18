#include "Encounter.h"

#include <algorithm>

Encounter::Encounter(std::vector<std::string> availableDirectories) {
	srand(int(time(NULL)));
	bool validInput = false;
	while (validInput == false) {
		std::cout << "Enter one of the following regions or \"Random\" to generate an encounter:\n";

		for (auto entry : availableDirectories) {
			std::cout << entry << std::endl;
		}

		std::cout << ">>";
		std::getline(std::cin, region);

		if (region == "Random" || region == "") { // Handle random (and empty)
			std::vector<std::string> temp;
			std::sample(availableDirectories.begin(), availableDirectories.end(), std::back_inserter(temp), 1, std::mt19937{ std::random_device{}() });
			region = temp[0];
		}

		for (auto entry : availableDirectories) {
			if (region == entry) {
				validInput = true;
			}
		}

		system("cls");
	}

	// instantiate other classes
	description = new Description(region);
	environment = new Environment(region);
	highlight = new Highlight(region);

	std::cout << "Generated \"" << region << "\" Biome:\n\n";

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
	// Can we maybe check if multiple entries get the same position and use the longer result?

	std::cout << std::endl;
}

std::string Encounter::getRegion() {
	return region;
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

	if (posLengthVector.size() == 0) {
		result.push_back(str);
		return result;
	}
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