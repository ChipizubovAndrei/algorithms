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

template <class Iter>
std::size_t getContainerSize(Iter beginIter, Iter endIter) {
	return endIter - beginIter;
}

template <class Iter>
SORTLIB_EXPORT void quicksort(Iter beginIter, Iter endIter)
{
	if (beginIter == endIter || endIter - beginIter == 1) return;
	std::size_t size = getContainerSize(beginIter, endIter);

	Iter anchorIter = chooseRandomElement(beginIter, size);

	Iter left = beginIter;
	Iter right = endIter-1;
	while (left <= right) {
		if (anchorIter == left) {
			left++;
			continue;
		}
		else if (*left <= *anchorIter) {
			if (anchorIter < left) {
				std::iter_swap(anchorIter, left);
				anchorIter = left;
			}
			else {
				left++;
			}
		}
		else {
			std::iter_swap(left, right);
			if (right == anchorIter) anchorIter = left;
			right--;
		}
	}

	quicksort(beginIter, anchorIter);
	quicksort(++anchorIter, endIter);
}


template <typename Iter>
void quicksort_mod(Iter begin, Iter end)
{
    auto size = getContainerSize(begin, end);
    if(size == 0 || size == 1) return;

    auto offset = generateRandomOffset(begin, size - 1);
    Iter anchor = begin + offset;

    Iter right = begin - 1;
    std::iter_swap(anchor, right);
    anchor = right;

    Iter left = begin;          // point to value, smaller than anchor
    

    std::iter_swap(left, anchor);
}
