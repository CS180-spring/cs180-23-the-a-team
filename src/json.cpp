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
    vector<int> myVector = {1, 2, 3, 4, 5};
    //string filename = "vector_contents.json";
    string filename = "Database/" + getColName() + "/writetest.json";
    
    ofstream outputFile(filename);
    if (outputFile.is_open()) {
        outputFile << "{\n\t\"numbers\": [";
        for (size_t i = 0; i < myVector.size(); ++i) {
            if (i != 0) {
                outputFile << ", ";
            }
            outputFile << myVector[i];
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
    string d;
    cout << "Please write the path of your input Json: " << endl;
    getline(cin, d);
    file.open(d);
    std::ifstream  From(d, ios::binary);
    std::ofstream  To(directory, ios::binary);
    To << From.rdbuf();
    
}

void Json::view()
{
    int choice;
    cout << "Use number 1 to 3 to control viewer" << endl;
    cout << "1. Edit" << endl;
    cout << "2. Previous" << endl;
    cout << "3. Next" << endl;
    cout << "99. Exit Viewer" << endl;
    do
    {
        //Show the Node
        cin >> choice;
        switch(choice)
        {
            case 1:
                //call edit 
                break;
            case 2:
                //go to previous node
                break;
            case 3:
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

void Json::edit(vector<pair<string, string>> &data)
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

    Document doc;
    doc.ParseStream(isw);
    //struct pairofjson s;
    if (!doc.IsArray()) {
        cout << "Document must be an array" << endl;
    }
    for (auto& itr : doc.GetArray()) {
            for (auto& obj : itr.GetObject()) {
                pair t = make_pair(string(obj.name.GetString()),string(obj.value.GetString()));
                //jsondata->insertToRear();
                /*
                pair.Jsonkey = obj.name.GetString();
                pair.Jsonval = obj.value.GetString();
                //information.push_back(pair);
                */
            }
        }
    /*
    for(const auto& p: information) {
        cout << p.Jsonkey << " : " << p.Jsonval << endl;
    }
    */
}
