
#include "rapidjson/include/rapidjson/document.h"
#include "src/csvtojson.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include "src/gui.h"
#include "src/collection.h"
#include "cryptopp/eccrypto.h"

using namespace std;

int main() 
{
    /*
    Collection c("this3");
    c.AddCollection("this3");
    c.AddCollection("this4");
    c.DeleteCollection("this3");
    c.ViewAllCollections();
    */
     gui Gui;
     Gui.main();
    return 0;
}

/*
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
*/
