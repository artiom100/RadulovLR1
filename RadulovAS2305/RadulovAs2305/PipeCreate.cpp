#include <iostream>
#include "Pipe.h"
#include "Tools.h"

Pipe PipeGen() {

    Pipe p;
    std::cout << "¬ведите название дл€ трубы: ";
    std::cin >> std::ws;
    getline(std::cin, p.name);
    std::cout << "¬ведите длину: ";
    while (!(std::cin >> p.length) || p.length <= 0) {
        std::cout << "ќшибка ввода. ¬ведите целое число дл€ длины отличное от нул€: ";
        fix();
    }
    std::cout << "¬ведите диаметр: ";
    while (!(std::cin >> p.diameter) || p.diameter <= 0) {
        std::cout << "ќшибка ввода. ¬ведите целое число дл€ диаметра: ";
        fix();
    }
    std::cout << "¬ведите состо€ние: ";
    while (!(std::cin >> p.state)) {
        std::cout << "ќшибка ввода. ¬ведите 1 дл€ исправно или 0 дл€ в работе ";
        fix();
    }
    return p;
}