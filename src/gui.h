#ifndef GUI_H
#define GUI_H

#include "parser.h"
#include <iostream>
#include <fstream>
#include "csvtojson.h"
#include "json.h"
#include <filesystem>
#include "collection.h"
#include "LinkedList.h"

class gui
{
    public:
          void main();
    private:
         int validinput();
         void welcome();
         void login();
         void menu(bool& user);
         LinkedList jsondata;
         Json j;
        
};

#endif
