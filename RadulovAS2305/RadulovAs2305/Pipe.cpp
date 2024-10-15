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

bool Pipe::Getstate()
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
    std::cout << "Введите название для трубы: ";
    in >> std::ws;
    getline(in, p.name);
    p.id = ++p.maxid;
    std::cout << "Введите длину: ";
    while (!(in >> p.length) || p.length <= 0) {
        std::cout << "Ошибка ввода. Введите целое число для длины отличное от нуля: ";
        fix();
    }
    std::cout << "Введите диаметр: ";
    while (!(in >> p.diameter) || p.diameter <= 0) {
        std::cout << "Ошибка ввода. Введите целое число для диаметра: ";
        fix();
    }
    std::cout << "Введите состояние: ";
    while (!(in >> p.state)) {
        std::cout << "Ошибка ввода. Введите 1 для исправно или 0 для в работе ";
        fix();
    }
    std::cout << std::endl;
	return in;
}

std::ostream& operator<<(std::ostream& out, const Pipe& p)
{
            out << "\n";
            out << "id: " << p.id << std::endl;
            out << "Название: " << p.name << std::endl;
            out << "Длина: " << p.length << std::endl;
            out << "Диаметр: " << p.diameter << std::endl;
            out << "Состояние: " << (p.state ? "Исправна" : "В ремонте") << std::endl << std::endl; // Выводим данные о трубе, если она существует
	return out;
}

int Pipe::GetId()
{
    return id;
}

std::string Pipe::Getname()
{
    return name;
}

