#include "FileSystem.h"

void FileSystem::printName(std::ostream& os, unsigned int spaces) const {
  os << std::string(spaces, ' ') << name << std::endl;
}
