#include <iostream>
#include "InOut.h"
#include <string>
#include <fstream>
#include "Tools.h"
#include <unordered_map>
#define INPUT_LINE(input_stream, data);

std::unordered_map<int, Pipe> PipesCreate(Pipe & p, std::unordered_map<int, Pipe> &m) {
    m.emplace(p.GetId(), p);
    return m;
}

std::unordered_map<int, KS> KSCreate(KS &g, std::unordered_map<int, KS>& m) {
    m.emplace(g.GetId(), g);
    return m;
}


void PipesPrint(std::unordered_map<int, Pipe> &m) {
    if (m.empty()) {
        std::cout << '\n';
        std::cout << "Труб нет." << std::endl;
        return;
    }
    for (const auto& Pipe : m) {
        std::cout << Pipe.second;
    }
}

void KSPrint(std::unordered_map<int, KS>& m) {
    if (m.empty()) { 
        std::cout << "КС нет." << std::endl;
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

    std::cout << "Введите имя файла: ";
    std::cin >> std::ws;
    std::getline(std::cin, data);

    fin.open(data);

    if (fin.is_open()) {
        int countpipes;
        fin >> countpipes;
        LoadObject(Pipemap, countpipes, fin);
        int countks;
        fin >> countks;
        LoadObject(KSmap, countks, fin);
        
        std::cout << "Данные успешно загружены" << std::endl;
    }
    else {
        std::cout << "Произошла ошибка. Обратитесь в поддержку или попробуйте снова." << std::endl;
    }
    fin.close();
}