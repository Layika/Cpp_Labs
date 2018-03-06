#pragma once
#include <iostream>
#include "Shape.h"

// Class describing a circle
class Circle : public Shape {

public:
	// Constructr giving value to circle radius
	Circle(const int value);

	// Virtual method for printing (will print circle's radius)
	virtual void print(std::ostream& os) const;

	// Virtual method for counting area of a circle
	virtual double countArea() const;

private:
	int radius;
};
