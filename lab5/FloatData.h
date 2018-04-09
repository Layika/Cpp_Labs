#pragma once

#include "Data.h"
#include <iostream>

class FloatData : public Data {
public:
	FloatData(float val) : val(val) {}
	FloatData(const FloatData& data) : val(data.getData()) {}
	FloatData* clone() const { return new FloatData(*this); }
	bool cmp(const Data& other) const;

	float getData() const { return val; }
	~FloatData() { std::cout << "~FloatData()" << std::endl; }
	virtual void print() const { std::cout << val << " "; }

private:
	float val;
};
