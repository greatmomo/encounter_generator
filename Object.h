#ifndef OBJECT_H
#define OBJECT_H

#include <fstream>

#include "Encounter.h"

class Object
{
public:
	Object() {} // if no encounter object is passed, at least create a random one
	Object(Encounter);

protected:
	std::string encounterName;
};

#endif