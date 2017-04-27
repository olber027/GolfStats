//
// Created by molberding on 4/24/2017.
//

#ifndef GOLFSTATS_CAREER_H
#define GOLFSTATS_CAREER_H

#include "Round.h"
#include "Utils.h"
#include <string>
#include <vector>

class Career {
private:
    vector<Round> rounds;

public:

    Career() { rounds = vector<Round>(); }

    void addRound(Round round) {
        rounds.push_back(round);
    }

    string getCareerStats() {
        string stats = "";
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
                        stats += rounds[j].getCourse().getCourseInfo();
                        first = false;
                    }
                    stats += rounds[j].getPrintableScores();
                }
            }
            stats += "\n";
        }
        return stats;
    }
};

#endif //GOLFSTATS_CAREER_H
