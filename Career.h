//
// Created by molberding on 4/24/2017.
//

#ifndef GOLFSTATS_CAREER_H
#define GOLFSTATS_CAREER_H

#include "Round.h"
#include "Utils.h"
#include <string>
#include <vector>
#include <sstream>

class Career {
private:
    vector<Round> rounds;

public:

    Career() {
        rounds = vector<Round>();
    }
    Career(const Career &career) {
        rounds = vector<Round>();
        for(int i = 0; i < career.rounds.size(); i++) {
            rounds.push_back(career.rounds[i]);
        }
    }

    void addRound(Round round) {
        rounds.push_back(round);
    }

    string getCareerStats() {
        stringstream stream;
        vector<string> courseNames = vector<string>();
        for(int i = 0; i < rounds.size(); i++) {
            if(!contains(courseNames, rounds[i].getCourse().getCourseName())) {
                courseNames.push_back(rounds[i].getCourse().getCourseName());
            }
        }
        for(int i = 0; i < courseNames.size(); i++) {
            bool first = true;
            for(int j = 0; j < rounds.size(); j++) {
                if(rounds[j].getCourse().getCourseName() == courseNames[i]) {
                    if(first) {
                        stream << rounds[j].getCourse().getCourseInfo();
                        for(int i = 0; i < rounds[j].getCourse().numberOfHoles() * 6; i++) {
                            stream << "-";
                        }
                        stream << endl;
                        first = false;
                    }
                    stream << rounds[j].getPrintableScores();
                }
            }
            stream << endl;
        }
        return stream.str();
    }
};

#endif //GOLFSTATS_CAREER_H
