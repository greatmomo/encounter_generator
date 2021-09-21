#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include "Object.h"

class Encounter;

class Environment :
    public Object
{
public:
    Environment(Encounter);

    int getEnvironmentVectorSize();
    std::vector<std::string> getEnvironmentVector();

private:
    std::vector<std::string> encounterEnvironment;
};

#endif