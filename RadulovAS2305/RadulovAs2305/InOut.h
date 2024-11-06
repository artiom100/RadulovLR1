#pragma once
#include "Pipe.h"
#include "KS.h"
#include <unordered_map>
#include <sstream> 
#include <vector>
#include "Tools.h"



std::unordered_map<int, KS> KSCreate(std::unordered_map<int, KS>& m);
std::unordered_map <int, Pipe> PipesCreate(std::unordered_map<int, Pipe>& m);
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
void DeleteObjectById(std::unordered_map<int, T>& objects, std::unordered_set <int>& res) {
    std::string idInput;
    std::cout << "������� ID �������� ��� �������� (����� ������): ";
    INPUT_LINE(std::cin, idInput);
    // ������� ������ � ID � ������
    std::istringstream idStream(idInput);
    std::unordered_set<int> ids;
    int id;
    while (idStream >> id) {
        ids.emplace(id);
    }

    // �������� �������� �� ������� ID �� ������
    for (int id : ids) {
        auto it = objects.find(id);
        if (res.find(id) == res.end()) {
            std::cout << "������ � ID " << id << " �� ������.\n";
            continue;
        }
        if (it != objects.end()) {
            objects.erase(it);
            std::cout << "������ � ID " << id << " ������� ������.\n";
        }
    }
}



void ChangePipe(std::unordered_map<int, Pipe>& Pipemap, std::unordered_set <int>& res);
void ChangeKS(std::unordered_map<int, KS>& KSmap, std::unordered_set <int>& res);