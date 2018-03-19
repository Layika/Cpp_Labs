#pragma once
#include "FileSystem.h"
#include "File.h"
#include <vector>
#include <iostream>

class Dir : public FileSystem {
public:
  Dir(std::string name) { setName(name); setSpaces(name.length()); };
  virtual ~Dir();
  Dir& operator+=(Dir* toAdd);
  Dir& operator+=(const File* toAdd);
  void setSpaces(unsigned int spaces) { this->spaces = spaces; }
  unsigned int getSpaces() const { return spaces; }
  void printSubdirs(std::ostream& os, unsigned int spaces) const;
  void printFiles(std::ostream& os, unsigned int spaces) const;
  const Dir* get(std::string name) const;

private:
  std::vector<const Dir*> subdirsList;
  std::vector<const File*> filesList;
  unsigned int spaces;
};

std::ostream& operator<<(std::ostream& os, const Dir& dir);
