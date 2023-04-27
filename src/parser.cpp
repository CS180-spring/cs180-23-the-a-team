#include <iostream>
#include "parser.h"
using namespace std; 

//constructor
 Parser:: Parser(/* args */)
{

}

void Parser::parseError(){
    //handle parsing error
    ifstream file("data.json");
    IStreamWrapper isw(file);
    Document document;
    document.ParseStream(isw);
    if (document.HasParseError()) {
        cout << "Following errors were found: \n" ;
        fprintf(stderr, "\nError(offset %u): %s\n",
        (unsigned)document.GetErrorOffset(),
        GetParseError_En(document.GetParseError()));
    }else{
        cout<<"No errors were found while parsing the file\n";
    }

}
void Parser::parseJson(){
    ifstream file("data.json");   
    IStreamWrapper isw(file);

    Document doc;
    doc.ParseStream(isw);
    // Accessing the whole JSON (this works for multiple collections)
    cout << "Total json data: \n";
    StringBuffer buffer;
    Writer<StringBuffer> writer(buffer);
    doc.Accept(writer);
    cout << buffer.GetString() << endl;

    rapidjson::Value::ConstValueIterator it;

    for(it = doc.Begin(); it != doc.End(); it++){

        cout << "ID :" << 
            it->GetObject()["id"].GetString() <<endl;
        cout << "Name: " << 
            it->GetObject()["Name"].GetString() << endl;
        cout << "Age: " << 
         it->GetObject()["Age"].GetString() << endl;
        cout << "College: " << 
            it->GetObject()["College"].GetString() << endl;

    }

}

 /*deconstructor
 Parser::~ Parser()
{
}
*/