//
// Created by molberding on 4/24/2017.
//

#ifndef GOLFSTATS_HOLE_H
#define GOLFSTATS_HOLE_H

class Hole {
private:
    int distance;
    int par;
    int score;
    int holeNumber;

public:
    Hole(int Distance, int Par, int Number, int Score) : distance(Distance), par(Par), holeNumber(Number), score(Score) { }
    Hole(Hole hole, int Score) : Hole(hole.getDistance(), hole.getPar(), hole.getHoleNumber(), Score) { }
    Hole(int Distance, int Par, int Number) : Hole(Distance, Par, Number, -1) { }
    Hole(int Par, int Number) : Hole(-1, Par, Number, -1) { }
    Hole() : Hole(-1, -1, -1, -1) { }

    Hole(const Hole &hole) {
        distance = hole.distance;
        par = hole.par;
        score = hole.score;
        holeNumber = hole.holeNumber;
    }

    int getDistance() {
        return distance;
    }
    int getPar() {
        return par;
    }
    int getScore() {
        return score;
    }
    int getHoleNumber() {
        return holeNumber;
    }
    int setDistance(int Distance) {
        distance = Distance;
    }
    int setPar(int Par) {
        par = Par;
    }
    int setScore(int Score) {
        score = Score;
    }
    int setHoleNumber(int number) {
        holeNumber = number;
    }
};

#endif //GOLFSTATS_HOLE_H
