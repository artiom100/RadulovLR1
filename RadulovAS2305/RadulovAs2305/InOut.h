#pragma once
#include "Pipe.h"
#include "KS.h"
#include <unordered_map>
#include <sstream> 
#include <vector>



std::unordered_map<int, KS> KSCreate(KS& g, std::unordered_map<int, KS>& m);
std::unordered_map <int, Pipe> PipesCreate(Pipe& p, std::unordered_map<int, Pipe>& m);
void PipesPrint(std::unordered_map<int, Pipe>& m);
void KSPrint(std::unordered_map<int, KS>& m);

template <typename T>
std::unordered_map<int, T> LoadObject(std::unordered_map<int, T>& Object, int count, std::ifstream& fin) {
	for (int i = 0; i < count; i++) {
		T obj{};
		fin >> obj;
		Object.emplace(obj.GetId(), obj);
	}
	return Object;
}
void Load(std::unordered_map<int, Pipe>& Pipemap, std::unordered_map<int, KS>& KSmap);

template <typename T>
void ModifyObjectById(std::unordered_map<int, T>& objects) {
    std::string idInput;
    std::cout << "Введите ID объектов для изменения (через пробел): ";
    std::getline(std::cin >> std::ws, idInput);

    std::istringstream idStream(idInput);
    std::vector<int> ids;
    int id;
    while (idStream >> id) {
        ids.push_back(id);
    }
    auto modifyObject = [](T& obj) {
        if constexpr (std::is_same_v<T, Pipe>) {
            bool newState;
            std::cout << "Введите новое состояние для трубы (0 - неактивен, 1 - активен): ";
            std::cin >> newState;
            obj.SetState(newState);
            std::cout << "Состояние трубы обновлено.\n";
        }
        else if constexpr (std::is_same_v<T, KS>) {
            int change;
            std::cout << "Текущее количество рабочих цехов: " << obj.GetWorkshopsInUse() << "\n";
            std::cout << "Введите изменение в количестве рабочих цехов (положительное - прибавить, отрицательное - вычесть): ";
            std::cin >> change;
            obj.UpdateWorkshopsInUse(change);
            std::cout << "Количество рабочих цехов обновлено.\n";
        }
        };

    // Обработка каждого ID из списка
    for (int id : ids) {
        auto it = objects.find(id);
        if (it != objects.end()) {
            modifyObject(it->second);
        }
        else {
            std::cout << "Объект с ID " << id << " не найден.\n";
        }
    }
}


template <typename T>
void DeleteObjectById(std::unordered_map<int, T>& objects) {
    std::string idInput;
    std::cout << "Введите ID объектов для удаления (через пробел): ";
    std::getline(std::cin >> std::ws, idInput);

    // Парсинг строки с ID в вектор
    std::istringstream idStream(idInput);
    std::vector<int> ids;
    int id;
    while (idStream >> id) {
        ids.push_back(id);
    }

    // Удаление объектов по каждому ID из списка
    for (int id : ids) {
        auto it = objects.find(id);
        if (it != objects.end()) {
            objects.erase(it);
            std::cout << "Объект с ID " << id << " успешно удален.\n";
        }
        else {
            std::cout << "Объект с ID " << id << " не найден.\n";
        }
    }
}