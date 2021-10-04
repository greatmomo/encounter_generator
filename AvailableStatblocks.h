#pragma once

#include "Object.h"

class AvailableStatblocks
{
public:
	AvailableStatblocks(std::string);

	std::vector<std::string> GetAvailableStatblocks();

private:
	void eraseSubStr(std::string &, const std::string &);

	std::vector<std::string> availableStatblocks;
	std::string targetDirectory;
};

