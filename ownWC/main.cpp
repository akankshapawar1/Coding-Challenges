#include <iostream>
#include <string>
#include <fstream>
#include <regex>
using namespace std;

// Read each line, get that line's size (returns length of the string in terms of bytes), add one byte for new line character
void c(string fn){
    fstream file;
    string line;
    file.open(fn, ios::in);
    int size = 0;
    while(getline(file, line)){
        size = size + line.size() + 1;
    }
    cout << size << " ";
    file.close();
}

// while a file is being read, increment counter for each line
void l(string fn){
    fstream file;
    string line;
    int count = 0;
    file.open(fn, ios::in);
    while (getline(file, line)){
        count++;
    }
    cout << count << " ";
    file.close();
}

// Extraction operator >> skips whitespaces and reads until next whitespace.
// a >> b is left to right. a's value is assigned to b.
void w(string fn){
    fstream file;
    string word;
    int count = 0;
    file.open(fn, ios::in);
    while (file >> word){
        count++;
    }
    cout << count << " ";
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
    cout << count << " ";
    file.close();
}

int main(){
    string command;
    string ccwc = "ccwc";
    string dash = "-";
    string filename;
    char flag = 'a';
    int dashAt = -1;
    regex e ("[a-zA-Z0-9]+\\.[a-zA-Z]+");
    smatch matchedString;

    getline(cin, command);
    regex_search(command, matchedString, e);
    filename = matchedString.str(0);

    if(command.find(ccwc) != std::string::npos){
        dashAt = command.find(dash);
        if(dashAt != -1){
            flag = command[dashAt + 1];
            switch (flag)
            {
            case 'l':
                l(filename);
                cout << filename;
                break;
            case 'c':
                c(filename);
                cout << filename;
                break;
            case 'm':
                m(filename);
                cout << filename;
                break;
            case 'w':
                w(filename);
                cout << filename;
                break;
            default:
                break;
            }
        }else{
            l(filename);
            w(filename);
            c(filename);
            cout << filename;
        }
    }

}