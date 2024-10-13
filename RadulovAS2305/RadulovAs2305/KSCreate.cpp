#include <iostream>
#include "KS.h"
#include "Tools.h"

KS KSCreate() {

    KS g;
    std::cout << "\n";
    std::cout << "������� �������� ��� ��: ";
    std::cin >> std::ws;
    getline(std::cin, g.name);
    std::cout << "������� ���������� �����: ";
    while (!(std::cin >> g.workshops) || g.workshops <= 0) {
        std::cout << "������ �����. ������� ����� ����� ����� �������� �� ����: ";
        fix();
    }
    std::cout << "������� ���������� ����� � ������: ";
    while (!(std::cin >> g.workshops_work) || (g.workshops < g.workshops_work) || g.workshops_work < 0) {
        std::cout << "������ �����. ������� ���������� ����� ����� � ������ (���������� ����� � ������ ������ ���� ������ ���������� �����): ";
        fix();
    }
    std::cout << "������� �������������: ";
    while (!(std::cin >> g.efficiency) || g.efficiency <= 0 || g.efficiency > 100) {
        std::cout << "������ �����. ������� ����� ����� ������������� � ��������� �� 1 �� 100: ";
        fix();
    }
    return g;
}