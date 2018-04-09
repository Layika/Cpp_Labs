#pragma once

#include "Data.h"
#include <iostream>

class IntData : public Data {
public:
	IntData(int val) : val(val) {}
	~IntData() { std::cout << "~IntData()" << std::endl; }
	IntData(const IntData& data) : val(data.getData()) {}
	IntData* clone() const { return new IntData(*this); }
	virtual bool cmp(const IntData& toCmp) const { if (this->val == toCmp.val) return true; else return false; } 

	int getData() const { return val; }
	virtual void print() const { std::cout << val << " "; }

private:
	int val;
};
