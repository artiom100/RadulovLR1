#include <iostream>
#include "Pipe.h"
#include "Tools.h"

Pipe PipeGen() {

    Pipe p;
    std::cout << "������� �������� ��� �����: ";
    std::cin >> std::ws;
    getline(std::cin, p.name);
    std::cout << "������� �����: ";
    while (!(std::cin >> p.length) || p.length <= 0) {
        std::cout << "������ �����. ������� ����� ����� ��� ����� �������� �� ����: ";
        fix();
    }
    std::cout << "������� �������: ";
    while (!(std::cin >> p.diameter) || p.diameter <= 0) {
        std::cout << "������ �����. ������� ����� ����� ��� ��������: ";
        fix();
    }
    std::cout << "������� ���������: ";
    while (!(std::cin >> p.state)) {
        std::cout << "������ �����. ������� 1 ��� �������� ��� 0 ��� � ������ ";
        fix();
    }
    return p;
}