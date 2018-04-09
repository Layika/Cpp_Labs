#pragma once

#include "Data.h"
#include <iostream>

class FloatData : public Data {
public:
	FloatData(float val) : val(val) {}
	FloatData(const FloatData& data) : val(data.getData()) {}
	FloatData* clone() const { return new FloatData(*this); }
	virtual bool cmp(const FloatData& toCmp) const { if (this->val == toCmp.val) return true; else return false; } 

	float getData() const { return val; }
	~FloatData() { std::cout << "~FloatData()" << std::endl; }
	virtual void print() const { std::cout << val << " "; }

private:
	float val;
};
