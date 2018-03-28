#pragma once

#include <iostream>

class Data {
public:
	virtual void print() const {} 

private:
	Data* next = NULL;
	Data* prev = NULL;
	unsigned int size;
};

// std::ostream& operator<<(std::ostream& os, const Data data);