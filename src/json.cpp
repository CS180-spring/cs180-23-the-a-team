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

void Json::view()
{
    int choice;
    int counter = 0;
    vector<pair<string, string>> show;
    cout << "Use number 1 to 3 to control viewer" << endl;
    cout << "1. Edit" << endl;
    cout << "2. Previous" << endl;
    cout << "3. Next" << endl;
    cout << "99. Exit Viewer" << endl;
    do
    {
        //Show the Node
        cout << "b" << endl;
        show = jsondata->get(counter);
        cout << "t" << endl;
        for(int i = 0; i < show.size() ; i++)
        {
            cout << " '" << show[i].first << "' : " << show[i].second << endl;
        }
        cin >> choice;
        switch(choice)
        {
            case 1:
                //call edit
                //edit(show);
                
                break;
            case 2:
                counter--;
                if(counter < 1)
                {
                    counter = 1;
                }
                show.clear();
                //go to previous node
                break;
            case 3:
                show.clear();
                counter++;
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

void Json::edit(vector<pair<string, string>> data)
{
    int choice;
    cout << "Enter the number of which attribute, would you like to edit" << endl;
    for(int i = 0; i < data.size(); i++)
    {
        cout << i << ". " << data[i].first << endl;
    }
    cin >> choice;
    while((choice < 0) || (choice >= data.size()))
    {
        cout <<"Invalid option, Try Again!" << endl;
        cout << "Enter the number of which attribute, would you like to edit" << endl;
        for(int i = 0; i < data.size(); i++)
        {
            cout << i << ". " << data[i].first << endl;
        }
        cin >> choice;
    }
    cout << "Enter the new value for this attribute(" << data[choice].first << "): " ;
    cin >> data[choice].second; //later should be getline
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
    vector<pair< string, string>> result;
    for(int i = 0; i < information.size(); i++)
    {
        if(information[i].first == firstentry && i != 0)
        {
            jsondata->insertToRear(result);
            result.clear();
        }

        result.push_back(information[i]);
    }
    jsondata->insertToRear(result);
    cout << "Size of LinkedList:" << jsondata->size() << endl;
    view();
    /*
    for(const auto& p: information) {
        cout << p.Jsonkey << " : " << p.Jsonval << endl;
    }
    */
}

LinkedList* searchFunc(LinkedList* &jsondata, string searchby, vector<string> match)
{
    LinkedList* result;
    vector<pair<string, string>> v = jsondata->get(0);
    int findattributeindex;
    for(int i = 0; i < v.size(); i++)
    {
        if(searchby == v[i].first)
        {
            findattributeindex = i;
            for(int j = 0; j < match.size(); j++)
            {
                if( match[j] == v[findattributeindex].second)
                {
                    result->insertToRear(jsondata->get(0));
                }
            }
            
            break;
        }
    }

    v.clear();
    for(int i = 1; i < jsondata->size(); i++)
    {
        v = jsondata->get(i);
        for(int j = 0; j < match.size(); j++)
        {
            if( match[j] == v[findattributeindex].second)
            {
                result->insertToRear(jsondata->get(0));
            }
        }
        v.clear();
    }

    return result;
}

void Json::stringparser(string command)
{
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
        temp = command.substr(0,index-1);
        transform(temp.begin(), temp.end(), temp.begin(), ::toupper);
        if (temp == "ASCENDING")
        {
            sortoption = 1;
        }
        else if (temp == "DESCENDING")
        {
            sortoption = 2;
        }
    }
    
    
   switch (choice)
   {
        case 1: //searchFunc(jsondata, attrib, values);
                view();
            break;
        case 2: //jsondata = sortList(attrib, sortoption);
                view();
            break;
        default:
            break;
   }
    
}


void Json::deleteChars(string &command, char t)
{
    //Delete first spaces
    while(command[0] == t)
    {
        command.erase(command.begin(), command.begin());
    }
}

void Json::sortCurrentList()
{
    string col_n;
    int opt;
    cout << "Which column would you like to sort by? (must be integer column) ";
    cin >> col_n;
    cout << "Would you like to do:\n\t1. Ascending Sort\n\t2. Descending Sort\nEnter option: ";
    cin >> opt;

    LinkedList* sortList = jsondata->sortList(col_n, opt);
    sortList->printList();
}