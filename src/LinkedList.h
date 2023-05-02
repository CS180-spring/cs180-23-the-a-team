#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream> 
#include <string>   
#include <vector>       
typedef std::string ItemType;

struct Node
{
	std::vector<std::pair<std::string, std::string>> data;
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
	bool deleteNode(int i) const;
	// Inserts val at the rear of the list       
	void insertToRear(std::vector<std::pair<std::string, std::string>> data);
	// Sets item to the value at position i stin this       
	// LinkedList and return true, returns false if        
	// there is no element i 
	std::vector<std::pair<std::string, std::string>> get(int i) const;
	// Reverses the LinkedList       
	// Returns the number of items in the Linked List.       
	int size() const;
};
#endif
