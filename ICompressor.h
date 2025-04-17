#pragma once

class ICompressor {
public:
	virtual void compressFile(const std::string&) = 0;
	virtual ~ICompressor() {}
};