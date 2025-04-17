#pragma once
#include <filesystem>
#include <string>

class IStorage {
public:
	virtual ~IStorage() = default;
	virtual void store(const std::filesystem::directory_entry&, const std::string& dest) = 0;
};