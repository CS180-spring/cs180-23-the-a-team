#ifndef JSON_H
#define JSON_H

#include <iostream>
#include <fstream>
#include "collection.h"

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
                Value empty_json(kObjectType);
                jsondata->insertToRear(empty_json);
            }
    private:
};

#endif
