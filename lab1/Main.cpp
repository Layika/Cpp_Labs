// File given by a lecturer, nothing can be changed here

#include <iostream>
#include "Square.h"
#include "Circle.h"
#include "Triangle.h"

int main() {
  Square s(4);
  Triangle t(3,2,4);
  const Circle c(3);

  print(s);
  print(t);
  print(c);

  Shape* shape = new Square(7);
  print(*shape);
  delete shape;

  shape = new Circle(7);
  print(*shape);
  delete shape;

  const Shape* all[] = {&s, &s, &c, &t, &c};
  for (unsigned int idx = 0; idx < sizeof(all)/sizeof(Shape*); ++idx ) {
    const Shape* shp = all[idx];
    shp->print(std::cout);
    std::cout << shp->countArea() << std::endl;
  }
}
