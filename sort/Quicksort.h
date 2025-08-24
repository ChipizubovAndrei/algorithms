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

	Iter referenceIter = chooseRandomElement(beginIter, size);
	std::cout << "reference = " << *referenceIter << std::endl;
	Iter left = beginIter;
	Iter right = endIter-1;
	while (left <= right) {
		if (referenceIter == left) {
			left++;
			continue;
		}
		else if (*left <= *referenceIter) {
			if (referenceIter < left) {
				std::iter_swap(referenceIter, left);
				referenceIter = left;
			}
			else {
				left++;
			}
		}
		else {
			std::iter_swap(left, right);
			if (right == referenceIter) referenceIter = left;
			right--;
		}
	}
	std::cout << "reference after = " << *referenceIter << std::endl;
	for (Iter temp = beginIter; temp != endIter; temp++) {
		std::cout << *temp << " ";
	}
	std::cout << "\n";

	quicksort(beginIter, referenceIter);
	quicksort(++referenceIter, endIter);
}

