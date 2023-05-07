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
#include <fstream>
#include "collection.h"
#include <vector>
#include "LinkedList.h"
#include "parser.h"


class Json : public Collection
{
    public:
        Json() {} //default constructor
        Json(string cname, string jname);
        /*
        struct pairofjson
        {
        //rapidjson::Value JsonKey;
        string Jsonkey;
        string Jsonval;
        //rapidjson::Value JsonValue; 
        };
        
        vector<pairofjson> information;
        */
        void setDirectoryJson(string cname, string jname);  
        void setfullDirectory(string n);
        void writeJson();
        void parseError();
        void parseJson(); 
        void intiializeEMPTYjson(string collectionname, string jsonname);
        void importJson();
        void view();
        void edit(vector<pair<string, string>> data);
        void delNode(int id)
        {
            //.deleteNode(id);
        }
        void addEmptyJson()
        {
            std::vector<std::pair<std::string, std::string>> empty;
            //jsondata.insertToRear(empty);
        }

    private:
        fstream file;
        LinkedList* jsondata = new LinkedList();
        string directory;
};

#endif
