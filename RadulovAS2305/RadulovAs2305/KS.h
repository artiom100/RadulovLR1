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
    std::string Getname();
    int GetId();

    friend std::ifstream& operator >> (std::ifstream& fin, KS& g);
    friend std::ofstream& operator << (std::ofstream& fout, const KS& g);

    friend std::istream& operator >> (std::istream& in, KS& g);
    friend std::ostream& operator << (std::ostream& out, const KS& g);
};
