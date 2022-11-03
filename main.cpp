#include <vector>
#include <set>
#include <algorithm>
#include <iostream>

template <typename T>

std::set<std::set<T>> combinations(std::set<T> s, int sz) {
    int n = s.size();
    std::vector<T> indexed_set(n);
    std::copy(s.begin(), s.end(), indexed_set.begin());
    std::vector<int> combination(n, 0);

    for (int i = n - 1; i >= n - sz; i--) {
        combination[i] = 1;
    }

    std::set<std::set<int>> ans;
    do {
        std::set<int> inst;
        for (int i = 0; i < n; i++) {
            if (combination[i]) {
                inst.insert(indexed_set[i]);
            }
        }
        ans.insert(inst);
    } while (std::next_permutation(combination.begin(), combination.end()));

    return ans;
}

template <typename T>

void print_combinations(std::set<T> s, int sz){
    std::set<std::set<T>> combs = combinations(s, sz);
    for (auto x: combs) {
        std::cout << "{ ";
        for (auto y: x) {
            std::cout << y << " ";
        }
        std::cout << "}\n";
    }
}


template<typename T>
std::multiset<std::vector<T>> permutations_with_repetitions(std::multiset<T> &s) {
    int n = s.size();
    std::vector<T> permutation_with_rep(n);
    std::copy(s.begin(), s.end(), permutation_with_rep.begin());
    sort(permutation_with_rep.begin(), permutation_with_rep.end());
    std::vector<std::pair<T, int>> permutation(n);
    for (int i = 0; i < n; i++) {
        permutation[i] = {permutation_with_rep[i], i};
    }
    std::set<std::vector<T>> ans;
    std::vector<T> inst(n);
    do {
        for (int i = 0; i < n; i++) {
            inst[i] = permutation[i].first;
        }
        ans.insert(inst);
    } while (std::next_permutation(permutation.begin(), permutation.end()));
    return ans;
}

template<typename T>
std::set<std::vector<T>> permutations_without_repetitions(std::set<T> &s) {
    return permutations_with_repetitions(s);
}


int main() {
    std::set<char> s = {'a', 'b'};
    print_combinations<char>(s, 1);

    return 0;
}
