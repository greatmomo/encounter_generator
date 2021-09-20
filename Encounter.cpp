#include "Encounter.h"

Encounter::Encounter(Region r) {
	srand(time(NULL));
	region = r;
	while (region == Region::Random) { // Random is not allowed, reroll
		region = Region(rand() % static_cast<int>(Region::Random));
	}
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