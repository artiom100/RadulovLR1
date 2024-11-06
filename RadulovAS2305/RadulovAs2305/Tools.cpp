#include "Tools.h"
#include <iostream>
#include "InOut.h"
#include <unordered_set>

void fix() {
    std::cin.clear(); // ����� ��������� ������
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}



bool checknamepipe(const Pipe& p, const std::string param)
{
	return p.Getname().find(param) != std::string::npos;
}
bool checkstate(const Pipe& p, bool param)
{
	return p.Getstate() == param;
}

bool checknameks(const KS& g, std::string param)
{
	return g.Getname().find(param) != std::string::npos;
}
bool workshops(const KS& g, int param)
{
	return g.Getworkshops() >= param;
}

void edit(std::unordered_map<int, Pipe>& Pipemap, std::unordered_set <int> res) {


    std::string idInput;
    std::cout << "������� ID �������� ��� ��������� ��������� (����� ������): ";
    std::getline(std::cin >> std::ws, idInput);

    std::istringstream idStream(idInput);
    int id;
    bool foundAny = false;

    while (idStream >> id) {
        // ���������, ���� �� ���� ID � ���������������
        if (res.find(id) != res.end()) {
            Pipemap.at(id).changeofstate(); // ������ ��������� ����� � ������ ID
            foundAny = true;
            std::cout << "��������� ����� � ID " << id << " ��������." << std::endl;
        }
        else {
            std::cout << "ID " << id << " �� ������ � ���������������." << std::endl;
        }
    }

    if (!foundAny) {
        std::cout << "�� ���� ������� �� ������ ID ��� ��������� ���������." << std::endl;
    }
}