#pragma once

#include <Global.h>

#include <vector>

template <class Iter>
SORTLIB_EXPORT void quicksort(Iter beginIter, Iter endIter);


SORTLIB_EXPORT void quicksort(std::vector<int>::iterator beginIter, std::vector<int>::iterator endIter);
