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

int main() {

    print_combinations<int>({1, 2}, 1);

    return 0;
}
