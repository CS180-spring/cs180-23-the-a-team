#ifndef JSON_H
#define JSON_H

#include <iostream>
#include <fstream>
#include "collection.h"
#include <vector>

class json
{
    public:
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
};

#endif
