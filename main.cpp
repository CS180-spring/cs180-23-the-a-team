
#include "rapidjson/include/rapidjson/document.h"
#include "src/csvtojson.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include "src/gui.h"
#include "src/collection.h"

using namespace std;

int main() 
{
    Collection c("this3");
    c.AddCollection("this4");
    Collection now;
     gui Gui;
     Gui.main();
    return 0;
}
/*
#include <iostream>
#include "parser.h"
using namespace std;
int main() {
    Parser p;
    int choice; 

  do {
    cout << "Please pick from the menu options\n";
    cout << "1 - Check for reliability of your file: \n";
    cout << "2 - Read/Parse Json file: \n";
    cin >> choice;
    switch (choice)
    {
    case 1: 
        cout<< "Check for Parsing error ......\n";
        p.parseError();
        break;
    
    case 2:
        cout << "Reading .....\n";
        p.parseJson();
        break;
    
    default:
    cout << "invalid choice\n";
    
    }

}while (choice !=3);

return 0;
}
*/
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
