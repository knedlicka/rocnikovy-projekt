//
// Created by prasiatko on 11/16/22.
//

#include <vector>
#include <algorithm>
#include <set>
#include "Tests.h"

int Tests::dummyFunc(int x, int y) {
    return x + y;
}

void Tests::testCombinationsWithoutRepetition() {
    std::vector<int> v = {1, 2, 3};
    int k = 2;
    std::set<std::set<int>> expectedCombinations = {
            {1, 2},
            {1, 3},
            {2, 3}
    };
//    auto calculatedCombinations = // TODO
}
