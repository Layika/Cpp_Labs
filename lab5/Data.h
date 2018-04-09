#pragma once

#include <iostream>

class Data {
public:
	virtual void print() const {}
	Data* next = NULL;
};
