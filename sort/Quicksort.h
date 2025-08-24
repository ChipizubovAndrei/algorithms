#pragma once

#include <Global.h>

#include <vector>

#include <algorithm>

template <class Iter>
Iter chooseRandomElement(Iter beginIter, Iter endIter)
{
	return beginIter;
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
	bool seenFlag = false;

	Iter referenceIter = chooseRandomElement(beginIter, endIter);
	Iter left = beginIter;
	Iter right = endIter-1;
	while (left != right) {
		if (referenceIter == left) {
			seenFlag = true;
			left++;
			continue;
		}
		else if (*left <= *referenceIter) {
			if (referenceIter < left) {
				std::iter_swap(referenceIter, left);
			}
			else {
				left++;
			}
		}
		else {
			std::iter_swap(left, right);
			right--;
		}
	}
	if (*left < *referenceIter && seenFlag) {
		std::iter_swap(left, referenceIter);
		referenceIter = left;
	}

	quicksort(beginIter, referenceIter);
	quicksort(++referenceIter, endIter);
}

