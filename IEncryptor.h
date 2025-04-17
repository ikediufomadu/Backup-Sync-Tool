#pragma once

class IEncryptor {
public:
	virtual void encryptFile(const std::string&) = 0;
	virtual ~IEncryptor() {}
};