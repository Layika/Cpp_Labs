#pragma once
#include <iostream>
#include "Shape.h"

// Class describing a square
class Square : public Shape {

public:
	// Constructr giving value to square side
	Square(const int side);

	// Virtual method for printing (will print square's side value)
	virtual void print(std::ostream& os) const;

	// Virtual method for counting area of a square
	virtual double countArea() const;

private:
	int side;
};
