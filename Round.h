//
// Created by molberding on 4/24/2017.
//

#ifndef GOLFSTATS_ROUND_H
#define GOLFSTATS_ROUND_H

#include "Course.h"
#include <vector>
#include <string>
#include <sstream>


class Round {
private:
    Course course;
    vector<Hole> scores;

public:
    Round() : course(Course()) {
        scores = vector<Hole>();
    }

    Round(Course c) : course(c) {
        scores = vector<Hole>();
    }

    Round(const Round &round) {
        course = round.course;
        scores = vector<Hole>();
        for(int i = 0; i < round.scores.size(); i++) {
            scores.push_back(round.scores[i]);
        }
    }

    void addHole(Hole hole) {
        scores.push_back(hole);
    }

    int getFinalScore() {
        int result = 0;
        for(int i = 0; i < scores.size(); i++) {
            result += getHole(i+1).getScore();
        }
        return result;
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

    vector<Hole> getScores() {
        return scores;
    }
    Course getCourse() {
        return course;
    }

};

#endif //GOLFSTATS_ROUND_H
