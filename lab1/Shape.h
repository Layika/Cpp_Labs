#pragma once
#include <iostream>

// Class describing a shape, circle, square and triangle will inherit from it
class Shape {

public:

	// Method for printing a shape - in case it's a circle - circle will be printed and so on...
	virtual void print(std::ostream& os) const;

	// Method for counting areas of shapes, works as print methos described above
	virtual double countArea() const;

	// Virtual destructor for pointers
	virtual ~Shape();

};

// In Main.cpp global function print is used therefore it need to be created here
void print(const Shape& s);
