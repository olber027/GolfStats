//
// Created by molberding on 4/24/2017.
//

#ifndef GOLFSTATS_ROUND_H
#define GOLFSTATS_ROUND_H

#include "Course.h"
#include <vector>
#include <string>


class Round {
private:
    Course course;
    vector<Hole> scores;

public:
    Round(Course c) : course(c) { scores = vector<Hole>(); }

    void addHole(Hole hole) {
        scores.push_back(hole);
    }

    string getPrintableScores() {
        string Scores = "| ";
        for(int i = 0; i < scores.size(); i++) {
            Scores += getHole(i+1).getScore(); Scores += " | ";
        }
        Scores += "\n";
        return Scores;
    }

    Hole getHole(int holeNumber) {
        if(holeNumber < 0)
            return Hole();
        for(int i = 0; i < scores.size(); i++) {
            if(scores[i].getHoleNumber() == holeNumber)
                return scores[i];
        }
        return Hole();
    }

    vector<Hole> getScores() { return scores; }
    Course getCourse() { return course; }

};

#endif //GOLFSTATS_ROUND_H
