#include "Environment.h"

Environment::Environment(Encounter enc) {
	std::ifstream inEnvironment("RegionData\\" + encounterName + "\\environment.txt");

	std::string readString;
	while (std::getline(inEnvironment, readString)) {
		if (readString.size() > 0) {
			encounterEnvironment.push_back(readString);
		}
	}

	inEnvironment.close();
}

int Environment::getEnvironmentVectorSize() {
	return encounterEnvironment.size();
}

std::vector<std::string> Environment::getEnvironmentVector() {
	return encounterEnvironment;
}