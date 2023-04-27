#ifndef PARSER_H
#define PARSER_H

#include "rapidjson-master/include/rapidjson/document.h"
#include "rapidjson-master/include/rapidjson/istreamwrapper.h" 
#include "rapidjson-master/include/rapidjson/ostreamwrapper.h"
#include "rapidjson-master/include/rapidjson/prettywriter.h"
#include "rapidjson-master/include/rapidjson/rapidjson.h"
#include "rapidjson-master/include/rapidjson/error/en.h"
#include <iostream>
#include <fstream>
#include <string.h>
#include <iomanip>
#include <cstdio>
#include "rapidjson-master/include/rapidjson/stringbuffer.h"
#include "rapidjson-master/include/rapidjson/writer.h"
#include "rapidjson-master/include/rapidjson/filewritestream.h"
#include "rapidjson-master/include/rapidjson/filereadstream.h"
using namespace rapidjson;
using namespace RAPIDJSON_NAMESPACE;
using namespace std;

class  Parser
{
private:
    /* data */
public:
//function prototypes/ member functions
     Parser(/* args */);
     void parseError();
     void parseJson();
    //~ Parser(); 

}; 
#endif

