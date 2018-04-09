#pragma once

#include <iostream>

class Data {
public:
	virtual void print() const {}
	virtual Data* clone() const = 0;
	Data* next = NULL;
};
