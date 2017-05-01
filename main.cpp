#include "Golfer.h"
#include "Course.h"
#include "Round.h"
#include "Career.h"
#include "Hole.h"
#include "Utils.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "Windows.h"
#include "Commdlg.h"

using namespace std;

string getCSVFilePath();
Course getCourseInformation(ifstream& in, string courseName);
vector<string> getLineAndTokenize(istream& str);
int stringToInt(string str);

int main() {

    vector<Golfer> golfers = vector<Golfer>();
    vector<Course> courses = vector<Course>();

    string file = getCSVFilePath();
    ifstream in;
    in.open(file);

    vector<string> row = getLineAndTokenize(in);
    Course currentCourse = Course("");

    while(!in.eof()) {
        if(row.size() <= 0) {
            continue;
        }
        if(row[0] == "course") {
            currentCourse = getCourseInformation(in, row[1]);
            courses.push_back(currentCourse);
        } else if(row[0] != "") {
            Round round = Round(currentCourse);
            for(int i = 1; i < row.size(); i++) {
                Hole hole = currentCourse.getHole(i);
                hole.setScore(stringToInt(row[i]));
                round.addHole(hole);
            }
            bool golferExisted = false;
            for(int i = 0; i < golfers.size(); i++) {
                if(golfers[i].getName() == row[0]) {
                    golfers[i].addRound(round);
                    golferExisted = true;
                }
            }
            if(!golferExisted) {
                golfers.push_back(Golfer(row[0]));
                golfers[golfers.size()-1].addRound(round);
            }
        }
        row = getLineAndTokenize(in);
    }

    for(int i = 0; i < golfers.size(); i++) {
        cout << golfers[i].getCareerStats(); cout << endl;
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

Course getCourseInformation(ifstream& in, string courseName) {
    vector<Hole> holes = vector<Hole>();
    vector<string> parRow = getLineAndTokenize(in);
    vector<string> distanceRow = getLineAndTokenize(in);
    int size = parRow.size(); // parRow and distanceRow should be the same length.
    for(int i = 1; i < size; i++) {
        Hole hole = Hole(stringToInt(distanceRow[i]), stringToInt(parRow[i]), i, -1);
        holes.push_back(hole);
    }
    Course course = Course(courseName, holes);
    course.getCourseInfo();
    return course;
}

int stringToInt(string str) {
    return atoi(str.c_str());
}

vector<string> getLineAndTokenize(istream& str)
{
    vector<string> result;
    string line;
    getline(str,line);
    cout << "got line: \"" << line << "\"" << endl;
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

