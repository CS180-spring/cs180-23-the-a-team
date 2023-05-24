#include "LinkedList.h"
#include <iostream>
#include <ctype.h>
#include <algorithm>
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
	Node* n = new Node();
	// * temp = head;
	n->data = data;
	n->next = nullptr;

	if (head == nullptr)
	{
		head = n;
		tail = head;
		n->id = 0;
		head->next = nullptr;
		//tail->prev = head;

	}
	else
	{
		tail->next = n;
		n->prev = tail;
		n->id = tail->id + 1;
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
			
			// need to update ids
			while (temp != nullptr)
			{
				temp->next->id = temp->next->id - 1;
				temp = temp->next;
			}

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
LinkedList* LinkedList::sortList(string column_name, int option)
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
		//cout << temp->id << endl;
		temp->sortkey = stoi(temp->data[index].second);
		temp = temp->next;
	}

	// set temp back to head
	temp = head;

	if (option == 1)
	{
		vector<pair<int, int>> sortvec;
		while (temp != nullptr)
		{
			int id = temp->id;
			int sortkey = temp->sortkey;
    		pair t = make_pair(sortkey,id);
			sortvec.push_back(t);
			temp = temp->next;
		}

		sort(sortvec.begin(), sortvec.end());

		for (int i = 0; i < sortvec.size(); i++)
		{
			nList->insertToRear(this->get(sortvec[i].second));
		}

		Node* newH = nList->head;

		while (newH != nullptr)
		{
			//cout << newH->data[0].second << endl;
			newH = newH->next;
		}

		return nList;
	}
	else if (option == 2)
	{
		vector<pair<int, int>> sortvec;
		while (temp != nullptr)
		{
			int id = temp->id;
			int sortkey = temp->sortkey;
    		pair t = make_pair(sortkey,id);
			sortvec.push_back(t);
			temp = temp->next;
		}

		sort(sortvec.begin(), sortvec.end());

		for (int i = sortvec.size() - 1; i >= 0; i--)
		{
			nList->insertToRear(this->get(sortvec[i].second));
		}

		Node* newH = nList->head;

		while (newH != nullptr)
		{
			//cout << newH->data[0].second << endl;
			newH = newH->next;
		}
		return nList;
	}

	return nullptr;
}


void LinkedList::printList()
{
	Node * temp = head;

	while (temp != nullptr)
	{
		for (int i = 0; i < temp->data.size(); i++)
		{
			cout << temp->data[i].first << " : " << temp->data[i].second << endl;
		}
		temp = temp->next;
	}

	return;
}

void LinkedList::set(std::vector<std::pair<std::string, std::string>> v, int i)
{
	int k = 0;
	Node* temp = head;
	if( head != nullptr)
	{
		while (temp != nullptr)
		{
			if (i == k)
			{
				temp->data.clear();
				temp->data = v;
			}
			k++;
			temp = temp->next;
		}
	}
	
}

