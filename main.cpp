#include "rapidjson/include/rapidjson/document.h"
#include "src/csvtojson.h"
#include <iostream>
using namespace std;

int main() 
{
    csvtojson c;
    c.printcsv("test1", 3);
    return 0;
}
