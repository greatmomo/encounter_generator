#include "AvailableStatblocks.h"

#include <filesystem>
#include <algorithm>
#include <cctype>
#include <locale>

AvailableStatblocks::AvailableStatblocks(std::string targetDir) {
    targetDirectory = targetDir;

    for (const auto& entry : std::filesystem::directory_iterator(targetDirectory)) {
        availableStatblocks.push_back(entry.path().string());
    }

    for (auto & entry : availableStatblocks) {
        eraseSubStr(entry, targetDirectory + "\\");
        eraseSubStr(entry, ".txt");
    }

    /*for (auto entry : availableStatblocks) {
        std::cout << entry << std::endl;
    }*/
}

std::vector<std::string> AvailableStatblocks::GetAvailableStatblocks() {
	return availableStatblocks;
}

void AvailableStatblocks::eraseSubStr(std::string & mainStr, const std::string & toErase) {
    size_t pos = mainStr.find(toErase);

    if (pos != std::string::npos) {
        mainStr.erase(pos, toErase.length());
    }
}