#ifndef DESCRIPTION_H
#define DESCRIPTION_H

#include "Object.h"

class Encounter;

class Description :
    public Object
{
public:
    Description(Encounter);

    int getDescriptionVectorSize();
    std::vector<std::string> getDescriptionVector();

private:
    std::vector<std::string> encounterDescription;
};

#endif