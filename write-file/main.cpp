#include <iostream>
#include <fstream>
#include <cctype>
#include <cstdlib>
#include <string>
#include <stdio.h>
using namespace std;

char action, actionToLower, idle = 'Y';
string fileName, fileContent;

char optAction(){
    cout << "-------------------------------------" << endl; 
    cout << "Which one do you wanna do?" << endl;
    cout << "c : create file" << endl;
    cout << "r : read file " << endl;
    cout << "u : update file" << endl;
    cout << "d : delete file" << endl;
    cout << ">> ";
    cin >> action;
    return action;
}

void againAction(){
    char again, againToUpper;
    cout << endl;
    cout << "-------------------------------------" << endl;
    cout << "Again? (Y/N): ";
    cin >> again;

    againToUpper = toupper(again);

    if(againToUpper == 'Y'){
        idle = 'Y';
    } else if(againToUpper == 'N'){ 
        idle = 'N';
        cout << "Thank you, goodbye" << endl;       
    } else{
        cout << "Wrong Command" << endl;
        againAction();
    }
}

void createFile(string fileName, string content){
    ofstream MyFile(fileName + ".txt");
    MyFile << content << endl;
    MyFile.close();
}

void readFile(string fileName){
    string myText;
    ifstream MyReadFile(fileName + ".txt");

    cout << "This file contains: " << endl;

    while(getline(MyReadFile, myText)){
        cout << myText << endl;
    }

    MyReadFile.close();
}

int deleteFile(string fileName){
    return remove(fileName.c_str());
}

void createFileAction(){
    cout << "Create File Action" << endl;
    cout << "-----------------------" << endl;
    cout << "Insert your file name and content" << endl;             
    cout << "File Name: ";
    cin >> fileName;
    cout << "File Content: "; 
    cin.clear();
    cin.ignore();
    getline(cin, fileContent);
    createFile(fileName, fileContent); 
}

void readFileAction(){
    cout << "Read File Action" << endl;
    cout << "-----------------------" << endl;
    cout << "Insert your file name: ";
    cin >> fileName;
    readFile(fileName); 
}

void deleteFileAction(){
    int status;
    cout << "Delete File Action" << endl;
    cout << "-----------------------" << endl;
    cout << "Insert your file name: ";
    cin >> fileName; 
    status = deleteFile(fileName + ".txt"); 
    if(status == 0){
        cout << "File successfully deleted" << endl;
    } else{
        cout << "Failed to delete file" << endl;
    }
}

void switchAction(){
    optAction();
    actionToLower = tolower(action);
    switch(actionToLower){
        case 'c':
            createFileAction();
            againAction();
            break;
        case 'r':
            readFileAction();
            againAction();
            break;
        case 'u':
            cout << "Update File Action" << endl;
            break;
        case 'd':
            deleteFileAction();
            againAction();
            break;
        default:
            cout << "There are no commands with that" << endl;
            againAction();
            break;
    }
}

int main(){
    cout << "-------------------------------------" << endl;
    cout << "Welcome to my File Management in C++" << endl;
    while(idle == 'Y'){
        switchAction();
    }

    return 0;
}