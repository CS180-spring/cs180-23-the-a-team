#ifndef JSON_H
#define JSON_H

#include <iostream>
#include <fstream>
#include "collection.h"
#include <vector>
#include "LinkedList.h"
#include "parser.h"

using namespace std;

class json : public collection
{
    public:
            json(){}
            void intiializeEMPTYjson(string collectionname, string jsonname);
            void importJson();
            void view();
            void edit(vector<pair<string, string>> &data);
            void writeJson();
            void delNode(int id)
            {
                    jsondata->delNode(id);
            }
            void addEmptyJson()
            {
                std::vector<std::pair<std::string, std::string>> empty;
                jsondata->insertToRear(empty);
            }
    private:
        fstream file;
        LinkedList* jsondata = new LinkedList();
        string directory;
};

#endif
