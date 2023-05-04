#include "json.h"

using namespace std;

void json::intiializeEMPTYjson(string collectionname, string jsonname)
{
    directory = "Database/" + collectionname + jsonname;
    file.open(directory);
    file.close();
}

//Parser could go under here
void json::importJson()
{
    
}

void json::view()
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

void json::edit(vector<pair<string, string>> &data)
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

void json::writeJson() {

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

void json::edit(Node *)
{
    
}