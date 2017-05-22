//
// Created by molberding on 4/24/2017.
//

#ifndef GOLFSTATS_CAREER_H
#define GOLFSTATS_CAREER_H

#include "Round.h"
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

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

    vector<Round> getRounds() {
        sort(rounds.begin(), rounds.end());
        return rounds;
    }

    //returns the length of the longest round of the career (used for output purposes)
    int getLongestRoundLength() {
        int longest = 0;
        for(int i = 0; i < rounds.size(); i++) {
            if(rounds[i].getCourse().numberOfHoles() > longest) {
                longest = rounds[i].getCourse().numberOfHoles();
            }
        }
        return longest;
    }
};

#endif //GOLFSTATS_CAREER_H
