#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream> 
#include <string>          
typedef std::string ItemType;

struct Node
{
	ItemType value;
	Node* next;
};

class LinkedList
{
private:
	Node* head;
public:
	// constructor       
	LinkedList() : head(nullptr) { }
	// copy constructor       
	LinkedList(const LinkedList& rhs);
	// destructor
	~LinkedList();
	// assignment operator       
	const LinkedList& operator=(const LinkedList& rhs);
	// insert to end of list    
	void insertToRear(const ItemType& val);
	// print list
	void printList() const;
	// value at position 'i' of the list
	ItemType& get(int i) const;      
	// size of list     
	int size() const;
};
#endif
