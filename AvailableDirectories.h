#pragma once

#include "Object.h"

class AvailableDirectories
{
public:
	AvailableDirectories(std::string);

	std::vector<std::string> GetAvailableDirectories();

private:
	void eraseSubStr(std::string&, const std::string&);

	std::vector<std::string> availableDirectories;
	std::string targetDirectory;
};

