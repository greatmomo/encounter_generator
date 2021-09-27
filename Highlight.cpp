#include "Highlight.h"

Highlight::Highlight(std::string str) {
	str[0] = tolower(str[0]);
	//std::cout << "str = " << str << std::endl << std::endl;

	std::ifstream inHighlight("RegionData\\" + str + "\\highlight.txt");

	std::string readString;
	while (std::getline(inHighlight, readString)) {
		if (readString.size() > 0) {
			encounterHighlight.push_back(readString);
		}
	}

	inHighlight.close();
}

int Highlight::getHighlightVectorSize() {
	return encounterHighlight.size();
}

std::vector<std::string> Highlight::getHighlightVector() {
	return encounterHighlight;
}