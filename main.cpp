#include <vector>
#include <set>
#include <algorithm>
#include <iostream>

std::set<std::set<int>> combinations(std::set<int> s, int sz) {
    int n = s.size();
    std::vector<int> indexed_set(n);
    std::copy(s.begin(), s.end(), indexed_set.begin());
    std::vector<int> combs(n, 0);

    for (int i = n - 1; i >= n - sz; i--) {
        combs[i] = 1;
    }

    std::set<std::set<int>> ans;
    do {
        std::set<int> inst;
        for (int i = 0; i < n; i++) {
            if (combs[i]) {
                inst.insert(indexed_set[i]);
            }
        }
        ans.insert(inst);
    } while (std::next_permutation(combs.begin(), combs.end()));

    return ans;
}

void print_combinations(std::set<int> s, int sz){
    std::set<std::set<int>> combs = combinations(s, sz);
    for (auto x: combs) {
        std::cout << "{ ";
        for (auto y: x) {
            std::cout << y << " ";
        }
        std::cout << "}\n";
    }
}

int main() {

    print_combinations({1, 2}, 1);

    return 0;
}
