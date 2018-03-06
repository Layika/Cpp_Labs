#include "Triangle.h"
#include <cmath>

Triangle::Triangle(const int a, const int b, const int c) { this->a = a; this->b = b; this->c = c; }

void Triangle::print(std::ostream& os) const {
	os << "Triangle sides:: " << a << " " << b << " " << c << "\n";
}

double Triangle::countArea() const {
	double x = (a+b+c)/2.0;
	return sqrt(x*(x-a)*(x-b)*(x-c));
}
