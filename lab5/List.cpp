#include "List.h"


List::List(const List& oldList) {
	size = oldList.getSize();
	Data* iterator = *(oldList.head);
	for (unsigned int i=0; i<size; ++i) {
		Data toInsert = *iterator;
		iterator = iterator->next;
		this->insert(toInsert);
	}
}


void List::insert(const Data& data, bool where) {
	Data toAdd = data;

	if (!head) {
		head = new Data*;
		*head = &toAdd;
	}

	else if (where == Begin) {
		toAdd.next = *head;
		*head = &toAdd;
	}

 else if (where == End) {
	 Data* next = *head;
	 for (unsigned int i=0; i<size-1; ++i) next = next->next;
	 next->next = &toAdd;
 }

	size += 1;
}


List& List::insert( const Data& data) {
	Data toAdd = data;

	if (!head) {
		head = new Data*;
		*head = &toAdd;
	}

	else  {
 	 Data* next = *head;
 	 for (unsigned int i=0; i<size-1; ++i) next = next->next;
 	 next->next = &toAdd;
  }

	size += 1;

	return *this;
}


void List::print() const {
	std::cout << "[ ";

	Data* iterator = *head;
	for (unsigned int i=0; i<getSize(); ++i) {
		iterator->print();
		if (iterator->next) iterator = iterator->next;
	}

	std::cout << "]" << std::endl;
}
