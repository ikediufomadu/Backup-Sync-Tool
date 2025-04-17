#pragma once

#include <iostream>
#include <filesystem>

#include "InterfaceStorage.h"

class CloudStorage : public InterfaceStorage {
public:
	void storeFile(const std::filesystem::directory_entry& src, const std::string& dest) override {
		std::cout << "Uploading " << src << " to cloud at " << dest << std::endl;
	}
};