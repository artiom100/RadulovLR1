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
    std::cout << "������� ID �������� ��� ��������� (����� ������): ";
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
            std::cout << "������� ����� ��������� ��� ����� (0 - ���������, 1 - �������): ";
            std::cin >> newState;
            obj.SetState(newState);
            std::cout << "��������� ����� ���������.\n";
        }
        else if constexpr (std::is_same_v<T, KS>) {
            int change;
            std::cout << "������� ���������� ������� �����: " << obj.GetWorkshopsInUse() << "\n";
            std::cout << "������� ��������� � ���������� ������� ����� (������������� - ���������, ������������� - �������): ";
            std::cin >> change;
            obj.UpdateWorkshopsInUse(change);
            std::cout << "���������� ������� ����� ���������.\n";
        }
        };

    // ��������� ������� ID �� ������
    for (int id : ids) {
        auto it = objects.find(id);
        if (it != objects.end()) {
            modifyObject(it->second);
        }
        else {
            std::cout << "������ � ID " << id << " �� ������.\n";
        }
    }
}


template <typename T>
void DeleteObjectById(std::unordered_map<int, T>& objects) {
    std::string idInput;
    std::cout << "������� ID �������� ��� �������� (����� ������): ";
    std::getline(std::cin >> std::ws, idInput);

    // ������� ������ � ID � ������
    std::istringstream idStream(idInput);
    std::vector<int> ids;
    int id;
    while (idStream >> id) {
        ids.push_back(id);
    }

    // �������� �������� �� ������� ID �� ������
    for (int id : ids) {
        auto it = objects.find(id);
        if (it != objects.end()) {
            objects.erase(it);
            std::cout << "������ � ID " << id << " ������� ������.\n";
        }
        else {
            std::cout << "������ � ID " << id << " �� ������.\n";
        }
    }
}