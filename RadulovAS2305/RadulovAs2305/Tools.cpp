#include "Tools.h"
#include <iostream>

void fix() {
    std::cin.clear(); // Сброс состояния потока
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
