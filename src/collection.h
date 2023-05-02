#ifndef COLLECTION_H
#define COLLECTION_H

#include <iostream>
#include "LinkedList.h"

class collection
{
    public:
            collection(){}
    private:
    protected:
            LinkedList* jsondata = new LinkedList();
};

#endif
