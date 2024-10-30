#include <iostream>
#include "InOut.h"
#include <string>
#include <fstream>
#include "Tools.h"
#include <unordered_map>


std::unordered_map<int, Pipe> PipesCreate(std::unordered_map<int, Pipe> &m) {
    Pipe p;
    std::cin >> p;
    m.emplace(p.GetId(), p);
    return m;
}

std::unordered_map<int, KS> KSCreate(std::unordered_map<int, KS>& m) {
    KS g;
    std::cin >> g;
    m.emplace(g.GetId(), g);
    return m;
}


void PipesPrint(std::unordered_map<int, Pipe> &m) {
    if (m.empty()) {
        std::cout << '\n';
        std::cout << "���� ���." << std::endl;
        return;
    }
    for (const auto& Pipe : m) {
        std::cout << Pipe.second;
    }
}

void KSPrint(std::unordered_map<int, KS>& m) {
    if (m.empty()) { 
        std::cout << "�� ���." << std::endl;
        std::cout << '\n';
        return;
    }
    for (const auto& KS : m) {
        std::cout << KS.second;
    }
}

void Load(std::unordered_map<int, Pipe>& Pipemap, std::unordered_map<int, KS>& KSmap) {
    std::ifstream fin;
    std::string data;

    std::cout << "������� ��� �����: ";
    INPUT_LINE(std::cin, data);

    fin.open(data);

    if (fin.is_open()) {
        int countpipes;
        fin >> countpipes;
        LoadObject(Pipemap, countpipes, fin);
        int countks;
        fin >> countks;
        LoadObject(KSmap, countks, fin);
        
        std::cout << "������ ������� ���������" << std::endl;
    }
    else {
        std::cout << "��������� ������. ���������� � ��������� ��� ���������� �����." << std::endl;
    }
    fin.close();
}