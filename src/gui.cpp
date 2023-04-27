#include "gui.h"

using namespace std;
void gui::main()
{
    welcome();
    bool user = false;

    do
    {
        if (!user)
        {
            
            login();

        }
        user=true;
        if (user)
        {
            welcome();
            menu(user);
        }
        

    } while (true);
}
void gui::welcome()
{
    cout << "\n***********************" << endl;
    cout << "      FRIENDLYCBD" << endl;
    cout << "\n***********************" << endl;
}
void gui::login()
{
    cout << "\n1. Create an account" << endl;
    cout << "\n2. Log in with an existing account" << endl;
    cout << "\nPress Ctrl+C to exit the program\n" << endl;
    int choice;
    cout<< "Enter your choice: ";
    cin >> choice;
    switch (choice)
    {
    case 1:
        // createAccount();
        cout << "Creating account";
        break;
    case 2:
       // loginAccount();
        cout << "logged in";
        break;
    default:
      cout << "invalid choice, please try again" << endl;
      break;
        
    }
}
void gui::menu(bool& user){
    cout << "\n==========================================\n" << endl;
    cout << "|      1. List all collections           |" << endl;
    cout << "|      2. Read a document                |" << endl;
    cout << "|      3. Create a document              |" << endl;
    cout << "|      4. Update a document              |" << endl;
    cout << "|      5. Delete a document              |" << endl;
    cout << "|      6. Query documents                |" << endl;
    cout << "|      7. Logout                         |" << endl;
    cout << "\n==========================================" << endl;
    cout<< "Enter your choice: ";
    int choice;
    cin >> choice;
    switch (choice){
    case 1:
       // listCollections();
       break;
    case 2:
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
    cout<<"logging out"<<endl;
       user= false;
       break;}

}
