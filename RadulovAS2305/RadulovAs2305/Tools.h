#pragma once
#include <iostream>
#include "Pipe.h"
#include "KS.h"
#include <unordered_map>
#include <unordered_set>
void fix();


bool checknamepipe(const Pipe& p, std::string param);
bool checkstate(const Pipe& p, bool param);

bool checknameks(const KS& g, std::string param);
bool workshops(const KS& g, int param);



template<typename T>
using filterpipe = bool(*)(const Pipe& p, T param);

template<typename T>
std::unordered_set<int> FindPipeFilter(const std::unordered_map<int, Pipe>& Pipemap, filterpipe<T> f, T param)
{
	std::unordered_set <int> res;
	int i = 0;
	for (auto& p : Pipemap)
	{
		if (f(p.second, param))
			res.emplace(p.first);
		i++;
	}

	return res;
}



template<typename T>
using filterks = bool(*)(const KS& g, T param);

template<typename T>
std::unordered_set<int> FindKSFilter(const std::unordered_map<int, KS>& KSmap, filterks<T> f, T param)
{
	std::unordered_set <int> res;
	int i = 0;
	for (auto& g : KSmap)
	{
		if (f(g.second, param))
			res.emplace(g.first);
		i++;
	}

	return res;
}








