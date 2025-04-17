#include <iostream>
#include <shlobj.h>
#include <string>
#include <windows.h>

#include "BackupService.h"
#include "LocalStorage.h"

std::string getFolderPath(REFKNOWNFOLDERID folderID) {
	PWSTR path = NULL;
	if (SUCCEEDED(SHGetKnownFolderPath(folderID, 0, NULL, &path))) {
		std::wstring widePath(path);
		CoTaskMemFree(path);  // Free memory
		return std::string(widePath.begin(), widePath.end()); // Convert to string
	}
	return "";
}

std::string getBackupFolder(const int choice) {
    PWSTR path = NULL;
    HRESULT hr;

    // Determine folder by user choice
    switch (choice) {
    case 1:
        hr = SHGetKnownFolderPath(FOLDERID_Desktop, 0, NULL, &path);
        break;
    case 2:
        hr = SHGetKnownFolderPath(FOLDERID_Documents, 0, NULL, &path);
        break;
    case 3:
        hr = SHGetKnownFolderPath(FOLDERID_Downloads, 0, NULL, &path);
        break;
    default:
        std::cerr << "Invalid folder choice.\n";
        return "";
    }

    // Handle result
    if (SUCCEEDED(hr)) {
        std::wstring ws(path);
        CoTaskMemFree(path);  // Clean up
        return std::filesystem::path(ws).string();  // Convert to std::string
    }
    else {
        std::cerr << "Failed to retrieve folder path.\n";
        return "";
    }
}

int main() {
	Logger log;
	LocalStorage local(log);
	BackupService backupService(local, log);

	std::cout << "Desktop: " << getFolderPath(FOLDERID_Desktop) << std::endl;
	backupService.backup(getFolderPath(FOLDERID_Desktop), getBackupFolder(1));

	std::cout << "Documents: " << getFolderPath(FOLDERID_Documents) << std::endl;
	backupService.backup(getFolderPath(FOLDERID_Documents), getBackupFolder(1));

	std::cout << "Pictures: " << getFolderPath(FOLDERID_Pictures) << std::endl;
	backupService.backup(getFolderPath(FOLDERID_Pictures), getBackupFolder(1));

	std::cout << "Music: " << getFolderPath(FOLDERID_Music) << std::endl;
	backupService.backup(getFolderPath(FOLDERID_Music), getBackupFolder(1));

	return 0;
}
