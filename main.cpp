
#include "rapidjson/include/rapidjson/document.h"
#include <iostream>
#include "src/gui.h"

using namespace std;

int main() {

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
