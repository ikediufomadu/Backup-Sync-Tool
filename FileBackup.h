#pragma once

class FileBackup {  // Handles file backup
public:
	void backupFile(const std::string& src, const std::string& dest);
	void backupFile(IStorage& storage, const std::string& src, const std::string& dest) {
		storage.storeFile(src, dest);
	}
};