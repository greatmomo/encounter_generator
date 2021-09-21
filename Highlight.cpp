#include "Highlight.h"

Highlight::Highlight(Encounter enc) {
	std::ifstream inHighlight("RegionData\\" + encounterName + "\\encounter.txt");

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