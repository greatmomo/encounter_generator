#include "Description.h"

Description::Description(std::string str) {

	str[0] = tolower(str[0]);
	//std::cout << "str = " << str << std::endl << std::endl;

	std::ifstream inDescription("RegionData\\" + str + "\\description.txt");
	
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