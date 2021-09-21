#ifndef HIGHLIGHT_H
#define HIGHLIGHT_H

#include "Object.h"

class Encounter;

class Highlight :
    public Object
{
public:
    Highlight(Encounter);

    int getHighlightVectorSize();
    std::vector<std::string> getHighlightVector();

private:
    std::vector<std::string> encounterHighlight;
};

#endif