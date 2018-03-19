#pragma once
#include "FileSystem.h"

class File : public FileSystem {
public:
  File(std::string name) { setName(name); };
};
