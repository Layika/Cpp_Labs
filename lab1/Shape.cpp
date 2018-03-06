#include "Shape.h"

Shape::~Shape() {}

double Shape::countArea() const {
	return 0;
}

void Shape::print(std::ostream& os) const { }

void print(const Shape& s) {
	s.print(std::cout);
}
