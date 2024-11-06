#include "Tools.h"
#include <iostream>
#include "InOut.h"
#include <unordered_set>

void fix() {
    std::cin.clear(); // Сброс состояния потока
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
    std::cout << "Введите ID объектов для изменения состояния (через пробел): ";
    std::getline(std::cin >> std::ws, idInput);

    std::istringstream idStream(idInput);
    int id;
    bool foundAny = false;

    while (idStream >> id) {
        // Проверяем, есть ли этот ID в отфильтрованных
        if (res.find(id) != res.end()) {
            Pipemap.at(id).changeofstate(); // Меняем состояние трубы с данным ID
            foundAny = true;
            std::cout << "Состояние трубы с ID " << id << " изменено." << std::endl;
        }
        else {
            std::cout << "ID " << id << " не найден в отфильтрованных." << std::endl;
        }
    }

    if (!foundAny) {
        std::cout << "Не было найдено ни одного ID для изменения состояния." << std::endl;
    }
}