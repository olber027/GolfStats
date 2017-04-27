//
// Created by molberding on 4/27/2017.
//

#ifndef GOLFSTATS_UTILS_H
#define GOLFSTATS_UTILS_H

#include <vector>
#include <string>

using namespace std;

bool contains(vector<string> list, string str) {
    for(int i = 0; i < list.size(); i++) {
        if(str == list[i]) {
            return true;
        }
    }
    return false;
}

#endif //GOLFSTATS_UTILS_H
