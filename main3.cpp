#include "encrypt.h"
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {

    Security SE; 
    int choice; 
    string fileInput;
    string fileOutput;
    string encryptedmessage;
    ifstream inputFile(fileInput);
    ifstream outputFile(fileOutput); 
    //wanna read from the encrypted output file and decrypt it back to original

    do {
        cout << "Enter your choice: \n"; 
        cout << "1. Encrypt: \n";
        cout << "2. Decrypt: \n";
        cout << "";

        cin >> choice;
        switch (choice)
        {
            case 1: 
                cout<< "Enter the file name from the collection: \n";
                cin>> fileInput;
                if(SE.openFile(fileInput))
                {
                    inputFile.open(fileInput);
                    string fileContent((istreambuf_iterator<char>(inputFile)), istreambuf_iterator<char>());
                    inputFile.close();
                    encryptedmessage = SE.encrypt(fileContent);
                    //cout << encryptedmessage;
                    cout << "File encrypted successfully. \n";
                    //I don't want the user to see the decrypted message, 
                    //I am going to generate random output file names and save the encrypted messages there and store the encrypted message there for 
                    //developer access only.
                    fileOutput = SE.generateFileName();
                    ofstream outputFile(fileOutput);
                    outputFile << encryptedmessage; 
                    outputFile.close();            
                }
                else
                {
                    cout << "Failed opening the file, try again.\n";
                }
                break;

            case 2:
                cout << "Message is being decrypted....\n";
                //if(SE.openFile(fileOutput))
                //{
                //outputFile.open(fileOutput);
                //string fileContent1((istreambuf_iterator<char>(outputFile)), istreambuf_iterator<char>());
                //inputFile.close();
                {
                    
                int decKey = SE.getKeyShift();
                string decryptedmessage = SE.decrypt(encryptedmessage,decKey);
                //cout << decryptedmessage << endl;
                }
                
                //}else{
                //cout<<"Failed opening the file, try again.\n";
                //}
                break;

            case 3:
                cout << "";
                //call the function

                break;

            default:
                cout << "Invalid choice\n";
        }

    } while (choice != 4);

    return 0;
}
