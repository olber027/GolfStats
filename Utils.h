//
// Created by molberding on 4/27/2017.
//

#ifndef GOLFSTATS_UTILS_H
#define GOLFSTATS_UTILS_H

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include "Windows.h"
#include "Commdlg.h"

using namespace std;

bool contains(vector<string> list, string str) {
    for(int i = 0; i < list.size(); i++) {
        if(str == list[i]) {
            return true;
        }
    }
    return false;
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

vector<string> getLineAndTokenize(istream& str)
{
    vector<string> result;
    string line;
    getline(str,line);
    string cell;

    int firstCommaIndex = 0;
    int secondCommaIndex;
    for(int i = 0; i < line.length(); i++) {
        if(line[i] == ',') {
            secondCommaIndex = i;
            cell = "";
            for(int j = firstCommaIndex; j < secondCommaIndex; j++) {
                cell += line[j];
            }
            result.push_back(cell);
            firstCommaIndex = secondCommaIndex+1;
        }
    }
    if(firstCommaIndex <= line.length() - 1) {
        cell = "";
        for(int j = firstCommaIndex; j < line.length(); j++) {
            cell += line[j];
        }
        result.push_back(cell);
    }
    return result;
}

int stringToInt(string str) {
    return atoi(str.c_str());
}

string doubleToString(double num) {
    stringstream temp;
    stringstream result;
    temp << num;
    for(int i = 0; i < 4 && i < temp.str().length(); i++) {
        result << temp.str()[i];
    }
    return result.str();
}

Course getCourseInformation(ifstream& in, string courseName) {
    vector<Hole> holes = vector<Hole>();
    vector<string> parRow = getLineAndTokenize(in);
    vector<string> distanceRow = getLineAndTokenize(in);
    int size = parRow.size(); // parRow and distanceRow should be the same length.
    for(int i = 1; i < size; i++) {
        if(distanceRow[i] != "" && parRow[i] != "") {
            Hole hole = Hole(stringToInt(distanceRow[i]), stringToInt(parRow[i]), i, -1);
            holes.push_back(hole);
        }
    }

    Course course = Course(courseName, holes);

    return course;
}

#endif //GOLFSTATS_UTILS_H
