#pragma once

#include "IntData.h"
#include "FloatData.h"
#include "StringData.h"

#include "Data.h"
#include <vector>

class List {
public:
	List() {}
	List(const List& oldList);

	void insert(const Data& data, bool where);
	List& insert(const Data& data);
	void print() const;

	const static bool Begin = true;
	const static bool End = false;

private:
	std::vector<const Data*> list;
	std::vector<const Data*>::iterator it;

	Data** head = NULL;
};
