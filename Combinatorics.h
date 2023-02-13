/**
@file
@author Nadiya Balanchuk
*/

#ifndef RP_COMBINATORICS_H
#define RP_COMBINATORICS_H

#include <vector>
#include <set>
#include <algorithm>
#include <iostream>

/**
 * Helper function for combinations_with_repetitions
 * @tparam T Type of elements from which combinations are formed
 * @param it Iterator to the first element of the set to be used for combinations
 * @param end_it Iterator to the end of the set to be used for combinations
 * @param k An integer, the size of the combinations
 * @param combinations The set in which the combinations will be stored
 * @param combination Accumulator for the current combination
 */

template<typename T>
void
generate_combinations_with_repetitions_(typename std::set<T>::iterator it, typename std::set<T>::iterator end_it, int k,
                                        std::set <std::multiset<T>> &combinations, std::multiset <T> &combination) {
    if (it == end_it) {
        return;
    }
    if (combination.size() == k) {
        combinations.insert(combination);
    } else {
        auto next_it = it;
        next_it++;
        generate_combinations_with_repetitions_(next_it, end_it, k, combinations, combination);
        combination.insert(*it);
        generate_combinations_with_repetitions_(it, end_it, k, combinations, combination);
        combination.erase(combination.find(*it));
    }
}

/**
 * Generate all combinations with repetitions of k elements from a given set
 * @tparam T Type of elements in the set
 * @param s Values to choose from
 * @param k An integer number of elements to be included in each combination
 * @return A set of all combinations with repetitions of k elements from a given set
 */
template<typename T>
std::set <std::multiset<T>> combinations_with_repetitions(std::set <T> &s, int k) {
    std::set <std::multiset<T>> ans;
    std::multiset <T> combination;
    generate_combinations_with_repetitions_(s.begin(), s.end(), k, ans, combination);
    return ans;
}


/**
 * Generate all combinations without repetitions of k elements from a given set
 * @tparam T Type of elements in the set
 * @param s Values to choose from
 * @param k An integer number of elements to be included in each combination
 * @return A set of all combinations without repetitions of k elements from a given set
 */
template<typename T>
std::set <std::set<T>> combinations_without_repetitions(std::set <T> &s, int k) {
    int n = s.size();
    std::vector <T> indexed_set(n);
    std::copy(s.begin(), s.end(), indexed_set.begin());
    std::vector<int> combination(n, 0);
    // Start with lexographically first combination
    for (int i = n - 1; i >= n - k; i--) {
        combination[i] = 1;
    }

    std::set <std::set<T>> ans;
    // Generate all combinations
    do {
        std::set <T> inst;
        for (int i = 0; i < n; i++) {
            if (combination[i]) {
                inst.insert(indexed_set[i]);
            }
        }
        ans.insert(inst);
    } while (std::next_permutation(combination.begin(), combination.end()));

    return ans;
}

/**
 * Generate all permutations with repetitions of a given set
 * @tparam T Type of elements in the set
 * @param s Values to choose from
 * @return A set of all permutations with repetitions of a given multiset
 */
template<typename T>
std::set <std::vector<T>> permutations_with_repetitions(std::multiset <T> &s) {
    int n = s.size();
    std::vector <T> permutation_with_rep(n);
    std::copy(s.begin(), s.end(), permutation_with_rep.begin());
    sort(permutation_with_rep.begin(), permutation_with_rep.end());
    std::set <std::vector<T>> ans;
    // Generate all permutations
    do {
        ans.insert(permutation_with_rep);
    } while (std::next_permutation(permutation_with_rep.begin(), permutation_with_rep.end()));
    return ans;
}

/**
 * Generate all permutations without repetitions of a given set
 * @tparam T Type of elements in the set
 * @param s Values to choose from
 * @return A set of all permutations without repetitions of a given set
 */
template<typename T>
std::set <std::vector<T>> permutations_without_repetitions(std::set <T> &s) {
    std::multiset <T> ms(s.begin(), s.end());
    // Generate all permutations without repetitions. We can use permutations with repetitions
    // because we have a set
    return permutations_with_repetitions(ms);
}

/**
 * Generate all arrangements with repetitions of k elements from a given set
 * @tparam T Type of elements in the set
 * @param s Values to choose from
 * @param k Integer number of elements to be included in each arrangement
 * @return A multiset of all arrangements with repetitions of k elements from a given set
 */
template<typename T>
std::multiset <std::vector<T>> arrangements_with_repetitions(std::set <T> &s, int k) {
    // Generate all combinations with repetitions of k elements from a given set
    std::set <std::multiset<T>> k_tuples = combinations_with_repetitions(s, k);
    std::multiset <std::vector<T>> arrangements;
    // Generate all permutations with repetitions of each combination
    for (auto k_tuple: k_tuples) {
        std::set <std::vector<T>> permutations = permutations_with_repetitions(k_tuple);
        for (auto arr: permutations) {
            arrangements.insert(arr);
        }
    }
    return arrangements;
}

/**
 * Generate all arrangements without repetitions of k elements from a given set
 * @tparam T Type of elements in the set
 * @param s Values to choose from
 * @param k Integer number of elements to be included in each arrangement
 * @return A multiset of all arrangements without repetitions of k elements from a given set
 */
template<typename T>
std::set <std::vector<T>> arrangements_without_repetitions(std::set <T> &s, int k) {
    // Generate all combinations without repetitions of k elements from a given set
    std::set <std::set<T>> k_tuples = combinations_without_repetitions(s, k);
    std::set <std::vector<T>> arrangements;
    // Generate all permutations without repetitions of each combination
    for (auto k_tuple: k_tuples) {
        std::set <std::vector<T>> permutations = permutations_without_repetitions(k_tuple);
        for (auto arr: permutations) {
            arrangements.insert(arr);
        }
    }
    return arrangements;
}

/**
 * Generate difference of two objects
 * @tparam T Type of the first object
 * @tparam U Type of the second object
 * @param s1 The first object
 * @param s2 The Second object
 * @return Difference of s1 and s2
 */
template<typename T, typename U>
T difference(T &s1, U &s2) {
    T diff;
    for (auto x: s1) {
        if (s2.find(x) == s2.end()) {
            diff.insert(x);
        } else {
            s2.erase(s2.find(x));
        }
    }
    return diff;
}

template<typename T, typename U, typename V>
class Solution {
    U s;

    void print_why(U found, U expected) {
        U diff = difference(found, expected);
        T diff2 = difference(expected, found);
        if (diff.size() > 0) {
            std::cout << "Found: " << std::endl;
            for (auto x: found) {
                std::cout << x << " ";
            }
            std::cout << std::endl;
            std::cout << "Expected: " << std::endl;
            for (auto x: expected) {
                std::cout << x << " ";
            }
            std::cout << std::endl;
            std::cout << "Difference of found and expected: " << std::endl;
            for (auto x: diff) {
                std::cout << x << " ";
            }
            std::cout << std::endl;
            std::cout << "Difference of expected and found: " << std::endl;
            for (auto x: diff2) {
                std::cout << x << " ";
            }
            std::cout << std::endl;
        }
    }

public:
    Solution(U solution) {
        s = solution;
    }

    bool operator==(const Solution<T, U, V> &other) const {
        if (this->s == other.s) {
            return true;
        }
        print_why(this->s, other.s);
        return false;
    }

    void fill(V sol) {
        s.insert(sol);
    }
};

#endif //RP_COMBINATORICS_H
