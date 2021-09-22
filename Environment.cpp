#include "Environment.h"

Environment::Environment(std::string str) {
	str[0] = tolower(str[0]);
	//std::cout << "str = " << str << std::endl << std::endl;

	std::ifstream inEnvironment("RegionData\\" + str + "\\environment.txt");

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