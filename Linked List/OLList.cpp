// OLList.cpp
// ENSF 619  Lab 6 Exercise 3 and 4

#include <iostream>
#include <stdlib.h>
using namespace std;
#include "OLList.h"

OLList::OLList()
: headM(0)
{
}

OLList::OLList(const OLList& source)
{
    copy(source);
}

OLList& OLList::operator =(const OLList& rhs)
{
    if (this != &rhs) {
        destroy();
        copy(rhs);
    }
    return *this;
}

OLList::~OLList()
{
    destroy();
}

void OLList::print() const
{
    cout << '[';
    if (headM != 0) {
        cout << ' ' << headM->item;
        for (const Node *p = headM->next; p != 0; p = p->next)
            cout << ", " << p->item;
    }
    cout << " ]\n";
}

void OLList::insert(const ListItem& itemA)
{
    Node *new_node = new Node;
    new_node->item = itemA;
    
    if (headM == 0 || itemA <= headM->item ) {
        new_node->next = headM;
        headM = new_node;
        // point one
    }
    else {
        Node *before = headM;      // will point to node in front of new node
        Node *after = headM->next; // will be 0 or point to node after new node
        while(after != 0 && itemA > after->item) {
            before = after;
            after = after->next;
        }
        new_node->next = after;
        before->next = new_node;
        // point two
    }
}

void OLList::remove(const ListItem& itemA)
{
    // if list is empty, do nothing
    if (headM == 0 || itemA < headM->item)
        return;
    
    Node *doomed_node = 0;
    
    if (itemA == headM->item) {
        doomed_node = headM;
        headM = headM->next;
    }
    else {
        Node *before = headM;
        Node *maybe_doomed = headM->next;

		while (maybe_doomed != 0 && itemA > maybe_doomed->item) {
			before = maybe_doomed;
			maybe_doomed = maybe_doomed->next;
		}
		if (maybe_doomed->item == itemA) {
			before->next = maybe_doomed->next;
			maybe_doomed->next = NULL;
			delete(maybe_doomed);	
		}
    }
}

void OLList::destroy()
{
	Node *cursor1 = headM;
	Node *cursor2 = headM;

	while (cursor1 != NULL) {
		cursor1 = cursor1->next;
		delete(cursor2);
		cursor2 = cursor1;
	}

	cout << "\nThe Object Has Been Destroyed\n";
	headM = 0;
}

void OLList::copy(const OLList& source)
{
	Node *src_cursor = source.headM;

	if (src_cursor == 0) {
		headM = 0;
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


