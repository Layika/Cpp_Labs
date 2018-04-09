#include "List.h"


List::List(const List& oldList) {
	Data* iterator;
	for (iterator=*(oldList.head); iterator->next; iterator=iterator->next);
		this->insert(*(iterator->clone()));
}


void List::insert(const Data& data, bool where) {
	Data* toAdd = data.clone();

	if (!head) {
		head = new Data*;
		*head = toAdd;
	}

	else if (where == Begin) {
		toAdd->next = *head;
		*head = toAdd;
	}

 else if (where == End) {
	 Data* next;
	 for(next=*head; next->next; next=next->next);
	 next->next = toAdd;
 }
}


List& List::insert( const Data& data) {
	insert(data, End);
	return *this;
}


void List::print() const {
	std::cout << "[ ";

	Data* iterator;
	for (iterator=*head; iterator->next; iterator=iterator->next)
		iterator->print();

	std::cout << "]" << std::endl;
}
