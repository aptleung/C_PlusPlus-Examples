#pragma once


struct ListItem {
	int year;
	double flow;
};
struct Node {
	ListItem item;
	Node *next;
};

class Flowlist {

public:

	//Constructors & Destructors
	Flowlist();
	Flowlist(Flowlist &list);
	Flowlist &operator=(const Flowlist &list);
	~Flowlist();

	const ListItem& getItem() const;
	
	void reset();
	
	bool isOn() const;
	
	const Node* cursor()const;
	
	void forward();
	
	void insert(const ListItem& itemA);
	
	void remove(int target_year);

	int count()const;

private:

	// always points to the first node in the list.
	Node *headM;

	// Initially is set to NULL, but it may point to any node.
	Node *cursorM;

	void copy(const Flowlist& source);
	void destroy();


};
