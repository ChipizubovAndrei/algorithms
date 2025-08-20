#pragma once

#include <Global.h>

#include <vector>

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
	std::size_t size = getContainerSize(beginIter, endIter);

	Iter referenceIter = chooseRandomElement(beginIter, endIter);
	Iter left = beginIter;
	Iter rigth = endIter--;
	Iter rightBegin, rightEnd, leftBegin, leftEnd;
	for (Iter temp = beginIter; temp != endIter; temp++) {
		if (referenceIter == beginIter) continue;
		else if(*temp <= *referenceIter) 
	}

	//quicksort();
	//quicksort();
}

