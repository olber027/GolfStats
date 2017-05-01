//
// Created by molberding on 4/24/2017.
//

#ifndef GOLFSTATS_GOLFER_H
#define GOLFSTATS_GOLFER_H

#include "Career.h"
#include "Round.h"
#include <string>

class Golfer {
private:
    string name;
    Career career;
public:
    Golfer(string Name) : name(Name), career(Career()) {}
    Golfer(const Golfer &golfer) {
        name = golfer.name;
        career = golfer.career;
    }

    void addRound(Round round) {
        career.addRound(round);
    }

    string getCareerStats() {
        stringstream stream;
        stream << "---------"; stream << name << "---------" << endl;
        stream << career.getCareerStats();
        return stream.str();
    }

    string getName() {
        return name;
    }
};

#endif //GOLFSTATS_GOLFER_H
