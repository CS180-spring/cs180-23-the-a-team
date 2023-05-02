#include "LinkedList.h"
#include <iostream>
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

void LinkedList::insertToRear(const ItemType& val)
{
	Node* n = new Node, * temp = head;
	n->value = val;
	n->next = nullptr;

	if (head == nullptr)
	{
		head = n;
		tail = n;
	}
	else
	{
		tail->next = n;
		tail = n;
	}
}
void LinkedList::printList() const
{
	Node* temp = head;
	while (temp != nullptr)
	{
		cout << temp->value << " ";
		temp = temp->next;
	}

	cout << endl;
}
ItemType& LinkedList::get(int i) const
{
	Node* temp = head;
	ItemType& Item = temp->value;

	if (head == nullptr)
		return Item;

	int k = 0;

	while (temp != nullptr)
	{
		if (i == k)
		{
			Item = temp->value;
			return Item;
		}
		k++;
		temp = temp->next;
	}

	return Item;
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