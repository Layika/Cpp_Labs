#pragma once
#include <string>
#include <iostream>

class FileSystem {
public:
  virtual ~FileSystem() {};
  void setName(std::string name) { this->name = name; }
  std::string getName() const { return name; }
  void printName(std::ostream& os, unsigned int spaces) const;
  unsigned int getNameLength() const { return getName().length(); }

private:
  std::string name;
};
