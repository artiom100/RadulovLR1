#pragma once
#include "Pipe.h"
#include "KS.h"
#include <unordered_map>



std::unordered_map<int, KS> KSCreate(KS& g, std::unordered_map<int, KS>& m);
std::unordered_map <int, Pipe> PipesCreate(Pipe& p, std::unordered_map<int, Pipe>& m);
void PipesPrint(std::unordered_map<int, Pipe>& m);
void KSPrint(std::unordered_map<int, KS>& m);