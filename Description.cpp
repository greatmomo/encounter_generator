#include "Description.h"

Description::Description(Encounter enc) {
	std::ifstream inDescription("RegionData\\" + encounterName + "\\description.txt");
	
	std::string readString;
	while (std::getline(inDescription, readString)) {
		if (readString.size() > 0) {
			encounterDescription.push_back(readString);
		}
	}

	inDescription.close();
}

int Description::getDescriptionVectorSize() {
	return encounterDescription.size();
}

std::vector<std::string> Description::getDescriptionVector() {
	return encounterDescription;
}