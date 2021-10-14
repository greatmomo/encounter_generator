#include "AvailableDirectories.h"

#include <filesystem>
#include <algorithm>
#include <cctype>
#include <locale>

AvailableDirectories::AvailableDirectories(std::string targetDir) {
    targetDirectory = targetDir;

    for (const auto& entry : std::filesystem::directory_iterator(targetDirectory)) {
        availableDirectories.push_back(entry.path().string());
    }

    for (auto& entry : availableDirectories) {
        eraseSubStr(entry, targetDirectory + "\\");
        eraseSubStr(entry, ".txt");
    }

    for (auto entry : availableDirectories) {
        std::cout << entry << std::endl;
    }
}

std::vector<std::string> AvailableDirectories::GetAvailableDirectories() {
    return availableDirectories;
}

void AvailableDirectories::eraseSubStr(std::string& mainStr, const std::string& toErase) {
    size_t pos = mainStr.find(toErase);

    if (pos != std::string::npos) {
        mainStr.erase(pos, toErase.length());
    }
}