#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream> 
#include <string>          
typedef std::string ItemType;

struct Node 
{    
	ItemType value;    
	Node *next; 
}; 

class LinkedList 
{ 
private:       
	Node* head;    
public:       
	// default constructor       
	LinkedList() : head(nullptr) { }                    
	// copy constructor       
	LinkedList(const LinkedList& rhs);                    
	// Destroys all the dynamically allocated memory       
	// in the list.       
	~LinkedList();                    
	// assignment operator       
	const LinkedList& operator=(const LinkedList& rhs);                    
	// Inserts val at the rear of the list       
	void insertToRear(const ItemType &val);                    
	// Prints the LinkedList
	void printList() const;                    
	// Sets item to the value at position i in this       
	// LinkedList and return true, returns false if        
	// there is no element i 
	bool get(int i) const;                    
	// Reverses the LinkedList       
	void reverseList();                                                          
	// Returns the number of items in the Linked List.       
	int size() const; 
};
#endif
