#pragma once

#include <Global.h>

#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

#include <iostream>

int generateRandomOffset(const int& size) {
	std::mt19937_64 rng(std::chrono::high_resolution_clock::now().time_since_epoch().count());
	std::uniform_int_distribution<int> dist(0, size);
	return dist(rng);
}

template <class Iter>
Iter chooseRandomElement(Iter beginIter, const int & size)
{
	int offset = generateRandomOffset(size - 1);
	return beginIter + offset;
}

template <typename Iter>
void quicksort(Iter begin, Iter end)
{
    std::size_t size = std::distance(begin, end);
    if( size < 1) return;

    auto anchor = *(std::prev(end, 1));       // in original should be random
    Iter i = begin;
    for(Iter j = begin; j != std::prev(end, 1); j = std::next(j, 1)){
        if(*j < anchor){
            std::iter_swap(i, j);
            ++i;
        }
    }
    std::iter_swap(i, std::prev(end, 1));

	quicksort(begin, i);
	quicksort(++i, end);
}
