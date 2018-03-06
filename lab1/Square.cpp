#include "Square.h"

Square::Square(const int side) { this->side = side; }

void Square::print(std::ostream& os) const {
	os << "Square side: " << side << "\n";
}

double Square::countArea() const{
	return side*side;
}
