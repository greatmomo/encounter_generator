#include "Object.h"

Object::Object(Encounter enc) {
    encounterName = enc.enumToText();
    encounterName[0] = tolower(encounterName[0]);
    std::cout << "encounterName = " << encounterName << std::endl << std::endl;
}