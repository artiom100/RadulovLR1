#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <istream>


class Pipe {
private:
    std::string name;
    int length;
    int diameter;
    bool state;
    int id;
    static int maxid;
public:
    Pipe();
    int GetId();
    std::string Getname();
    bool Getstate();

    friend std::ifstream& operator >> (std::ifstream& fin, Pipe& p);
    friend std::ofstream& operator << (std::ofstream& fout, const Pipe& p);

    friend std::istream& operator >> (std::istream& in, Pipe& p);
    friend std::ostream& operator << (std::ostream& out, const Pipe& p);
};
