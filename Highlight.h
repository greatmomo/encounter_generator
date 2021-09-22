#ifndef HIGHLIGHT_H
#define HIGHLIGHT_H

#include "Object.h"

class Highlight
{
public:
    Highlight(std::string);

    int getHighlightVectorSize();
    std::vector<std::string> getHighlightVector();

private:
    std::vector<std::string> encounterHighlight;
};

#endif