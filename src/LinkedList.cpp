#include "LinkedList.h"
#include <iostream>
#include <ctype.h>
using namespace std;

LinkedList::~LinkedList()
{
	while (head != nullptr)
	{
		Node* p = head;
		head = head->next;
		delete p;
	}
}

void LinkedList::insertToRear(vector<pair<string, string>> data)
{
	Node* n = new Node, * temp = head;
	n->data = data;
	n->next = nullptr;

	if (head == nullptr)
	{
		head = n;
		tail = n;
		head->next = tail;
		tail->prev = head;
	}
	else
	{
		tail->next = n;
		n->prev = tail;
		tail = n;
	}
}

bool LinkedList::deleteNode(int i) const
{
	Node* temp = head;

	if (head == nullptr)
		return false;

	int k = 0;

	while (temp != nullptr)
	{
		if (i == k)
		{
			temp->prev->next = temp->next;
			temp->next->prev = temp->prev;
			delete temp;
			return true;
		}
		k++;
		temp = temp->next;
	}

	return false;
}

vector<pair<string, string>> LinkedList::get(int i) const
{
	Node* temp = head;

	if (head == nullptr)
		return head->data;

	int k = 0;

	while (temp != nullptr)
	{
		if (i == k)
		{
			return temp->data;
		}
		k++;
		temp = temp->next;
	}

	return temp->data;
}
int LinkedList::size() const
{
	int count = 0;
	Node* temp = head;

	while (temp != nullptr)
	{
		temp = temp->next;
		count++;
	}

	return count;
}

// option key
// 1 = ascending sort
// 2 = descending sort
LinkedList* LinkedList::sort(string column_name, int option)
{
	if (head == nullptr) 
	{
		return nullptr;
	}

	LinkedList* nList = new LinkedList();
	Node * temp = head;


	// first find index of column name
	int index = -1;
	for (int i = 0; i < temp->data.size(); i++)
	{
		if (temp->data[i].first == column_name)
		{
			index = i;
		}
	}
	if (index == -1)
	{
		// could not find column name, return nullptr
		return nullptr;
	}
	// integer validation 
	for (int k = 0; k < temp->data[index].second.size(); k++)
	{
		if (isdigit(temp->data[index].second[k]))
			continue;
		else
			return nullptr;
	}

	// can now safely convert to integer and store in storekey member of node
	// go through whole linkedlist
	temp = head;
	
	while (temp != nullptr)
	{
		temp->sortkey = stoi(temp->data[index].second);
		temp = temp->next;
	}

	// set temp back to head
	temp = head;
	if (option == 1)
	{

	}
	else if (option == 2)
	{

	}
	else return nullptr;

	return nullptr;
}