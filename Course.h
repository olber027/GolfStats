//
// Created by molberding on 4/24/2017.
//

#ifndef GOLFSTATS_COURSE_H
#define GOLFSTATS_COURSE_H

#include "Hole.h"
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Course {
private:
    vector<Hole> holes;
    string name;
public:
    Course() : name("") {
        holes = vector<Hole>();
    }
    Course(string Name) : name(Name) {
        holes = vector<Hole>();
    }
    Course(string Name, vector<Hole> holeList) : name(Name), holes(holeList) { }

    Course(const Course &course) {
        holes = vector<Hole>();
        for(int i = 0; i < course.holes.size(); i++) {
            holes.push_back(course.holes[i]);
        }
        name = course.name;
    }

    string getCourseInfo() {
        stringstream stream;
        stream << "| ";
        stream << name;
        stream << " |" << endl << "| ";
        for (int i = 0; i < holes.size(); i++) {
            stream << i+1 << " | ";
        }
        stream << endl << "| ";
        for(int i = 0; i < holes.size(); i++) {
            stream << getHole(i+1).getDistance() << " | ";
        }
        stream << getTotalYardage() << " |\n| ";
        for(int i = 0; i < holes.size(); i++) {
            stream << getHole(i+1).getPar() << " | ";
        }
        stream << getPar() << " |\n";
        return stream.str();
    }

    Hole getHole(int holeNumber) {
        if(holeNumber < 0) {
            return Hole();
        }
        for(int i = 0; i < holes.size(); i++) {
            if(holes[i].getHoleNumber() == holeNumber) {
                return holes[i];
            }
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

    string getCourseName() {
        return name;
    }

};


#endif //GOLFSTATS_COURSE_H
