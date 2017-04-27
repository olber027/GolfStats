#include "Golfer.h"
#include "Course.h"
#include "Round.h"
#include "Career.h"
#include "Hole.h"
#include "Utils.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Windows.h"
#include "Commdlg.h"

using namespace std;

string getCSVFilePath();
Course getCourseInformation(ifstream& in);
string stripWhitespace(string str);
vector<string> splitLine(string line);
string getline(ifstream& in);

int main() {

    vector<Golfer> golfers = vector<Golfer>();

    string file = getCSVFilePath();
    ifstream in;
    in.open(file);
    char garbage;
    string line;

    in >> garbage;

    while(!in.eof()) {
        cout << "\"" << garbage << "\"" << endl;
        /*
        vector<string> separated = splitLine(line);
        for(int i = 0; i < separated.size(); i++) {
            cout << "\"" << separated[i] << "\" ";
        }
        cout << endl;
         */
        //Course currentCourse = getCourseInformation(in);
        //Round round(currentCourse);
        in >> garbage;
    }

    for(int i = 0; i < golfers.size(); i++) {
        cout << "----------------------------------------------" << endl;
        cout << golfers[i].getName() << endl;
        cout << "----------------------------------------------" << endl;

        cout << golfers[i].getCareerStats() << endl;
    }

    return 0;
}


string getCSVFilePath() {
    OPENFILENAME ofn;       // common dialog box structure
    char szFile[260];       // buffer for file name
    HWND hwnd = CreateWindow("STATIC","File Explorer",WS_MINIMIZE,0,0,100,100,NULL,NULL,NULL,NULL);
    HANDLE hf;              // file handle

    // Initialize OPENFILENAME
    ZeroMemory(&ofn, sizeof(ofn));
    ofn.lStructSize = sizeof(ofn);
    ofn.hwndOwner = hwnd;
    ofn.lpstrFile = szFile;
    // Set lpstrFile[0] to '\0' so that GetOpenFileName does not
    // use the contents of szFile to initialize itself.
    ofn.lpstrFile[0] = '\0';
    ofn.nMaxFile = sizeof(szFile);
    ofn.lpstrFilter = "*.csv\0"; //can change these to whatever file extensions you want visible
    ofn.nFilterIndex = 1;
    ofn.lpstrFileTitle = NULL;
    ofn.nMaxFileTitle = 0;
    ofn.lpstrInitialDir = "C:\\"; //change this to wherever you want the window to open to.
    ofn.Flags;

    if(GetOpenFileName(&ofn) == TRUE) {
        return ofn.lpstrFile;
    } else {
        cout << CommDlgExtendedError() << endl;
        return "";
    }
}

Course getCourseInformation(ifstream& in) {
    //get course name
    string courseName = "";
    //get par
    //get yardage
    //create hole list
    return Course(courseName);
}

string stripWhitespace(string str) {
    for(int i = 0; i < str.length(); i++) {
        if(str[i] == ' ' || str[i] == '\n' || str[i] == '\t') {
            str[i] = '\0';
        }
    }
    return str;
}

vector<string> splitLine(string line) {
    vector<string> parts = vector<string>();
    string temp = "";
    for(int i = 0; i < line.length(); i++) {
        if(line[i] != ',') {
            temp += line[i];
        } else {
            if(temp.length() > 0) {
                parts.push_back(temp);
                temp = "";
            }
        }
    }
    temp = stripWhitespace(temp);
    if(temp.length() > 0) {
        parts.push_back(temp);
    }
    return parts;
}

string getline(ifstream& in) {
    string line = "";
    char nextCharacter = '\0';
    in >> nextCharacter;
    while(nextCharacter != '\n') {
        line += nextCharacter;
        in >> nextCharacter;
    }
    return line;
}

