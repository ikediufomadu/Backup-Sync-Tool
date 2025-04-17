#pragma once

#include <filesystem>
#include <fstream>
#include <iostream>

#include "InterfaceStorage.h"
#include "Logger.h"

class LocalStorage : public InterfaceStorage {
	Logger& log;
public:
	LocalStorage() = delete;
	LocalStorage(Logger& logType) : log(logType) {}
	void storeFile(const std::filesystem::directory_entry& entry, const std::string& dest) override {
		std::string backupLog;
		std::ifstream file(entry.path(), std::ios::binary);

		if (!file) {
			std::cerr << "Error: Could not open file " << entry.path() << std::endl;
			return;
		}

		if (!std::filesystem::exists(dest)) {
			std::cerr << "Backup destination directory does not exist: " << dest << std::endl;
			return;
		}

		std::filesystem::path destinationPath = std::filesystem::path(dest) / entry.path().filename();

		std::ofstream outFile(destinationPath, std::ios::binary);

		if (!outFile) {
			backupLog = "Failed to create output file: " + destinationPath.string();
			log.log(backupLog, 12);
			backupLog.clear();
			return;
		}

		outFile << file.rdbuf();
		backupLog = "File backed up locally: " + destinationPath.string();
		log.log(backupLog, 10);
		backupLog.clear();
	}
};
