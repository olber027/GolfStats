#include "Golfer.h"
#include "Utils.h"
#include "Statistics.h"
#include "Output.h"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {

    vector<Golfer> golfers = vector<Golfer>();

    string file = getCSVFilePath();
    ifstream in;
    in.open(file);

    file[file.length()-3] = 'o';
    file[file.length()-2] = 'u';
    file[file.length()-1] = 't';
    ofstream out;
    out.open(file, ofstream::out);

    vector<string> row = getLineAndTokenize(in);
    Course currentCourse = Course("");

    while(!in.eof()) {
        if(row.size() <= 0) {
            continue;
        }
        if(row[0] == "course") {
            currentCourse = getCourseInformation(in, row[1]);
        } else if(row[0] != "") {
            Round round = Round(currentCourse);
            for(int i = 1; i < row.size() && row[i] != ""; i++) {
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
        out << center(7*(golfers[i].getCareer().getLongestRound() + 1), golfers[i].getName(), '~') << endl;
        out << golfers[i].getCareer() << endl;
        out << golfers[i].getStats() << endl;
    }

    in.close();
    out.close();

    return 0;
}

