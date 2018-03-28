#include "List.h"


List::List(const List& oldList) {
	for (unsigned int i=0; i < oldList.list.size(); ++i)
		this->list.push_back(oldList.list[i]);
}


void List::insert(const Data& data, bool where) {
	//if (!head) head = &data;
	if (where == Begin) {
		it = list.begin();
		list.insert(it, &data);
	}

	else list.push_back(&data);
}

List& List::insert(const Data& data) {
	list.push_back(&data);\
	return *this;
}

void List::print() const {
	std::cout << "[ ";

	for (unsigned int i=0; i < list.size(); ++i)
		list[i]->print();

	std::cout << "]" << std::endl;
}

