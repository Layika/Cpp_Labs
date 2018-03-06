#pragma once
#include <iostream>
#include "Shape.h"

// Class describing a triangle
class Triangle : public Shape {

public:
	// Constructr giving value to triangle radius
	Triangle(const int a, const int b, const int c);

	// Virtual method for printing (will print triangle's sides)
	virtual void print(std::ostream& os) const;

	// Virtual method for counting area of a triangle
	virtual double countArea() const;

private:
	int a;
	int b;
	int c;
};
