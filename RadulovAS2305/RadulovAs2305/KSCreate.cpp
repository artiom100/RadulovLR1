#include <iostream>
#include "KS.h"
#include "Tools.h"

KS KSCreate() {

    KS g;
    std::cout << "\n";
    std::cout << "¬ведите название дл€  —: ";
    std::cin >> std::ws;
    getline(std::cin, g.name);
    std::cout << "¬ведите количество цехов: ";
    while (!(std::cin >> g.workshops) || g.workshops <= 0) {
        std::cout << "ќшибка ввода. ¬ведите целое число цехов отличное от нул€: ";
        fix();
    }
    std::cout << "¬ведите количество цехов в работе: ";
    while (!(std::cin >> g.workshops_work) || (g.workshops < g.workshops_work) || g.workshops_work < 0) {
        std::cout << "ќшибка ввода. ¬ведите корректное число цехов в работе (количество цехов в работе должно быть меньше количества цехов): ";
        fix();
    }
    std::cout << "¬ведите Ёффективность: ";
    while (!(std::cin >> g.efficiency) || g.efficiency <= 0 || g.efficiency > 100) {
        std::cout << "ќшибка ввода. ¬ведите целое число эффективности в диапозоне от 1 до 100: ";
        fix();
    }
    return g;
}