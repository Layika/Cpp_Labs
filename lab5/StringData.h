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
	virtual bool cmp(const StringData& toCmp) const { if (this->str == toCmp.str) return true; else return false; } 

	std::string getData() const { return str; }
	virtual void print() const { std::cout << str << " "; }

private:
	std::string str;
};
