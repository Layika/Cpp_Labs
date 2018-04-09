#include "List.h"


List::List(const List& oldList) {
	Data* iterator;
	for (iterator=*(oldList.head); iterator; iterator=iterator->next)
		this->insert(*(iterator->clone()));
}


List::~List() {
	Data* iterator;
	for (iterator=*head; iterator; iterator=iterator->next)
		delete iterator;
	delete head;
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
	 for (next=*head; next->next; next=next->next);
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
	for (iterator=*head; iterator; iterator=iterator->next)
		iterator->print();

	std::cout << "]" << std::endl;
}


bool List::find(Data data) const {
	bool found = false;
	Data* iterator;
	for (iterator=*head; iterator; iterator=iterator->next) {
		if (found) break;
		found = data.cmp(iterator);
	}
	return found;
}
