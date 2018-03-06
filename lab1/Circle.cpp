#include "Circle.h"

#define pi 3.1415

Circle::Circle(const int value) { radius = value; }

void Circle::print(std::ostream& os) const {
	os << "Radius of a circle: " << radius << "\n";
}

double Circle::countArea() const {
	return pi*radius;
}
