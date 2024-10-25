#include <iostream>
#include "Pipe.h"
#include "Tools.h"
#include "InOut.h"


int Pipe::maxid = 0;


Pipe::Pipe()
{
	name = "None";
	length = 0;
	diameter = 0;
	state = 0;
}

bool Pipe::Getstate() const
{
    return state;
}


std::ifstream& operator>>(std::ifstream& fin, Pipe& p)
{
    fin >> std::ws;
    getline(fin, p.name);
    fin >> p.id;
    p.maxid = p.id;
    fin >> p.length;
    fin >> p.diameter;
    fin >> p.state;
	return fin;
}

std::ofstream& operator<<(std::ofstream& fout, const Pipe& p)
{
    fout << p.name << std::endl << p.length << std::endl << p.diameter << std::endl << p.state << std::endl;
	return fout;
}

std::istream& operator>>(std::istream& in, Pipe& p)
{
    std::cout << "������� �������� ��� �����: ";
    in >> std::ws;
    getline(in, p.name);
    p.id = ++p.maxid;
    std::cout << "������� �����: ";
    while (!(in >> p.length) || p.length <= 0) {
        std::cout << "������ �����. ������� ����� ����� ��� ����� �������� �� ����: ";
        fix();
    }
    std::cout << "������� �������: ";
    while (!(in >> p.diameter) || p.diameter <= 0) {
        std::cout << "������ �����. ������� ����� ����� ��� ��������: ";
        fix();
    }
    std::cout << "������� ���������: ";
    while (!(in >> p.state)) {
        std::cout << "������ �����. ������� 1 ��� �������� ��� 0 ��� � ������ ";
        fix();
    }
    std::cout << std::endl;
	return in;
}

std::ostream& operator<<(std::ostream& out, const Pipe& p)
{
            out << "\n";
            out << "id: " << p.id << std::endl;
            out << "��������: " << p.name << std::endl;
            out << "�����: " << p.length << std::endl;
            out << "�������: " << p.diameter << std::endl;
            out << "���������: " << (p.state ? "��������" : "� �������") << std::endl << std::endl; // ������� ������ � �����, ���� ��� ����������
	return out;
}

int Pipe::GetId()
{
    return id;
}

std::string Pipe::Getname() const
{
    return name;
}



