#pragma once

#include <filesystem>
#include <unordered_set>

#include "InterfaceStorage.h"
#include "Logger.h"

class BackupService {
private:
	Logger& log;
	InterfaceStorage& storage;
	std::string backupLog;
	std::unordered_set<std::string> supportedExtensions = {
		// Word Documents
	".docx", ".docm", ".dotx", ".dotm", ".doc",

	// Excel Files
	".xlsx", ".xlsm", ".xlsb", ".xls",

	// PowerPoint Files
	".pptx", ".pptm", ".potx", ".potm", ".ppsx", ".ppsm",

	// PDF
	".pdf",

	// Images
	".jpg", ".jpeg", ".png", ".bmp", ".gif", ".tif", ".tiff",
	".svg", ".psd", ".ai", ".emf", ".wmf", ".eps",

	// 3D Modeling/Printing
	".3mf", ".cool", ".glb", ".gltf", ".obj", ".stl",

	// Audio/Video
	".3g2", ".3gp", ".3gpp", ".asf", ".avi", ".m2ts", ".m4a",
	".m4v", ".mkv", ".mov", ".mp3", ".mp4", ".mp4v", ".mts",
	".ts", ".wav", ".webm", ".wma", ".wmv",

	// Apple Files
	".movie", ".pages", ".pict", ".sketch",

	// Adobe Files
	".ai", ".pdf", ".psb", ".psd",

	// Other Files
	".rtf", ".asp", ".htm", ".html", ".txt", ".dif", ".slk",
	".xps", ".xml", ".xmlx", ".mht", ".mhtml", ".ods", ".csv", ".dif"
	};

	bool isSupportedExtension(const std::filesystem::path& ext) {
		std::cout << ext.extension().string() << std::endl;
		return supportedExtensions.find(ext.extension().string()) != supportedExtensions.end();
	}

	std::unordered_set<char> getAllDrives() {
		std::unordered_set<char> drives;
		DWORD driveMask = GetLogicalDrives();

		for (char letter = 'A'; letter <= 'Z'; ++letter) {
			if (driveMask & (1 << (letter - 'A'))) {
				drives.insert(letter);
			}
		}

		return drives;
	}

public:
	BackupService() = delete;
	BackupService(InterfaceStorage& storageType, Logger& logType) : storage(storageType), log(logType) {}

	void backup(const std::string& src, const std::string& dest) {
		// see if I can make this multithreaded for time save
		// encrypt files after

		namespace fs = std::filesystem;
		try {
			for (const auto& entry : fs::directory_iterator(src)) {
				if (entry.is_regular_file() && isSupportedExtension(entry.path())) {
					backupLog = "Supported file found: " + entry.path().string();
					log.log(backupLog);
					backupLog.clear();
					storage.storeFile(entry, dest);
				}
				else if (entry.is_directory()) {
					backupLog = "Directory found: " + entry.path().string();
					log.log(backupLog);
					backupLog.clear();
					backup(entry.path().string(), dest);
				}
				else {
					backupLog = "Unsupported file found : " + entry.path().string();
					log.log(backupLog, 12);
					backupLog.clear();
				}
			}
		}
		catch (const fs::filesystem_error& e) {
			std::cerr << "Filesystem error: " << e.what() << std::endl;
		}
	}
};