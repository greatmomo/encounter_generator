#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include "Object.h"

class Environment
{
public:
    Environment(std::string);

    int getEnvironmentVectorSize();
    std::vector<std::string> getEnvironmentVector();

private:
    std::vector<std::string> encounterEnvironment;
};

#endif