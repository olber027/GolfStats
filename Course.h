//
// Created by molberding on 4/24/2017.
//

#ifndef GOLFSTATS_COURSE_H
#define GOLFSTATS_COURSE_H

#include "Hole.h"
#include <vector>
#include <string>

using namespace std;

class Course {
private:
    vector<Hole> holes;
    string name;
public:
    Course(string Name) : name(Name) { holes = vector<Hole>(); }
    Course(string Name, vector<Hole> holeList) : name(Name), holes(holeList) {}

    string getCourseInfo() {
        string courseInfo = "| ";
        courseInfo += name;
        courseInfo += "\n| ";
        for (int i = 0; i < holes.size(); i++) {
            courseInfo += i + 1; courseInfo += " | ";
        }
        courseInfo += "\n| ";
        for(int i = 0; i < holes.size(); i++) {
            courseInfo += getHole(i+1).getDistance(); courseInfo += " | ";
        }
        courseInfo += getTotalYardage();
        courseInfo += " |\n| ";
        for(int i = 0; i < holes.size(); i++) {
            courseInfo += getHole(i+1).getPar(); courseInfo += " | ";
        }
        courseInfo += getPar();
        courseInfo += " |\n";

        return courseInfo;
    }

    Hole getHole(int holeNumber) {
        if(holeNumber < 0)
            return Hole();
        for(int i = 0; i < holes.size(); i++) {
            if(holes[i].getHoleNumber() == holeNumber)
                return holes[i];
        }
        return Hole();
    }

    int numberOfHoles() {
        return holes.size();
    }

    int getPar() {
        int par = 0;
        for(int i = 0; i < holes.size(); i++) {
            par += holes[i].getPar();
        }
        return par;
    }

    int getTotalYardage() {
        int yardage = 0;
        for(int i = 0; i < holes.size(); i++) {
            yardage += holes[i].getDistance() > 0 ? holes[i].getDistance() : 0;
        }
        return yardage > 0 ? yardage : -1;
    }

    string getCourseName() { return name; }

};


#endif //GOLFSTATS_COURSE_H
