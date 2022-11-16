#ifndef RP_TESTS_H
#define RP_TESTS_H

#include "Combinatorics.h"

class Tests {
    static void testCombinationsWithoutRepetition() {
        std::set<int> s = {1, 2, 3};
        int k = 2;
        std::set<std::set<int>> expectedCombinations = {
                {1, 2},
                {1, 3},
                {2, 3}
        };
        auto calculatedCombinations = Combinatorics::combinations_without_repetitions(s, k);
    if(calculatedCombinations != expectedCombinations) {
        std::cout << "[FAIL] ";
    } else {
        std::cout << "[PASS] ";
    }
    const std::string test_name = "Combinations without repetitions, int, n=3, k=2";
    std::cout << test_name << '\n';
    }
public:
    static void runTests() {
        testCombinationsWithoutRepetition();
    }
};


#endif //RP_TESTS_H
