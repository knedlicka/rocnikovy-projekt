#ifndef RP_AUTHORSOLUTIONS_H
#define RP_AUTHORSOLUTIONS_H

#include "Combinatorics.h"

// ULOHA1: Mame 5 guliciek a 3 tanieriky. Kolkymi sposobmi vieme ich poukladat do tychto tanierikov,
// tak aby v kazdom bola aspon jedna gulicka?

Solution<std::vector<std::multiset<int>>> task1() {
    // RIESENIE 1:
    // na zaciatku do kazdeho tanierika dame jednu gulku, zvysne rozdelime do tanierikov
    Solution<std::vector<std::multiset<int>>> sol1;
    std::multiset<int> zvysne_gulky_a_priehradky = {1, 1, -1, -1}; // 1 reprezentuje gulicku, -1 priehradku
    for (const auto& rozdelenie: permutations_with_repetitions(zvysne_gulky_a_priehradky)) {
        std::vector<std::multiset<int>> tanieriky(3, std::multiset<int>({1}));
        // zistime do ktoreho tanierika kolko guliek patri
        int ktory_tanierik = 0;
        for (auto gulka: rozdelenie) {
            if (gulka > -1) {
                tanieriky[ktory_tanierik].insert(gulka);
            } else {
                ktory_tanierik++;
            }
        }
        sol1.fill(tanieriky);
    }
    return sol1;
}

#endif //RP_AUTHORSOLUTIONS_H
