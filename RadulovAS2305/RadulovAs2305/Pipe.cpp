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
    fin >> p.id;
    fin >> std::ws;
    getline(fin, p.name);
    fin >> p.length;
    fin >> p.diameter;
    fin >> p.state;
    p.maxid = p.id;
	return fin;
}

std::ofstream& operator<<(std::ofstream& fout, const Pipe& p)
{
    fout << p.id << std::endl << p.name << std::endl << p.length << std::endl << p.diameter << std::endl << p.state << std::endl;
	return fout;
}

std::istream& operator>>(std::istream& in, Pipe& p)
{
    std::cout << "������� �������� ��� �����: ";
    INPUT_LINE(in, p.name);
    p.id = ++p.maxid;
    std::cout << "������� �����: ";
    p.length = GetCorrectNumber(1, 10000);
    std::cout << "������� �������: ";
    p.diameter = GetCorrectNumber(1, 10000);
    std::cout << "������� ���������: ";
    p.state = GetCorrectNumber(0, 1);
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
            out << "���������: " << (p.state ? "��������" : "� �������") << std::endl << std::endl;
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



