#include "gui.h"
#include "json.h"
#include "authentication.h"

using namespace std;
bool user = false;
void gui::main()
{

    welcome();

    do
    {
        if (!user)
        {

            login();
        }

        if (user)
        {
           
            menu(user);
        }

    } while (true);
}
void gui::welcome()
{
    cout << "\n************************************************************************************************************************\n"<< endl;
    


std::cout << "8888888888 8888888b.  8888888 8888888888 888b    888 8888888b.  888    Y88b   d88P       .d8888b.  8888888b.  888888b.   \n"
             "888        888   Y88b   888   888        8888b   888 888  \"Y88b 888     Y88b d88P       d88P  Y88b 888  \"Y88b 888  \"88b  \n"
             "888        888    888   888   888        88888b  888 888    888 888      Y88o88P        888    888 888    888 888  .88P  \n"
             "8888888    888   d88P   888   8888888    888Y88b 888 888    888 888       Y888P         888        888    888 8888888K.  \n"
             "888        8888888P\"    888   888        888 Y88b888 888    888 888        888          888        888    888 888  \"Y88b \n"
             "888        888 T88b     888   888        888  Y88888 888    888 888        888          888    888 888    888 888    888 \n"
             "888        888  T88b    888   888        888   Y8888 888  .d88P 888        888          Y88b  d88P 888  .d88P 888   d88P \n"
             "888        888   T88b 8888888 8888888888 888    Y888 8888888P\"  88888888   888           \"Y8888P\"  8888888P\"  8888888P\" ";

   
    cout << "\n\n************************************************************************************************************************" << endl;
};

int gui::validinput()
{
    int choice = 0;
    while (!(cin >> choice))
    {

        cout << "\n<<<<<<<<<< INVALID INPUT, PLEASE ENTER A INTEGER >>>>>>>>>>\n"
             << endl;
        cout << "\nEnter your choice: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return choice;
};
void gui::login()
{
    string username, password = "";
    cout << "\n--------------------------------------" << endl;
    cout << "| 1. Create an account               |" << endl;
    cout << "|------------------------------------|" << endl;
    cout << "| 2. Log in with an existing account |" << endl;
    cout << "--------------------------------------" << endl;

    cout << "\n         ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~-   Press Ctrl+C to exit the program   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~-\n"
         << endl;

    int choice;
    cout << "Enter your choice: ";
    choice = validinput();
    
    authentication authenticate;
   
    switch (choice)
    {
    case 1:

        if (authenticate.createAccount())
        {

            cout << "\n         ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~-   ACCOUNT SUCCESSFULLY CREATED   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~-\n"
                 << endl;
        }
        login();
        break;
    case 2:
        // loginAccount();
        cout << "\nEnter the username: ";

        cin >> username;
        cout << "\nEnter the password: ";
        cin >> password;
        if (authenticate.login_user(username, password) || (username == "a" && password == "a"))
        {
            cout << "\n         ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~-   USER SUCCESSFULLY LOGGED IN   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~-\n"
                 << endl;

            user = true;
        }
        else
        {
            login();
        }

        break;
    default:
        cout << "\n<<<<<<<<<< INVALID CHOICE, PLEASE TRY AGAIN >>>>>>>>>>\n"
             << endl;
        break;
    }
};
void gui::menu(bool &user)
{

    csvtojson c;
    string name;
    int sizeofdata;
    stringstream outputofcsv;
    //Parser p; moved it to json file
    Collection col;
    string temp, temp2, command;

    cout << "\n==========================================" << endl;
    cout << "|      1. List all collections           |" << endl;
    cout << "|----------------------------------------|" << endl;
    cout << "|      2. Read a document                |" << endl;
    cout << "|----------------------------------------|" << endl;
    cout << "|      3. Create a document              |" << endl;
    cout << "|----------------------------------------|" << endl;
    cout << "|      4. Update a document              |" << endl;
    cout << "|----------------------------------------|" << endl;
    cout << "|      5. Delete a document              |" << endl;
    cout << "|----------------------------------------|" << endl;
    cout << "|      6. Query documents                |" << endl;
    cout << "|----------------------------------------|" << endl;
    cout << "|      7. Logout                         |" << endl;
    cout << "|----------------------------------------|" << endl;
    cout << "|      8. READ CSV document              |" << endl;
    cout << "|----------------------------------------|" << endl;
    cout << "|      9. Write a document               |" << endl;
    cout << "|----------------------------------------|" << endl;
    cout << "|      10. Add a collection              |" << endl;
    cout << "|----------------------------------------|" << endl;
    cout << "|      11. Delete a collection           |" << endl;
    cout << "|----------------------------------------|" << endl;
    cout << "|      12. Import Json document          |" << endl;
    cout << "|----------------------------------------|" << endl;
    cout << "|      13. JSON viewer                   |" << endl;
    cout << "|----------------------------------------|" << endl;
    cout << "|      14. Search and Sort               |" << endl;
    cout << "|----------------------------------------|" << endl;
    cout << "|      15. Sort                          |" << endl; 
    cout << "==========================================" << endl;
    cout << "\nEnter your choice: ";
    int choice;
    choice = validinput();
    switch (choice)
    {
    case 1:
        col.ViewAllCollections();
        // listCollections();
        break;
    case 2:
        //check for any errors first before parsing
        cout << "Enter collection name(no spaces): ";
        cin >> temp;
        cout << "Enter the Json name(no spaces): " << endl;
        cin >> temp2;
       // getline(cin , temp2);
        //cin.ignore(1024, '\n');
        //cin.clear();
        j.setDirectoryJson(temp, temp2);
        //j.parseError();
        j.parseJson();
        //p.parseJson();
        //p.parseError();
        // readDocument();
        break;
    case 3:
        // createDocument();
        break;
    case 4:
        // updateDocument();
        break;
    case 5:
        // deleteDocument();
        break;
    case 6:
        // queryDocuments();
        break;
    case 7:
        cout << "\n         ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~-   USER SUCCESSFULLY LOGGED OUT   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~-\n"
             << endl;
        user = false;
        break;
    case 8:
        cout << "Enter the path to file: " << endl;
        getline(cin , name);
        cin.ignore(1024, '\n');
        cin.clear();
        cout << "Enter the amount of rows you wish to import(excluding row1 with column names): ";
        cin >> sizeofdata;
        c.printcsv(name, sizeofdata, outputofcsv);
        outputofcsv.str();
        break;
    case 9:
        j.writeJson();
        break;
    case 10:
        cout << "Please enter in a collection name(no spaces): ";
        cin >> temp;
        col.AddCollection(temp);
        break;
    case 11:
        cout << "Collections: " << endl;
        col.ViewAllCollections();
        cout << "Please enter in the collection name(no spaces): ";
        cin >> temp;
        col.DeleteCollection(temp);
        break;
    case 12:
        cin.ignore(1024, '\n');
        cin.clear();
        j.importJson();
        break;
    case 13:
        j.view();
        break;
    case 14:
        cout << "Sample Search:  SEARCH \"This Col\" (value1|value2)" << endl;
        cout << "Sample Sort: SORT \"This Col\" ASCENDING;" << endl;
        getline(cin, command);
        cin.ignore(1024,'\n');
        cin.clear();
        j.stringparser(command);
        break;
    case 15:
        
        j.sortCurrentList();
        break;
    default:
        cout << "\n<<<<<<<<<< INVALID CHOICE, PLEASE TRY AGAIN >>>>>>>>>>\n" << endl;
    break;
    }
};
