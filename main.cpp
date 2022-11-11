#include <vector>
#include <set>
#include <algorithm>
#include <iostream>

template<typename T>
std::set<std::multiset<T>> combinations_with_repetitions(std::multiset<T> &s, int k) {
    int n = s.size();
    std::vector<T> indexed_set(n);
    std::copy(s.begin(), s.end(), indexed_set.begin());
    std::vector<int> combination(n, 0);

    for (int i = n - 1; i >= n - k; i--) {
        combination[i] = 1;
    }

    std::set<std::multiset<T>> ans;
    do {
        std::multiset<T> inst;
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
std::set<std::set<T>> combinations_without_repetitions(std::set<T> &s, int k) {
    std::multiset<T> ms(s.begin(), s.end());
    // s has no duplicates -> ms has no duplicates -> if x in combinations_with_repetitions(ms, k), then x has no duplicates
    std::set<std::multiset<T>> ans_multiset = combinations_with_repetitions(ms, k);
    std::set<std::set<T>> ans;
    for(auto x : ans_multiset){
        std::set<T> temp(x.begin(), x.end());
        ans.insert(temp);
    }
    return ans;
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
    std::multiset<T> ms(s.begin(), s.end());
    std::multiset<std::vector<T>> ans_multiset = permutations_with_repetitions(ms);
    std::set<std::vector<T>> ans(ans_multiset.begin(), ans_multiset.end());
    return ans;
}

int main() {
    std::set<char> s = {'a', 'b'};

    return 0;
}
