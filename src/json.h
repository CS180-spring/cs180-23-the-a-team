//all the crud operations 
#ifndef JSON_H
#define JSON_H
#include "../rapidjson/include/rapidjson/document.h"
#include "../rapidjson/include/rapidjson/istreamwrapper.h" 
#include "../rapidjson/include/rapidjson/ostreamwrapper.h"
#include "../rapidjson/include/rapidjson/prettywriter.h"
#include "../rapidjson/include/rapidjson/rapidjson.h"
#include "../rapidjson/include/rapidjson/error/en.h"
#include <iostream>
#include <fstream>
#include <string.h>
#include <iomanip>
#include <cstdio>
#include "../rapidjson/include/rapidjson/stringbuffer.h"
#include "../rapidjson/include/rapidjson/writer.h"
#include "../rapidjson/include/rapidjson/filewritestream.h"
#include "../rapidjson/include/rapidjson/filereadstream.h"
using namespace rapidjson;
using namespace RAPIDJSON_NAMESPACE;
using namespace std;
#include <vector>
#include <iostream>

class Json
{
    public:
        Json() {} //default constructor
        struct pairofjson
        {
        //rapidjson::Value JsonKey;
        string Jsonkey;
        string Jsonval;
        //rapidjson::Value JsonValue; 
        };
        vector<pairofjson> information;  
        void writeJson();
        void parseError();
        void parseJson(); 

    private:

};

#endif
