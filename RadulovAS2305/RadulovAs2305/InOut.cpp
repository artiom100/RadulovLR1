#include <iostream>
#include "Pipe.h"
#include "KS.h"
#include <string>
#include <fstream>

void PipePrint(const Pipe& p) {
    std::cout << "\n";
    std::cout << "Название: " << p.name << std::endl;
    std::cout << "Длина: " << p.length << std::endl;
    std::cout << "Диаметр: " << p.diameter << std::endl;
    std::cout << "Состояние: " << (p.state ? "Исправна" : "В ремонте") << std::endl << std::endl;
}
void KSPrint(const KS& g) {
    std::cout << "\n";
    std::cout << "Название: " << g.name << std::endl;
    std::cout << "Количество цехов: " << g.workshops << std::endl;
    std::cout << "Количество цехов в работе: " << g.workshops_work << std::endl;
    std::cout << "Эффективность: " << g.efficiency << std::endl;
}

void SavePipe(std::ofstream& fout, const Pipe& p)
{
    fout << p.name << std::endl << p.length << std::endl << p.diameter << std::endl << p.state << std::endl;
}

void SaveKS(std::ofstream& fout, const KS& g)
{
    fout << g.name << std::endl << g.workshops << std::endl << g.workshops_work << std::endl << g.efficiency << std::endl;
}

Pipe LoadPipe(std::ifstream& fin)
{
    Pipe p;
    fin >> std::ws;
    getline(fin, p.name);
    fin >> p.length;
    fin >> p.diameter;
    fin >> p.state;

    return p;
}

KS LoadKS(std::ifstream& fin) {
    KS g;
    fin >> std::ws;
    getline(fin, g.name);
    fin >> g.workshops;
    fin >> g.workshops_work;
    fin >> g.efficiency;

    return g;
}