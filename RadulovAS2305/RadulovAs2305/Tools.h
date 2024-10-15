#pragma once
#include "Tools.h"
#include <iostream>
#include "InOut.h"
void fix();
void search(Pipe& p, std::unordered_map<int, Pipe>& m, std::unordered_map<int, Pipe>& t);
void searchKS(KS& g, std::unordered_map<int, KS>& m, std::unordered_map<int, KS>& filterKS);