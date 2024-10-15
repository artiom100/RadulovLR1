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

std::string KS::Getname()
{
    return name;
}

int KS::GetId()
{
    return id;
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
    std::cout << "Введите название для КС: ";
    in >> std::ws;
    getline(in, g.name);
    g.id = ++ g.maxid;
    std::cout << "Введите количество цехов: ";
    while (!(in >> g.workshops) || g.workshops <= 0) {
        std::cout << "Ошибка ввода. Введите целое число цехов отличное от нуля: ";
        fix();
    }
    std::cout << "Введите количество цехов в работе: ";
    while (!(in >> g.workshops_work) || (g.workshops < g.workshops_work) || g.workshops_work < 0) {
        std::cout << "Ошибка ввода. Введите корректное число цехов в работе (количество цехов в работе должно быть меньше количества цехов): ";
        fix();
    }
    std::cout << "Введите Эффективность: ";
    while (!(in >> g.efficiency) || g.efficiency <= 0 || g.efficiency > 100) {
        std::cout << "Ошибка ввода. Введите целое число эффективности в диапозоне от 1 до 100: ";
        fix();
    }
    std::cout << std::endl;
    return in;
}

std::ostream& operator<<(std::ostream& out, const KS& g)
{
    if (g.name == "") {
        std::cout << "Нет данных для вывода" << "\n";
    }
    else {
        if (g.name != "") {
            out << "\n";
            out << "id: " << g.id << std::endl;
            out << "Название: " << g.name << std::endl;
            out << "Количество цехов: " << g.workshops << std::endl;
            out << "Количество цехов в работе: " << g.workshops_work << std::endl;
            out << "Эффективность: " << g.efficiency << std::endl << std::endl; 
        }
    }
    return out;
}
