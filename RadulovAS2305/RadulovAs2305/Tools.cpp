#include "Tools.h"
#include <iostream>
#include "InOut.h"

//std::unordered_map<int, Pipe> Pipemap;

void fix() {
    std::cin.clear(); // Сброс состояния потока
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}


std::unordered_map<int, Pipe> t;
std::unordered_map<int, KS> filterKS;

void search(Pipe& p, std::unordered_map<int, Pipe>& m, std::unordered_map<int, Pipe> &t) {
    if (m.empty()) {
        std::cout << "Труб нет" << std::endl;
        std::cout << std::endl;
    }
    else {
        std::string search;
        std::cin >> search;
        std::cout << std::endl;
        bool found = false;
        for (const auto& Pipe : m) {
            if (p.Getname().find(search) != std::string::npos) {
                t.emplace(p.GetId(), p);
                found = true;
            }
        }
        if (found) {
            PipesPrint(t);  // Печать найденных труб
        }
        else {
            std::cout << "Трубы не найдены" << std::endl;
        }
    }
}


void searchKS(KS& g, std::unordered_map<int, KS>& m, std::unordered_map<int, KS>& filterKS) {
    if (m.empty()) {
        std::cout << "КС нет" << std::endl;
        std::cout << std::endl;
    }
    else {
        std::string search;
        std::cin >> search;
        std::cout << std::endl;
        bool found = false;
        for (const auto& Pipe : m) {
            if (g.Getname().find(search) != std::string::npos) {
                filterKS.emplace(g.GetId(), g);
                found = true;
            }
        }
        if (found) {
            KSPrint(filterKS); 
        }
        else {
            std::cout << "КС не найдены" << std::endl;
        }
    }
}