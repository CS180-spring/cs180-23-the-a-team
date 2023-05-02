#include "collection.h"

namespace fs = std::experimental::filesystem;

    Collection::Collection()
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
    Collection::Collection(string name)
    {
        this->name = name;
    }
    void Collection::AddCollection(string name)
    {
        string dname = "Database/" + name;
        const char* d = dname.c_str();
        fs::create_directories(d);

        /*
        string directoryname = "Database/";
        const char* d = directoryname.c_str();
        mkdir(d, 0777);

        if (mkdir(d, 0777) == -1)
        cerr << "Error :  " << strerror(errno) << endl;
        else
            cout << "Directory created";
        }
        */
    }
    void Collection::DeleteCollection(string name)
    {

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



