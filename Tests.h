#ifndef RP_TESTS_H
#define RP_TESTS_H

#include "Combinatorics.h"


static void testCombinationsWithoutRepetitionInt() {
    std::set<int> s = {1, 2, 3};
    int k = 2;
    std::set<std::set<int>> expectedCombinations = {
            {1, 2},
            {1, 3},
            {2, 3}
    };
    auto calculatedCombinations = combinations_without_repetitions(s, k);
if(calculatedCombinations != expectedCombinations) {
    std::cout << "[FAIL] ";
} else {
    std::cout << "[PASS] ";
}
const std::string test_name = "Combinations without repetitions, int, n=3, k=2";
std::cout << test_name << '\n';
}

static void testCombinationsWithoutRepetitionChar() {
    std::set<char> s = {'A', 'B', 'C', 'D', 'E', 'F'};
    int k = 3;
    std::set<std::set<char>> expectedCombinations = {
            {'A', 'B', 'C'},
            {'A', 'B', 'D'},
            {'A', 'B', 'E'},
            {'A', 'B', 'F'},
            {'A', 'C', 'D'},
            {'A', 'C', 'E'},
            {'A', 'C', 'F'},
            {'A', 'D', 'E'},
            {'A', 'D', 'F'},
            {'A', 'E', 'F'},
            {'B', 'C', 'D'},
            {'B', 'C', 'E'},
            {'B', 'C', 'F'},
            {'B', 'D', 'E'},
            {'B', 'D', 'F'},
            {'B', 'E', 'F'},
            {'C', 'D', 'E'},
            {'C', 'D', 'F'},
            {'C', 'E', 'F'},
            {'D', 'E', 'F'}
    };
    auto calculatedCombinations = combinations_without_repetitions(s, k);
    if(calculatedCombinations != expectedCombinations) {
        std::cout << "[FAIL] ";
    } else {
        std::cout << "[PASS] ";
    }
    const std::string test_name = "Combinations without repetitions, char, n=6, k=3";
    std::cout << test_name << '\n';
}

static void testCombinationsWithRepetitionInt() {
    std::set<int> s = {1, 2, 3, 4};
    int k = 2;
    std::set<std::multiset<int>> expectedCombinations = {
            {1, 1},
            {1, 2},
            {1, 3},
            {1, 4},
            {2, 2},
            {2, 3},
            {2, 4},
            {3, 3},
            {3, 4},
            {4, 4}
    };

    auto calculatedCombinations = combinations_with_repetitions(s, k);
    if(calculatedCombinations != expectedCombinations) {
        std::cout << "[FAIL] ";
    } else {
        std::cout << "[PASS] ";
    }
    const std::string test_name = "Combinations with repetitions, int, n=4, k=2";
    std::cout << test_name << '\n';
}

static void testCombinationsWithRepetitionString() {
    std::set<std::string> s = {"a", "b", "c", "d"};
    int k = 3;
    std::set<std::multiset<std::string>> expectedCombinations = {
            {"a", "a", "a"},
            {"a", "a", "b"},
            {"a", "a", "c"},
            {"a", "a", "d"},
            {"a", "b", "b"},
            {"a", "b", "c"},
            {"a", "b", "d"},
            {"a", "c", "c"},
            {"a", "c", "d"},
            {"a", "d", "d"},
            {"b", "b", "b"},
            {"b", "b", "c"},
            {"b", "b", "d"},
            {"b", "c", "c"},
            {"b", "c", "d"},
            {"b", "d", "d"},
            {"c", "c", "c"},
            {"c", "c", "d"},
            {"c", "d", "d"},
            {"d", "d", "d"}

    };
    auto calculatedCombinations = combinations_with_repetitions(s, k);
    if(calculatedCombinations != expectedCombinations) {
        std::cout << "[FAIL] ";
    } else {
        std::cout << "[PASS] ";
    }
    const std::string test_name = "Combinations with repetitions, string, n=4, k=3";
    std::cout << test_name << '\n';
}

static void testPermutationWithRepetitionInt() {
    std::multiset<int> s = {1, 2, 2};
    std::set<std::vector<int>> expectedPermutations = {
            {1, 2, 2},
            {1, 2, 2},
            {2, 1, 2},
            {2, 2, 1},
            {2, 1, 2},
            {2, 2, 1}
    };
    auto calculatedCombinations = permutations_with_repetitions(s);
    if(calculatedCombinations != expectedPermutations) {
        std::cout << "[FAIL] ";
    } else {
        std::cout << "[PASS] ";
    }
    const std::string test_name = "Permutations with repetitions, int, n=3";
    std::cout << test_name << '\n';
}

static void testPermutationWithRepetitionChar() {
    std::multiset<char> s = {'a', 'a', 'b', 'b'};
    std::set<std::vector<char>> expectedPermutations = {
            {'a', 'a', 'b', 'b'},
            {'a', 'b', 'a', 'b'},
            {'a', 'b', 'b', 'a'},
            {'b', 'a', 'b', 'a'},
            {'b', 'b', 'a', 'a'},
            {'b', 'a', 'a', 'b'},
    };
    auto calculatedCombinations = permutations_with_repetitions(s);
    if(calculatedCombinations != expectedPermutations) {
        std::cout << "[FAIL] ";
    } else {
        std::cout << "[PASS] ";
    }
    const std::string test_name = "Permutations with repetitions, char, n=4";
    std::cout << test_name << '\n';
}

static void testPermutationWithoutRepetitionInt() {
    std::set<int> s = {1, 2, 3};
    std::set<std::vector<int>> expectedPermutations = {
            {1, 2, 3},
            {1, 3, 2},
            {2, 1, 3},
            {2, 3, 1},
            {3, 1, 2},
            {3, 2, 1}
    };
    auto calculatedCombinations = permutations_without_repetitions(s);
    if(calculatedCombinations != expectedPermutations) {
        std::cout << "[FAIL] ";
    } else {
        std::cout << "[PASS] ";
    }
    const std::string test_name = "Permutations without repetitions, int, n=3";
    std::cout << test_name << '\n';
}

static void testPermutationWithoutRepetitionString() {
    std::set<std::string> s = {"355", "867"};
    std::set<std::vector<std::string>> expectedPermutations = {
            {"355", "867"},
            {"867", "355"}
    };
    auto calculatedCombinations = permutations_without_repetitions(s);
    if(calculatedCombinations != expectedPermutations) {
        std::cout << "[FAIL] ";
    } else {
        std::cout << "[PASS] ";
    }
    const std::string test_name = "Permutations without repetitions, string, n=2";
    std::cout << test_name << '\n';
}

static void testArrangemetsWithoutRepetitionInt() {
    std::set<int> s = {1, 2, 3};
    int k = 2;
    std::set<std::vector<int>> expectedPermutations = {
            {1, 2},
            {2, 1},
            {1, 3},
            {3, 1},
            {2, 3},
            {3, 2}
    };
    auto calculatedCombinations = arrangements_without_repetitions(s, k);
    if(calculatedCombinations != expectedPermutations) {
        std::cout << "[FAIL] ";
    } else {
        std::cout << "[PASS] ";
    }
    const std::string test_name = "Arrangemets without repetitions, int, n=3, k = 2";
    std::cout << test_name << '\n';
}

static void testArrangemetsWithoutRepetitionChar() {
    std::set<char> s = {'A', 'B', 'C'};
    int k = 3;
    std::set<std::vector<char>> expectedPermutations = {
            {'A', 'B', 'C'},
            {'A', 'C', 'B'},
            {'B', 'A', 'C'},
            {'B', 'C', 'A'},
            {'C', 'A', 'B'},
            {'C', 'B', 'A'},
            {'C', 'B', 'A'}
    };
    auto calculatedCombinations = arrangements_without_repetitions(s, k);
    if(calculatedCombinations != expectedPermutations) {
        std::cout << "[FAIL] ";
    } else {
        std::cout << "[PASS] ";
    }
    const std::string test_name = "Arrangemets without repetitions, char, n=3, k = 3";
    std::cout << test_name << '\n';
}

static void testArrangemetsWithRepetitionInt() {
    std::set<int> s = {1, 2, 3};
    int k = 2;
    std::multiset<std::vector<int>> expectedPermutations = {
            {1, 1},
            {1, 2},
            {1, 3},
            {2, 1},
            {2, 2},
            {2, 3},
            {3, 1},
            {3, 2},
            {3, 3}
    };
    auto calculatedCombinations = arrangements_with_repetitions(s, k);
    if(calculatedCombinations != expectedPermutations) {
        std::cout << "[FAIL] ";
    } else {
        std::cout << "[PASS] ";
    }
    const std::string test_name = "Arrangemets with repetitions, int, n=3, k = 2";
    std::cout << test_name << '\n';
}

static void testDifferenceSets() {
    std::set<int> s1 = {1, 2, 3, 4, 5};
    std::set<int> s2 = {1, 2, 3};
    std::set<int> expectedDifference = {4, 5};
    auto calculatedDifference = difference(s1, s2);
    if(calculatedDifference != expectedDifference) {
        std::cout << "[FAIL] ";
    } else {
        std::cout << "[PASS] ";
    }
    const std::string test_name = "Difference of sets";
    std::cout << test_name << '\n';
}

static void testDifferenceMultisetAndSet(){
    std::multiset<int> s1 = {1, 1, 2, 3, 4, 5};
    std::set<int> s2 = {1, 2, 3};
    std::multiset<int> expectedDifference = {1, 4, 5};
    auto calculatedDifference = difference(s1, s2);
    if(calculatedDifference != expectedDifference) {
        std::cout << "[FAIL] ";
    } else {
        std::cout << "[PASS] ";
    }
    const std::string test_name = "Difference of multiset and set";
    std::cout << test_name << '\n';
}

static void testDifferenceSetSet() {
    std::multiset<int> s1 = {1, 1, 2, 3, 4, 5};
    std::multiset<int> expectedDifference = {1, 4, 5};
    auto calculatedDifference = difference(s1, std::set<int>{1, 2, 3});
    if(calculatedDifference != expectedDifference) {
        std::cout << "[FAIL] ";
    } else {
        std::cout << "[PASS] ";
    }
    const std::string test_name = "Difference of set and ...";
    std::cout << test_name << '\n';
}

static void runTests() {
    testCombinationsWithoutRepetitionInt();
    testCombinationsWithoutRepetitionChar();
    testCombinationsWithRepetitionInt();
    testCombinationsWithRepetitionString();
    testPermutationWithRepetitionInt();
    testPermutationWithRepetitionChar();
    testPermutationWithoutRepetitionInt();
    testPermutationWithoutRepetitionString();
    testArrangemetsWithoutRepetitionInt();
    testArrangemetsWithoutRepetitionChar();
    testArrangemetsWithRepetitionInt();
    testDifferenceSets();
    testDifferenceMultisetAndSet();
    testDifferenceSetSet();
}


#endif //RP_TESTS_H
