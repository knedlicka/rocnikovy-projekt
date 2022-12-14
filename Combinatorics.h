#ifndef RP_COMBINATORICS_H
#define RP_COMBINATORICS_H

#include <vector>
#include <set>
#include <algorithm>
#include <iostream>

template<typename T>
static std::set<std::multiset<T>> combinations_with_repetitions(std::set<T> &s, int k) {
    int n = s.size();
    std::multiset<T> extended_s;
    for(auto x : s) {
        for(int i = 0; i < k; i++) {
            extended_s.insert(x);
        }
    }
    std::vector<T> indexed_set(n * k);
    std::copy(extended_s.begin(), extended_s.end(), indexed_set.begin());
    std::vector<int> combination(n * k, 0);

    for (int i = (n * k) - 1; i >= (n * k) - k; i--) {
        combination[i] = 1;
    }


    std::set<std::multiset<T>> ans;
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

template<typename T>
static std::set<std::set<T>> combinations_without_repetitions(std::set<T> &s, int k) {
    int n = s.size();
    std::vector<T> indexed_set(n);
    std::copy(s.begin(), s.end(), indexed_set.begin());
    std::vector<int> combination(n, 0);

    for (int i = n - 1; i >= n - k; i--) {
        combination[i] = 1;
    }

    std::set<std::set<T>> ans;
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

template<typename T>
static std::set<std::vector<T>> permutations_with_repetitions(std::multiset<T> &s) {
    int n = s.size();
    std::vector<T> permutation_with_rep(n);
    std::copy(s.begin(), s.end(), permutation_with_rep.begin());
    sort(permutation_with_rep.begin(), permutation_with_rep.end());
    std::set<std::vector<T>> ans;
    do {
        ans.insert(permutation_with_rep);
    } while (std::next_permutation(permutation_with_rep.begin(), permutation_with_rep.end()));
    return ans;
}

template<typename T>
static std::set<std::vector<T>> permutations_without_repetitions(std::set<T> &s) {
    std::multiset<T> ms(s.begin(), s.end());
    return permutations_with_repetitions(ms);
}

template<typename T>
static std::multiset<std::vector<T>> arrangements_with_repetitions(std::set<T> &s, int k){
    std::set<std::multiset<T>> k_tuples = combinations_with_repetitions(s, k);
    std::multiset<std::vector<T>> arrangements;
    for(auto k_tuple : k_tuples){
        std::set<std::vector<T>> permutations = permutations_with_repetitions(k_tuple);
        for(auto arr : permutations){
            arrangements.insert(arr);
        }
    }
    return arrangements;
}

template<typename T>
static std::set<std::vector<T>> arrangements_without_repetitions(std::set<T> &s, int k) {
    std::set<std::set<T>> k_tuples = combinations_without_repetitions(s, k);
    std::set<std::vector<T>> arrangements;
    for(auto k_tuple : k_tuples){
        std::set<std::vector<T>> permutations = permutations_without_repetitions(k_tuple);
        for(auto arr : permutations){
            arrangements.insert(arr);
        }
    }
    return arrangements;
}


#endif //RP_COMBINATORICS_H
