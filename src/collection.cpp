#include "collection.h"

namespace fs = std::filesystem;
using namespace std;

    Collection::Collection()
    {
        DIR *directory;
        struct dirent* dent;
        string d = "Database/";
        const char* cname = d.c_str();
        directory=opendir(cname); 
        do 
        {
            dent = readdir(directory);
            if (dent && (dent->d_name[0] != '.') )
            {
                if(checkIFFolder(dent->d_name))
                {
                    cout << "Collection: " << dent->d_name<< endl;
                }
                else
                {
                    cout << "File: " << dent->d_name << endl;
                }
            }
        } while (dent);
        closedir(directory);
    }

    Collection::Collection(string name)
    {
        //this->name = name;
        AddCollection(name);
    }

    void Collection::addcolName(string name)
    {
        collectionName = name;
    }

    string Collection::getColName()
    {
        return collectionName;
    }

    void Collection::AddCollection(string name)
    {
        string dname = "Database/" + name;
        const char* d = dname.c_str();
        fs::create_directories(d);

    }

    void Collection::DeleteCollection(string name)
    {
        if(verifyCollectionExist(name) == true)
        {
            string dname = "Database/" + name;
            uintmax_t deletefolder=  fs::remove_all(dname);
            cout << "Deletion Successful" << endl;
        }
        else
        {
            cout << "Deletion Failed" << endl;
        }
        
    }

    void Collection::ViewCollection(string name)
    {
        DIR *directory;
        struct dirent* dent;
        string d = "Database/" + name;
        const char* cname = d.c_str();
        directory=opendir(cname); 
        do 
        {
            dent = readdir(directory);
            if (dent && (dent->d_name[0] != '.') )
            {
                if(checkIFFolder(dent->d_name))
                {
                    cout << "Collection: " << dent->d_name<< endl;
                }
                else
                {
                    cout << "File: " << dent->d_name << endl;
                }
            }
        } while (dent);
        closedir(directory);
    }

    void Collection::ViewAllCollections()
    {
        DIR *directory;
        struct dirent* dent;
        directory=opendir("Database/"); 
        do 
        {
            dent = readdir(directory);
            if (dent && (dent->d_name[0] != '.') )
            {
                if(checkIFFolder(dent->d_name))
                {
                    cout << "Collection: " << dent->d_name<< endl;
                }
                else
                {
                    //cout << "File: " << dent->d_name << endl;
                }
            }
        } while (dent);
        closedir(directory);   
    }

    bool Collection::checkIFFolder(string s)
    {
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == '.')
            {
                return false;
            }
        }
        return true;
    }

    bool Collection::verifyCollectionExist(string name)
    {
        DIR *directory;
        struct dirent* dent;
        string n = "Database/";
        const char* d = n.c_str();
        directory=opendir(d);
        cout << "137";
        do 
        {
            dent = readdir(directory);
            if (dent && (dent->d_name[0] != '.') )
            {
                cout << "dent->d_name: " << dent->d_name << endl;
                if(checkIFFolder(dent->d_name) && (dent->d_name == name))
                {
                    cout << "here146";
                    return true;
                }
            }
        } while (dent);
        closedir(directory);
        return false;
    }



