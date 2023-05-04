#ifndef COLLECTION_H
#define COLLECTION_H

#include <stdio.h>
#include <dirent.h>
#include <typeinfo>
#include<iostream>
#include <fstream>
#include <string>
#include <bits/stdc++.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <filesystem>
#include "LinkedList.h"

using namespace std;

class Collection
{
    public:
            Collection();
            Collection(string name);
            void AddCollection(string name);
            void DeleteCollection(string name);
            void ViewCollection(string name);
            void ViewAllCollections();
            bool checkIFFolder(string s);
            bool verifyCollectionExist(string name);
            void test()
            {
                Node* n = new Node();
                std::pair t = std::make_pair(std::string("lightbulbs"),std::string("test"));
                jsondata->insertToRear({t});
            }    
    private:
    protected:
            LinkedList* jsondata = new LinkedList();
};

#endif
