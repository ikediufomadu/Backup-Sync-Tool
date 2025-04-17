#pragma once

#include <iostream>
#include <string>

class FileMonitor {
public:
	void watchDirectory(const std::string& path) {
		std::cout << "Monitoring directory: " << path << std::endl;
	}
};