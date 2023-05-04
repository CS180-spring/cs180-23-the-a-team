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

void LinkedList::insertToRear(vector<pair<string, string>> data)
{
	Node* n = new Node, * temp = head;
	n->data = data;
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