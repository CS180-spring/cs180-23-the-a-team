#ifndef AUTHENTICATION_H
#define AUTHENTICATION_H

#include <random>
#include <sstream>
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;
class authentication
{
    public:
            authentication();
            bool createAccount();
            bool login_user(string username, string password);
    private:
    unordered_map<string, pair<string, string> > user_map;
           string Hashing(string salt, string password);
           string SaltGenerator();
           bool CheckPassword(string password);
           bool storeuser(string username, string hash, string salt);
};

#endif

