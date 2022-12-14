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
 * Generate all combinations with repetitions of k elements from a given set
 * @tparam T Type of elements in the set
 * @param s Values to choose from
 * @param k An integer number of elements to be included in each combination
 * @return A set of all combinations with repetitions of k elements from a given set
 */
template<typename T>
std::set<std::multiset<T>> combinations_with_repetitions(std::set<T> &s, int k) {
    int n = s.size();
    std::multiset<T> extended_s;
    // Extend the set to have each element k times
    for(auto x : s) {
        for(int i = 0; i < k; i++) {
            extended_s.insert(x);
        }
    }
    std::vector<T> indexed_set(n * k);
    std::copy(extended_s.begin(), extended_s.end(), indexed_set.begin());
    std::vector<int> combination(n * k, 0);
    // Start with lexographically first combination
    for (int i = (n * k) - 1; i >= (n * k) - k; i--) {
        combination[i] = 1;
    }


    std::set<std::multiset<T>> ans;
    // Generate all combinations
    do {
        std::multiset<T> inst;
        for (int i = 0; i < n * k; i++) {
            if (combination[i]) {
                inst.insert(indexed_set[i]);
            }
        }
        ans.insert(inst);
    } while (std::next_permutation(combination.begin(), combination.end()));

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
std::set<std::set<T>> combinations_without_repetitions(std::set<T> &s, int k) {
    int n = s.size();
    std::vector<T> indexed_set(n);
    std::copy(s.begin(), s.end(), indexed_set.begin());
    std::vector<int> combination(n, 0);
    // Start with lexographically first combination
    for (int i = n - 1; i >= n - k; i--) {
        combination[i] = 1;
    }

    std::set<std::set<T>> ans;
    // Generate all combinations
    do {
        std::set<T> inst;
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
std::set<std::vector<T>> permutations_with_repetitions(std::multiset<T> &s) {
    int n = s.size();
    std::vector<T> permutation_with_rep(n);
    std::copy(s.begin(), s.end(), permutation_with_rep.begin());
    sort(permutation_with_rep.begin(), permutation_with_rep.end());
    std::set<std::vector<T>> ans;
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
std::set<std::vector<T>> permutations_without_repetitions(std::set<T> &s) {
    std::multiset<T> ms(s.begin(), s.end());
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
std::multiset<std::vector<T>> arrangements_with_repetitions(std::set<T> &s, int k){
    // Generate all combinations with repetitions of k elements from a given set
    std::set<std::multiset<T>> k_tuples = combinations_with_repetitions(s, k);
    std::multiset<std::vector<T>> arrangements;
    // Generate all permutations with repetitions of each combination
    for(auto k_tuple : k_tuples){
        std::set<std::vector<T>> permutations = permutations_with_repetitions(k_tuple);
        for(auto arr : permutations){
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
std::set<std::vector<T>> arrangements_without_repetitions(std::set<T> &s, int k) {
    // Generate all combinations without repetitions of k elements from a given set
    std::set<std::set<T>> k_tuples = combinations_without_repetitions(s, k);
    std::set<std::vector<T>> arrangements;
    // Generate all permutations without repetitions of each combination
    for(auto k_tuple : k_tuples){
        std::set<std::vector<T>> permutations = permutations_without_repetitions(k_tuple);
        for(auto arr : permutations){
            arrangements.insert(arr);
        }
    }
    return arrangements;
}


#endif //RP_COMBINATORICS_H
