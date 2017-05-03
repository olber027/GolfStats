//
// Created by molberding on 5/3/2017.
//

#ifndef GOLFSTATS_STATISTICS_H
#define GOLFSTATS_STATISTICS_H

#include "Career.h"
#include "Round.h"
#include "Hole.h"
#include "Course.h"

#include <iostream>

class Statistics {
private:
    Career career;
public:
    Statistics(Career c) : career(c) {}

    Statistics(const Statistics &statistics) {
        career = statistics.career;
    }

    double yardsPerShot() {
        double totalYards = 0.0;
        double totalShots = 0.0;
        vector<Round> rounds = career.getRounds();
        for(int i = 0; i < rounds.size(); i++) {
            vector<Hole> holes = rounds[i].getScores();
            for(int j = 0; j < holes.size(); j++) {
                totalYards += holes[j].getDistance();
                totalShots += holes[j].getScore();
            }
        }
        return totalYards/totalShots;
    }

    int lifetimeOverUnder() {
        int overUnder = 0;
        vector<Round> rounds = career.getRounds();
        for(int i = 0; i < rounds.size(); i++) {
            overUnder += rounds[i].getFinalScore() - rounds[i].getCourse().getPar();
        }
        return overUnder;
    }

    double averageOverUnder() {
        double overUnder = 0.0;
        vector<Round> rounds = career.getRounds();
        for(int i = 0; i < rounds.size(); i++) {
            overUnder += rounds[i].getFinalScore() - rounds[i].getCourse().getPar();
        }
        overUnder /= (double) rounds.size();
        return overUnder;
    }

    double averageOUForHolesBetween(int minDistance, int maxDistance) {
        double average = 0.0;
        int numHoles = 0;

        vector<Round> rounds = career.getRounds();
        for(int i = 0; i < rounds.size(); i++) {
            vector<Hole> holes = rounds[i].getScores();
            for(int j = 0; j < holes.size(); j++) {
                int distance = holes[j].getDistance();
                if(distance >= minDistance && distance <= maxDistance) {
                    average += (holes[j].getScore() - holes[j].getPar());
                    numHoles++;
                }
            }
        }

        if(numHoles <= 0) {
            return -123;
        }

        return (average/numHoles);
    }
};

#endif //GOLFSTATS_STATISTICS_H
