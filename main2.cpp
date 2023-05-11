#include "src/LinkedList.h"
#include <iostream>
using namespace std;

int main()
{
    LinkedList* list = new LinkedList();

    pair t = make_pair("Age", "20");
    pair t2 = make_pair("Age", "77");
    pair t3 = make_pair("Age", "13");

    vector<pair<string,string>> vec1;
    vector<pair<string,string>> vec2;
    vector<pair<string,string>> vec3;

    vec1.push_back(t);
    vec2.push_back(t2);
    vec3.push_back(t3);

    list->insertToRear(vec1);
    list->insertToRear(vec2);
    list->insertToRear(vec3);

    cout << "Before Sort" << endl;
    list->printList();
    int option;
    cout << "Would you like to do ascending or descending sort?\n\t1. Ascending\n\t2. Descending\nSelect: ";
    cin >> option;

    LinkedList* newList = list->sortList("Age", option);

    cout << "After Sort" << endl;
    newList->printList();

    
}