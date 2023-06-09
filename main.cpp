#include "Tests.h"
#include "Combinatorics.h"
#include "AuthorSolutions.h"

int main() {
    runTests();

    std :: cout << "Uloha 1: " << std :: endl;

    // ULOHA1: Mame 5 guliciek a 3 tanieriky. Kolkymi sposobmi vieme ich poukladat do tychto tanierikov,
    // tak aby v kazdom bola aspon jedna gulicka?

    //RIESENIE 2:
    // skusime vygenerovat vsetky riesenia a odstranime tie, ktore do aspon jedneho tanierika nedaju aspon jednu gulicku
    Solution <std::vector<std::multiset<int>>> sol2;
    std::multiset<int> gulky_a_priehradky = {1, 1, 1, 1, 1, -1, -1}; // 1 reprezentuje gulicku, -1 priehradku

    for(const auto& rozdelenie : permutations_with_repetitions(gulky_a_priehradky)) {
        std::vector<std::multiset<int>> tanieriky2(3, std::multiset<int>());
        // zistime do ktoreho tanierika kolko guliek patri
        int ktory_tanierik = 0;
        for (auto gulka : rozdelenie) {
            if(gulka > -1) {
                tanieriky2[ktory_tanierik].insert(gulka);
            } else {
                ktory_tanierik++;
            }
        }
        // overime, ci vsetky tanieriky obsahuju aspon jednu gulicku
        int ok = true;
        for(const auto& tanierik : tanieriky2) {
            if(tanierik.empty()) {
                ok = false;
            }
        }
        if(ok) {
            sol2.fill(tanieriky2);
            sol2.fill(tanieriky2); // tento riadok je tu len preto, aby sa vysledky RIESENIA 1 a RIESENIA 2 nezhodovali
        }
    }

    // RIESENIE 1: (z AuthorSolutions.h)
    Solution <std::vector<std::multiset<int>>> sol1 = task1();

    // porovname vysledky RIESENIA 1 a RIESENIA 2
    if(sol2 == sol1) {
        std::cout << "OK" << std::endl;
    } else {
        std::cout << "NOK" << std::endl;
        sol2.explain(sol1);
    }
    return 0;
}
