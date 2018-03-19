#include "Dir.h"
#include "FileSystem.h"

Dir::~Dir() {
  std::cout << "Deleting Dir: " << getName() << std::endl;
  for (unsigned int i = 0; i < filesList.size(); ++i) {
    std::cout << "About to delete: " << filesList[i]->getName() << std::endl;
    delete filesList[i];
  }
  for (unsigned int i = 0; i < subdirsList.size(); ++i) {
    std::cout << "About to delete: " << subdirsList[i]->getName() << std::endl;
    delete subdirsList[i];
  }
}

Dir& Dir::operator+=(Dir* toAdd) {
  this->subdirsList.push_back(toAdd);
  return *this;
}

Dir& Dir::operator+=(const File* toAdd) {
  this->filesList.push_back(toAdd);
  return *this;
}

void Dir::printSubdirs(std::ostream& os, unsigned int spaces) const {
  for (unsigned int i = 0; i < subdirsList.size(); ++i) {
    subdirsList[i]->printName(os, spaces);
    subdirsList[i]->printFiles(os, spaces+subdirsList[i]->getSpaces());
    subdirsList[i]->printSubdirs(os, spaces+subdirsList[i]->getSpaces());
  }
}

void Dir::printFiles(std::ostream& os, unsigned int spaces) const {
  for (unsigned int i = 0; i < filesList.size(); ++i)
    filesList[i]->printName(os, spaces);
}

const Dir* Dir::get(std::string name) const {
  for (unsigned int i = 0; i < subdirsList.size(); ++i) {
    if (subdirsList[i]->getName().compare(name) == 0)
      return subdirsList[i];
  }
  return 0;
}

std::ostream& operator<<(std::ostream& os, const Dir& dir) {
  dir.printName(os, 0);
  dir.printSubdirs(os, dir.getSpaces());
  dir.printFiles(os, dir.getSpaces());
  return os;
}
