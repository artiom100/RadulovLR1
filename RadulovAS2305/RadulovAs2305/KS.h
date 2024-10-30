#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <istream>

class KS {
private:
    std::string name;
    int workshops;
    int workshops_work;
    int efficiency;
    int id;
    static int maxid;
public:
    KS();
    std::string Getname() const;
    void UpdateWorkshopsInUse(int change) {
        int new_workshops_work = workshops_work + change;
        // ��������, ����� ���������� ������� ����� �� ��������� ����� ���������� ����� � �� ���� �������������
        if (new_workshops_work >= 0 && new_workshops_work <= workshops) {
            workshops_work = new_workshops_work;
        }
        else {
            std::cout << "������: ���������� ������� ����� ������ ���� � �������� �� 0 �� " << workshops << ".\n";
        }
    }
    int GetWorkshopsInUse() const { return workshops_work; }
    int GetId();
    int Getworkshops() const;
    friend std::ifstream& operator >> (std::ifstream& fin, KS& g);
    friend std::ofstream& operator << (std::ofstream& fout, const KS& g);

    friend std::istream& operator >> (std::istream& in, KS& g);
    friend std::ostream& operator << (std::ostream& out, const KS& g);
};
