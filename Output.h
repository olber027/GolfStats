//
// Created by molberding on 5/3/2017.
//

#ifndef GOLFSTATS_OUTPUT_H
#define GOLFSTATS_OUTPUT_H

#include "Golfer.h"
#include "Course.h"
#include "Round.h"
#include "Career.h"
#include "Hole.h"
#include "Utils.h"

#include <iostream>
#include <vector>

int getWidth(int number) {
    int width = 0;
    while(number > 0) {
        number /= 10;
        width++;
    }
    return width;
}

string center(int desiredWidth, string stringToCenter, char paddingCharacter) {
    int width = stringToCenter.length();
    stringstream result;
    if(width >= desiredWidth) {
        result << stringToCenter;
        return result.str();
    }
    int necessaryPadding = desiredWidth - width;

    for(int i = necessaryPadding; i > necessaryPadding/2; i--) {
        result << paddingCharacter;
    }
    result << stringToCenter;
    for(int i = necessaryPadding/2; i > 0; i--) {
        result << paddingCharacter;
    }

    return result.str();
}

string center(int desiredWidth, string stringToCenter) {
    return center(desiredWidth, stringToCenter, ' ');
}

string center(int desiredWidth, int numberToCenter) {
    stringstream stream;
    stream << numberToCenter;
    return center(desiredWidth, stream.str(), ' ');
}

ostream& operator<<(ostream& out, Course course) {

    int width = getWidth(course.getTotalYardage());
    int lineLength = (width + 3) * (course.numberOfHoles() + 1);
    out << "|" << center(lineLength-1, course.getCourseName()) << "|" << endl;

    out << "| ";
    for(int i = 1; i <= course.numberOfHoles(); i++) {
        out << center(width, i) << " | ";
    }
    out << endl << "| ";
    for(int i = 1; i <= course.numberOfHoles(); i++) {
        out << center(width, course.getHole(i).getPar()) << " | ";
    }
    out << center(width, course.getPar()) << " |" << endl << "| ";
    for(int i = 1; i <= course.numberOfHoles(); i++) {
        out << center(width, course.getHole(i).getDistance()) << " | ";
    }
    out << center(width, course.getTotalYardage()) << " |" << endl;
    return out;
}

ostream& operator<<(ostream& out, Golfer golfer) {

    out << golfer.getName();

    return out;
}

ostream& operator<<(ostream& out, Round round) {

    int width = getWidth(round.getCourse().getTotalYardage());

    out << round.getCourse();
    int lineLength = (width + 3) * (round.getCourse().numberOfHoles() + 1);
    for(int i = 0; i <= lineLength; i++) {
        out << "-";
    }
    out << endl << "| ";

    for(int i = 1; i <= round.getCourse().numberOfHoles(); i++) {
        out << center(width, round.getHole(i).getScore()) << " | ";
    }
    out << center(width, round.getFinalScore()) << " |" << endl;

    return out;
}

ostream& operator<<(ostream& out, vector<Round> rounds) {

    vector<string> courseNames = vector<string>();
    for(int i = 0; i < rounds.size(); i++) {
        if(!contains(courseNames, rounds[i].getCourse().getCourseName())) {
            courseNames.push_back(rounds[i].getCourse().getCourseName());
        }
    }

    for(int i = 0; i < courseNames.size(); i++) {
        bool first = true;
        for(int j = 0; j < rounds.size(); j++) {
            Round round = rounds[j];
            int width = getWidth(round.getCourse().getTotalYardage());
            if(round.getCourse().getCourseName() == courseNames[i]) {
                if(first) {
                    out << round.getCourse();
                    int lineLength = (width + 3) * (round.getCourse().numberOfHoles() + 1);
                    for(int i = 0; i <= lineLength; i++) {
                        out << "-";
                    }
                    out << endl;
                    first = false;
                }
                out << "| ";
                for(int i = 1; i <= round.getCourse().numberOfHoles(); i++) {
                    out << center(width, round.getHole(i).getScore()) << " | ";
                }
                out << center(width, round.getFinalScore()) << " |" << endl;
            }
        }
        out << endl;
    }

    return out;
}

ostream& operator<<(ostream& out, Career career) {

    out << career.getRounds();

    return out;
}

#endif //GOLFSTATS_OUTPUT_H
