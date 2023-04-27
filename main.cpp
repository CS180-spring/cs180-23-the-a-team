#include "rapidjson/include/rapidjson/document.h"
#include "src/csvtojson.h"
#include <iostream>
#include <sstream>
using namespace std;

int main() 
{

    csvtojson c;
    string name;
    int sizeofdata;
    stringstream outputofcsv;

    cout << "PLEASE input csv file to ..[ProjectFolder]/Inputs/" << endl;
    cout << "Enter the name of your csv file(no spaces): ";
    cin >> name;
    cout << "Enter the amount of rows you wish to import(excluding row1 with column names): ";
    cin >> sizeofdata;
    c.printcsv(name, sizeofdata, outputofcsv);
    outputofcsv.str();
    
    return 0;
}
