#include "pch.h"
#include "Flowlist.h"
#include <iostream>

using namespace std;

Flowlist::Flowlist() {
	headM = 0;
	cursorM = NULL;
}

Flowlist::Flowlist(Flowlist &list) {
	copy(list);
}

Flowlist::~Flowlist() {
	destroy();
}

Flowlist& Flowlist::operator=(const Flowlist &list) {
	if (this != &list) {
		destroy();
		copy(list);
	}
	return *this;
}

const ListItem& Flowlist::getItem() const {
	if (cursorM != NULL) {
		return cursorM->item;
	}
	else {
		Node *empty = new Node();
		cout << "Unable To Retrieve Item, CursorM is NULL" << endl;
		return empty->item;
	}
}

void Flowlist::reset() {
	cursorM = headM;
}

bool Flowlist::isOn() const {
	if (cursorM != NULL) {
		return true;
	}
	else {
		return false;
	}
}

const Node* Flowlist::cursor() const {
	return cursorM;
}

void Flowlist::forward() {
	if (cursorM != NULL) {
		cursorM = cursorM->next;
	}
	else {
		cout << "CursorM Is Currently NULL. The Cursor Will be Moved to the Head" << endl;
		reset();
	}
}

void Flowlist::insert(const ListItem& itemA) {

	Node *new_node = new Node();
	new_node->item = itemA;

	if (headM == 0 || itemA.year < headM->item.year) {
		new_node->next = headM;
		headM = new_node;
		cout << "Record Added!\n";
	}
	else {
		Node *before = headM;
		Node *after = headM->next;
		while (after != NULL && itemA.year > after->item.year) {
			before = after;
			after = after->next;
		}

		if (after != NULL && after->item.year == itemA.year) {
			cout << "A record already exists for " << itemA.year << " . This record will not be added.\n";
			return;
		}
		new_node->next = after;
		before->next = new_node;
		cout << "Record Added!\n";
	}
	cursorM = NULL;
}

void Flowlist::remove(int target_year) {

	if (headM == 0 || target_year < headM->item.year) {
		cout << "Year To Be Removed Does NOT Exist" << endl;
		return;
	}

	Node *doomed_node = 0;

	if (target_year == headM->item.year) {
		doomed_node = headM;
		headM = headM->next;
		delete(doomed_node);
		cursorM = NULL;
		cout << "Record Removed!\n";
	}
	else {
		Node *before = headM;
		Node *maybe_doomed = headM->next;
		while (maybe_doomed != NULL && target_year > maybe_doomed->item.year) {
			before = maybe_doomed;
			maybe_doomed = maybe_doomed->next;
		}

		if (maybe_doomed != NULL && maybe_doomed->item.year == target_year) {
			before->next = maybe_doomed->next;
			maybe_doomed->next = NULL;
			delete(maybe_doomed);
			cursorM = NULL;
			cout << "Record Removed!\n";
		}
		else {
			cout << "The Target Year Does NOT Exist in the List" << endl;
		}
	}
}

int Flowlist::count() const {
	int count = 0;
	Node *cursor = headM;
	while (cursor != NULL) {
		cursor = cursor->next;
		count++;
	}
	return count;
}

void Flowlist::copy(const Flowlist& source) {
	Node *src_cursor = source.headM;

	if (src_cursor == 0) {
		return;
	}

	Node *temp_head = new Node();
	headM = temp_head;
	temp_head->item = src_cursor->item;
	temp_head->next = NULL;
	Node *copy_cursor = headM;
	src_cursor = src_cursor->next;

	while (src_cursor != NULL) {
		Node *temp = new Node();
		temp->item = src_cursor->item;
		temp->next = NULL;

		copy_cursor->next = temp;
		copy_cursor = temp;
		src_cursor = src_cursor->next;
	}
}

void Flowlist::destroy() {
	Node *cursor1 = headM;
	Node *cursor2 = headM;

	while (cursor1 != NULL) {
		cursor1 = cursor1->next;
		delete(cursor2);
		cursor2 = cursor1;
	}

	cout << "The object has been destroyed" << endl;
	headM = 0;
}





