#ifndef GUI_H
#define GUI_H
#include <string>
#include <iostream>
using namespace std;
class gui
{
    public:
          void main();
          int validinput();
          
    private:
        
         void welcome();
         void login();
         void menu(bool& user);
         void reset(string username);
        
};

#endif
