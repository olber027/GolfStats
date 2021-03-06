//
// Created by molberding on 4/24/2017.
//

#ifndef GOLFSTATS_GOLFER_H
#define GOLFSTATS_GOLFER_H

#include "Career.h"
#include "Round.h"
#include "Statistics.h"
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

    const bool operator<(const Golfer &golfer) {
        return name < golfer.name;
    }

    void addRound(Round round) {
        career.addRound(round);
    }

    Career getCareer() {
        return career;
    }

    string getName() {
        return name;
    }

    Statistics getStats() {
        return Statistics(career);
    }
};

#endif //GOLFSTATS_GOLFER_H
