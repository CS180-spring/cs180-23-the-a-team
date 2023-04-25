#include "LinkedList.h"
#include <iostream>
using namespace std;

LinkedList::LinkedList(const LinkedList& rhs)
{
	head = nullptr;
	*this = rhs;
}

LinkedList::~LinkedList()
{
	Node* temp = head;
	Node* p = head;

	while (p != nullptr)
	{
		p = temp->next;
		delete temp;
		temp = p;
	}
}

const LinkedList& LinkedList::operator=(const LinkedList& rhs)
{
	while (head != nullptr)
	{
		Node* old = head;
		head = head->next;

		delete old;
	}

	Node* temp = rhs.head;

	while (temp != nullptr)
	{
		insertToRear(temp->value);
		temp = temp->next;
	}

	return *this;
}

void::LinkedList::insertToRear(const ItemType& val)
{
	Node* n = new Node, * temp = head;
	n->value = val;
	n->next = nullptr;

	if (head == nullptr)
	{
		head = n;
	}
	else
	{
		while (temp->next != nullptr)
		{
			temp = temp->next;
		}
		temp->next = n;
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
	ItemType& Item;
	Node* temp = head;

	if (head == nullptr)
		return NULL;

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

	return NULL;
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