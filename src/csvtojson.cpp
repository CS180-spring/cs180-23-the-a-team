#include "csvtojson.h"

using namespace std;

csvtojson::csvtojson(){}

void csvtojson::printcsv(string name, int datarows, ostream& output)
{
    //Check name if it has .csv
    string csvfile;
    string extension = ".csv";
    if (name.find(extension) == string::npos)
    {
        csvfile = "Inputs/" + name + extension;
    }
    else
    {
        csvfile = "Inputs/" + name;
    }
    
    fstream file;
    //fstream jsonfile;
    file.open(csvfile);
    //jsonfile.open("Inputs/test1.json");

    string columns, temp, comma = ",";
    vector<string> columnlist;

    cout << "File name: " << csvfile << endl;
    getline(file, columns);

    int positionOfcomma = 0;
    while(columns.find(comma) != string::npos)
    {
        positionOfcomma = columns.find(comma);
        columnlist.push_back(columns.substr(0,positionOfcomma));
        columns.erase(0,positionOfcomma+1);

    }
    if (columns.length() != 0)
    {
        positionOfcomma = columns.find(comma);
        columnlist.push_back(columns.substr(0,positionOfcomma));
        columns.erase(0,positionOfcomma+1);
    }

    int rows = 0;
    while(file.is_open())
    {
        for(int i = 0; i < columnlist.size(); i++)
        {
            if(i == (columnlist.size() - 1))
            {
                getline(file,temp);  
            }
            else if (i <= (columnlist.size() - 1))
            {
                getline(file,temp,','); 
            }
            if (rows == datarows)
            {
                file.close();
                break;
            }
            else
            {
                cout << temp;
                output << temp;
            }
            
        }
        rows++;

    }  
}

