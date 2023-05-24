#include "json.h"

using namespace std;

Json::Json(string cname, string jname)
{
    collectionName = cname;
    if(verifyCollectionExist(cname)) //parent function
    {
        setDirectoryJson(cname, jname);
    }
    else
    {
        AddCollection(cname); //parent function
        setDirectoryJson(cname, jname);
    }
    
}

void Json::setfullDirectory(string n)
{
    directory = n;
}

void Json::setDirectoryJson(string cname, string jname)
{
    collectionName = cname;
    if( verifyCollectionExist(cname)) //parent function
    {
        directory = "Database/" + cname + "/" + jname;
    }
    else
    {
        AddCollection(cname); //parent function
        directory = "Database/" + cname + "/" + jname;
    }
    cout << "Directory Successful: " << directory << endl;
    //check if directory already exists
}

//try to use rapidjson
void Json::writeJson() {
     struct Person {
        string id;
        string name;
        int age;
        string college;
    };

    vector<Person> people = {
        {"9873e87e879ueid", "Farnaz", 23, "UC Riverside"},
        {"98e89r8983009id", "Golnaz", 27, "UC Berkely"},
        {"9898378747382id", "Niloofar", 30, "UCLA"},
        {"959067fs9d798id", "Muneeb", 23, "UC Riverside"}
    };
    string filename = "output.json";
    
    ofstream outputFile(filename);
    if (outputFile.is_open()) {
        outputFile << "{\n\t\"people\": [";
        for (size_t i = 0; i < people.size(); ++i) {
            if (i != 0) {
                outputFile << ", ";
            }
            outputFile << "{\n\t\t\"id\": \"" << people[i].id << "\",\n";
            outputFile << "\t\t\"name\": \"" << people[i].name << "\",\n";
            outputFile << "\t\t\"age\": " << people[i].age << ",\n";
            outputFile << "\t\t\"college\": \"" << people[i].college << "\"\n\t}";
        }
        outputFile << "]\n}";
        outputFile.close();
    }
}

void Json::intiializeEMPTYjson(string collectionname, string jsonname)
{
    directory = "Database/" + collectionname + jsonname;
    file.open(directory);
    file.close();
}

//Parser could go under here
void Json::importJson()
{
    //Add string manipulation for getting name automatically
    string d,d2,d3;
    cout << "Please write the path of your input Json: " << endl;
    getline(cin, d);
    cout << "Please enter the collection name(no spaces): ";
    cin >> d2;
    cout << "Enter in name of json to be created(no spaces): ";
    cin >> d3;
    setDirectoryJson(d2,d3);
    file.open(d);
    ifstream  From(d, ios::binary);
    ofstream  To(directory, ios::binary);
    To << From.rdbuf();
    
}

void Json::view(LinkedList* list)
{
    int choice, viewcount, editchoice;
    int counter = 0;
    vector<pair<string, string>> show;
    cout << "Enter how many entries would you like to view per page (greater than 0): " << endl;
    cin >> viewcount;
    while(viewcount <= 0)
    {
        cout << "Invalid, Please Try Again " << endl;
        cout << "Enter how many entries would you like to view per page (greater than 0): " << endl;
        cin >> viewcount;
    }
    cout << "Use number 1 to 3 to control viewer" << endl;
    cout << "1. Edit" << endl;
    cout << "2. Previous" << endl;
    cout << "3. Next" << endl;
    cout << "99. Exit Viewer" << endl;
    do
    {
        //Show the Node
        for (int c = counter; c < viewcount; c++)
        {
            if(list->size() > c)
            {
                show = list->get(c);
                cout<< c << ". ";
                for(int i = 0; i < show.size() ; i++)
                {
                    cout << "'" << show[i].first << "' : " << show[i].second << endl;
                } 
            }
            
        }
        
        cin >> choice;
        switch(choice)
        {
            case 1:
                cout << "Enter the number associated with the entry you would like to edit" << endl;
                cin >> editchoice;
                show = edit(show);
                list->set(show, editchoice);
                break;
            case 2:
                counter -= viewcount;
                if(counter < 1)
                {
                    counter = 0;
                }
                show.clear();
                //go to previous node
                break;
            case 3:
                if((counter += viewcount) >= list->size())
                {
                    counter += viewcount;
                    show.clear();  
                }
                else
                {
                    cout << "End of List" << endl;
                }
                
                //go to next node
                break;
            case 99:
                break;
            default:    cout << "Error: Invalid option" << endl;
                        cout << "Use number 1 to 3 to control viewer" << endl;
                        cout << "1. Edit" << endl;
                        cout << "2. Previous" << endl;
                        cout << "3. Next" << endl;
                        cout << "99. Exit Viewer" << endl;
                break;
        }
        
    } while (choice != 99);
    
}

vector<pair<string, string>> Json::edit(vector<pair<string, string>> &show)
{
    int choice;
    cout << "Enter the number of which attribute, would you like to edit" << endl;
    for(int i = 0; i < show.size(); i++)
    {
        cout << i << ". " << show[i].first << endl;
    }
    cin >> choice;
    while((choice < 0) || (choice >= show.size()))
    {
        cout <<"Invalid option, Try Again!" << endl;
        cout << "Enter the number of which attribute, would you like to edit" << endl;
        for(int i = 0; i < show.size(); i++)
        {
            cout << i << ". " << show[i].first << endl;
        }
        cin >> choice;
    }
    cout << "Enter the new value for this attribute(" << show[choice].first << "): " ;
    cin >> show[choice].second; //later should be getline
    return show;
}

/*
void Json::writeJson() {

    cout << "here";
    string id = "7343d87e623urfd";
    string name = "Muneeb";
    int age = 23;
    string college = "UC Riverside";

    string data = "{\n";
    data += "  \"id\": \"" + id + "\",\n";
    data += "  \"Name\": \"" + name + "\",\n";
    data += "  \"Age\": " + to_string(age) + ",\n";
    data += "  \"College\": \"" + college + "\"\n";
    data += "}\n";

    ofstream outfile("out.json");
    outfile << data;
    outfile.close();

    cout << "\nfinal\n";
}
*/
void Json::parseError()
{
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
void Json::parseJson()
{
    ifstream file(directory);   
    IStreamWrapper isw(file);
    cout << endl << "RealDirectory: " << directory << endl;
    Document doc;
    doc.ParseStream(isw);
    vector<pair<string, string>> information;
    //struct pairofjson s;
    if (!doc.IsArray()) {
        cout << "Document must be an array" << endl;
    }
    for (auto& itr : doc.GetArray()) {
            for (auto& obj : itr.GetObject()) {
                pair t = make_pair(string(obj.name.GetString()),string(obj.value.GetString()));
                information.push_back(t);
                //jsondata->insertToRear();
                /*
                pair.Jsonkey = obj.name.GetString();
                pair.Jsonval = obj.value.GetString();
                //information.push_back(pair);
                */
            }
        }
    
    string firstentry = information[0].first;
    vector<pair< string, string>> temp;
    for(int i = 0; i < information.size(); i++)
    {
        if(information[i].first == firstentry && i != 0)
        {
            jsondata->insertToRear(temp);
            temp.clear();
        }

        temp.push_back(information[i]);
    }
    jsondata->insertToRear(temp);
    cout << "Size of LinkedList:" << jsondata->size() << endl;
    view(jsondata);
    /*
    for(const auto& p: information) {
        cout << p.Jsonkey << " : " << p.Jsonval << endl;
    }
    */
}

void Json::searchFunc( string searchby, vector<string> match)
{
    vector<pair<string, string>> v = jsondata->get(0);
    int findattributeindex;
    cout << "Finding " << searchby << " with " << match.size() << " matchings" << endl;
    for(int i = 0; i < v.size(); i++)
    {
        if(searchby == v[i].first)
        {
            findattributeindex = i;
            cout << "Found Attribute" << endl;
        }
    }
    cout << endl << "Attribute index: " << findattributeindex << endl;
    cout << "Match:" << match[0] << ";" << endl;
    for(int i = 0; i < jsondata->size(); i++)
    {
        cout << "Herein loop" << endl;
        v = jsondata->get(i);
   
        for(int j = 0; j < match.size(); j++)
        {
            if( match[j] == v[findattributeindex].second)
            {
                cout << "found";
                result->insertToRear(v);
                //break;
            }
        
        }
        
    }
    cout << "Found " << result->size() << " entries" << endl;
    result->printList();

   //view(result);

}

void Json::sortFunc(string attrib, int option)
{
    LinkedList* result = jsondata->sortList(attrib, option);
    result->printList();
}

void Json::filterFunc( string searchby, vector<string> match)
{
    LinkedList* result;
    vector<pair<string, string>> v = jsondata->get(0);
    int findattributeindex;
    for(int i = 0; i < v.size(); i++)
    {
        if(searchby == v[i].first)
        {
            findattributeindex = i;
            // for(int j = 0; j < match.size(); j++)
            // {
            //     if( match[0] == v[findattributeindex].second)
            //     {
            //         result->insertToRear(jsondata->get(0));
            //     }
            // }
            
            break;
        }
    }

    v.clear();
    for(int i = 0; i < jsondata->size(); i++)
    {
        v = jsondata->get(i);
   
       // for(int j = 0; j < match.size(); j++)
        //{
            if( match[0] != v[findattributeindex].second)
            {
            
                for (int i = 0; i < v.size(); i++)
                {
                    cout << v[i].first << " " << v[i].second << endl;
                }
                //result->insertToRear(jsondata->get(i));
            
            }
       // }
        
    }

   //view(result);

}


void Json::stringparser(string command)
{
    cout << "command:" << command << endl;
    deleteChars(command, ' ');

    //Grab first keyword that will be until next space
    vector<string> values;    
    int index = command.find(' ');
    string temp= command.substr(0,index);
    string attrib, value;
    int choice = 0, sortoption;
    if(temp == "SEARCH")
    {
        choice = 1;
        command.erase(command.begin(), command.begin() + index); //delete keyword
        deleteChars(command, ' ');
        deleteChars(command, '"'); //Delete 1st quotattion symbol
        index = command.find('"');     
        temp = command.substr(0,index);
        attrib = temp; 
        command.erase(command.begin(), command.begin() + index + 1);
        deleteChars(command, ' ');
        deleteChars(command, '(');
        index = command.find(')');
        value = command.substr(0,index);
        command.erase(command.begin(), command.begin() + index + 1);
        while(value.find('|') != string::npos)
        {
            index = value.find('|');
            temp = value.substr(0,index);
            values.push_back(temp);
            value.erase(0,index+1);
        }
        if(value.find("|") == string::npos)
        {
            index = value.find(')');
            temp = value.substr(0 ,index);
            values.push_back(temp);
            temp = "";
        }
      
    }
    if(temp == "SORT") 
    {
        choice = 2;
        command.erase(command.begin(), command.begin() + index); //delete keyword
        deleteChars(command, ' ');
        deleteChars(command, '"'); //Delete 1st quotattion symbol
        index = command.find('"');
        temp = command.substr(0,index);
        attrib = temp;
        command.erase(command.begin(), command.begin() + index + 1);
        deleteChars(command, ' ');
        index = command.find(';');
        temp = command.substr(0,index);
        transform(temp.begin(), temp.end(), temp.begin(), ::toupper);
        cout << "Attrib: " << attrib << " temp: " << temp << endl;
        if (temp == "ASCENDING")
        {
            sortoption = 1;
        }
        else if (temp == "DESCENDING")
        {
            sortoption = 2;
        }
    }
    if(temp == "FILTER")
    {
        choice = 3;
        command.erase(command.begin(), command.begin() + index); //delete keyword
        deleteChars(command, ' ');
        deleteChars(command, '"'); //Delete 1st quotattion symbol
        index = command.find('"');     
        temp = command.substr(0,index);
        attrib = temp; 
        cout << "Attrib:" << attrib << endl;
        command.erase(command.begin(), command.begin() + index + 1);
        deleteChars(command, ' ');
        deleteChars(command, '(');
        index = command.find(')');
        value = command.substr(0,index);
        command.erase(command.begin(), command.begin() + index + 1);
        if((value.find('|') != string::npos) || (value.length() != 0))
        {
            index = value.find('|');
            temp = value.substr(0,index);
            values.push_back(temp);
            value.erase(0,index+1);
        }
        if(value.find("|") == string::npos)
        {
            index = value.find(')');
            temp = value.substr(0 ,index);
            values.push_back(temp);
            temp = "";
        }
      
    }
   switch (choice)
   {
        case 1: 
                searchFunc(attrib, values);
                cin.clear();
                //view(result);
            break;
        case 2: //jsondata = jsondata->sortList(attrib, sortoption);
                sortFunc(attrib, sortoption);

                //view(jsondata);
            break;
        case 3:
                filterFunc(attrib, values);
                cin.clear();
        default:
            break;
   }
    
}


void Json::deleteChars(string &command, char t)
{
    //Delete first spaces
    while(command[0] == t)
    {
        command.erase(command.begin());
    }
}

void Json::viewOriginal()
{
    view(jsondata);
}
