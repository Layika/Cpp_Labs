#pragma once

#include "Data.h"
#include <string>
#include <iostream>

class StringData : public Data {
public:
	StringData(std::string str) : str(str) {}
	~StringData() { std::cout << "~StringData()" << std::endl; }
	StringData(const StringData& data) : str(data.getData()) {}
	StringData* clone() const { return new StringData(*this); }
	bool cmp(Data& other) const;

	std::string getData() const { return str; }
	virtual void print() const { std::cout << str << " "; }

private:
	std::string str;
};
