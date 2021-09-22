#ifndef DESCRIPTION_H
#define DESCRIPTION_H

#include "Object.h"

class Description
{
public:
    Description(std::string);

    int getDescriptionVectorSize();
    std::vector<std::string> getDescriptionVector();

private:
    std::vector<std::string> encounterDescription;
};

#endif