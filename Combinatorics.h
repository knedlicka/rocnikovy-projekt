#ifndef RP_COMBINATORICS_H
#define RP_COMBINATORICS_H


class Combinatorics {
    template<typename T>
    std::set<std::multiset<T>> combinations_with_repetitions(std::multiset<T> &s, int k);

    template<typename T>
    std::set<std::set<T>> combinations_without_repetitions(std::set<T> &s, int k);

    template<typename T>
    std::multiset<std::vector<T>> permutations_with_repetitions(std::multiset<T> &s);

    template<typename T>
    std::set<std::vector<T>> permutations_without_repetitions(std::set<T> &s);

    template<typename T>
    std::multiset<std::vector<T>> arrangements_with_repetitions(std::multiset<T> &s, int k);

    template<typename T>
    std::set<std::vector<T>> arrangements_without_repetitions(std::set<T> &s, int k);
};


#endif //RP_COMBINATORICS_H
