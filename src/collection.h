#ifndef COLLECTION_H
#define COLLECTION_H

#include <iostream>
#include "LinkedList.h"

class collection
{
    public:
            collection()
            {}
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
