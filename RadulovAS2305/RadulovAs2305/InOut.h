#pragma once
#include "Pipe.h"
#include "KS.h"
#include <unordered_map>

//Pipe PipeGen();
std::unordered_map<int, KS> KSCreate(KS& g, std::unordered_map<int, KS>& m);
std::unordered_map <int, Pipe> PipesCreate(Pipe& p, std::unordered_map<int, Pipe>& m);
//void PipePrint(const Pipe& p);
//void KSPrint(const KS& g);
//void SavePipe(std::ofstream& fout, const Pipe& p);
//void SaveKS(std::ofstream& fout, const KS& g);
//Pipe LoadPipe(std::ifstream& fin);
//KS LoadKS(std::ifstream& fin);
void PipesPrint(std::unordered_map<int, Pipe>& m);
void KSPrint(std::unordered_map<int, KS>& m);