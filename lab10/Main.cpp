// DO NOT CHANGE THIS FILE, file given by a lecturer
#include <iostream>
#include "Point.h"


int main() {

  const Point s1(0, 1);
  const Point s2(-5, 2);
  std::cout << "s1 " << s1.wsp<0>() <<  " " << s1.wsp<1>() << std::endl;
  std::cout << "s2 " << s2.wsp<0>() <<  " " << s2.wsp<1>() << std::endl;

  std::cout << Point::min(s1.wsp<0>(), s2.wsp<0>()) << " " << Point::min(s1.wsp<1>(), s2.wsp<1>()) << std::endl;
  std::cout << Point::max(s1.wsp<0>(), s2.wsp<0>()) << " " << Point::max(s1.wsp<1>(), s2.wsp<1>()) << std::endl;

  std::cout << Point::min(s1, s2).wsp<0>() << " " << Point::min(s1, s2).wsp<1>() << std::endl;
  std::cout << Point::max(s1, s2).wsp<0>() << " " << Point::max(s1, s2).wsp<1>() << std::endl;

  std::cout << "comparison: " << (s1 < s2) << " " << (s2 < s1) << std::endl;
}
