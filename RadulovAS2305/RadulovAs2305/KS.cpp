#include <iostream>
#include "KS.h"
#include "Tools.h"
#include "InOut.h"

int KS::maxid = 0;

KS::KS()
{
	name = "None";
	workshops = 0;
	workshops_work = 0;
	efficiency = 0;

}

std::string KS::Getname() const
{
    return name;
}


int KS::GetId()
{
    return id;
}

int KS::Getworkshops() const
{
    return workshops;
}

std::ifstream& operator>>(std::ifstream& fin, KS& g)
{
    fin >> std::ws;
    getline(fin, g.name);
    fin >> g.workshops;
    fin >> g.workshops_work;
    fin >> g.efficiency;

    return fin;
}

std::ofstream& operator<<(std::ofstream& fout, const KS& g)
{
    fout << g.name << std::endl << g.workshops << std::endl << g.workshops_work << std::endl << g.efficiency << std::endl;
    return fout;
}

std::istream& operator>>(std::istream& in, KS& g)
{
    std::cout << "\n";
    std::cout << "������� �������� ��� ��: ";
    in >> std::ws;
    getline(in, g.name);
    g.id = ++ g.maxid;
    std::cout << "������� ���������� �����: ";
    while (!(in >> g.workshops) || g.workshops <= 0) {
        std::cout << "������ �����. ������� ����� ����� ����� �������� �� ����: ";
        fix();
    }
    std::cout << "������� ���������� ����� � ������: ";
    while (!(in >> g.workshops_work) || (g.workshops < g.workshops_work) || g.workshops_work < 0) {
        std::cout << "������ �����. ������� ���������� ����� ����� � ������ (���������� ����� � ������ ������ ���� ������ ���������� �����): ";
        fix();
    }
    std::cout << "������� �������������: ";
    while (!(in >> g.efficiency) || g.efficiency <= 0 || g.efficiency > 100) {
        std::cout << "������ �����. ������� ����� ����� ������������� � ��������� �� 1 �� 100: ";
        fix();
    }
    std::cout << std::endl;
    return in;
}

std::ostream& operator<<(std::ostream& out, const KS& g)
{
    if (g.name == "") {
        std::cout << "��� ������ ��� ������" << "\n";
    }
    else {
        if (g.name != "") {
            out << "\n";
            out << "id: " << g.id << std::endl;
            out << "��������: " << g.name << std::endl;
            out << "���������� �����: " << g.workshops << std::endl;
            out << "���������� ����� � ������: " << g.workshops_work << std::endl;
            out << "�������������: " << g.efficiency << std::endl << std::endl; 
        }
    }
    return out;
}
