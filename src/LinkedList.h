#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream> 
#include <string>   
#include <vector>       
typedef std::string ItemType;

struct Node
{
	std::vector<std::pair<string, string>> data;
	Node* next;
	Node* prev;
};

class LinkedList
{
private:
	Node* head;
	Node* tail;
public:
	// default constructor       
	LinkedList() : head(nullptr), tail(nullptr) { }
	// Destroys all the dynamically allocated memory       
	// in the list.       
	~LinkedList();
	// Inserts val at the rear of the list       
	void insertToRear(const ItemType& val);
	// Prints the LinkedList
	void printList() const;
	// Sets item to the value at position i in this       
	// LinkedList and return true, returns false if        
	// there is no element i 
	ItemType& get(int i) const;
	// Reverses the LinkedList       
	// Returns the number of items in the Linked List.       
	int size() const;
};
#endif
