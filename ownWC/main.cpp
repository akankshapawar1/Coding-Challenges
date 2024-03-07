#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
using namespace std;

int matchCommand(int s, char com[]){
    char c = com[6];
    if (c == 'c'){
        return 0;
    }else if(c == 'l'){
        return 1;
    }else if(c == 'w'){
        return 2;
    }else if(c == 'm'){
        return 3;
    }
    return 7;
}

void c(string fn){
    fstream file;
    string line;
    file.open(fn, ios::in);
    if(!file){
        cout << "File does not exist";
    }else{
        getline(file, line);
    }
    cout << line.size() << " " << fn;
    file.close();
}

void l(string fn){
    fstream file;
    string line;
    int count = 0;
    file.open(fn, ios::in);
    while (getline(file, line)){
        count++;
    }
    cout << count << " " << fn;
    file.close();
}

void w(string fn){
    fstream file;
    string word;
    int count = 0;
    file.open(fn, ios::in);
    while (file >> word){
        count++;
    }
    cout << count << " " << fn;
    file.close();
}

void m(string fn){
    fstream file;
    string lines;
    int count = 0;
    file.open(fn, ios::in);
    while(getline(file, lines)){
        count = count + lines.length() + 1;
    }
    cout << count << " " << fn;
    file.close();
}

// Avoid allocating array during run-time
// void m(string fn){
//     fstream file;
//     string lines;
//     int count = 0;
//     file.open(fn, ios::in);
//     while(getline(file, lines)){
//         int si = lines.length();
//         char arr[si];
//         strcpy(arr, lines.c_str());
//         int s = sizeof(arr) / sizeof(char);
//         count = count + s;
//     }
//     cout << count << " " << fn;
//     file.close();
// }

string matchFile(int s, char com[]){
    int fileNameSize = s-8;
    int count = 0;
    char fileName[fileNameSize+1];
    for(int i=8; i < s; i++){
        fileName[count]=com[i];
        count++;
    }
    fileName[fileNameSize+1] = '\0';
    return fileName;
}

int main(){
    string command;
    getline(cin, command);
    int si = command.length();
    char char_array[si+1];
    strcpy(char_array, command.c_str());
    int commandNum = matchCommand(si, char_array);
    string fileName = "text";
    fileName = matchFile(si, char_array);
    string fileName2 = fileName.substr(0, fileName.size()-1);
    switch (commandNum){
        case 0:
            c(fileName2);
            break;
        case 1:
            l(fileName2);
            break;
        case 2:
            w(fileName2);
            break;
        case 3:
            m(fileName2);
            break;
        default:
            cout << "Invalid";
            break;
    }
    return 0;
}

/*
1. Check which command is being typed (first focus on c,l,w - which would be 6th element in the array)
2. Check the file path
*/