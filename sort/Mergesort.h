#pragma once

#include <algorithm>

template <typename Iter>
void merge(Iter lBegin, Iter lEnd, Iter rBegin, Iter rEnd) {
	Iter i = lBegin;
	for (Iter j = rBegin; j != rEnd;/* j = std::next(j, 1)*/) {
		if (*i < *j) {
			i = std::next(i, 1);
			j = rBegin;
			continue;
		}
		else {
			//auto anchor = *j;
			/*Перемещаем значение j вверх, так как оно меньше чем i*/
			for (Iter curr = j; curr != i; curr = std::prev(curr, 1)) {
				Iter prev = std::prev(curr, 1);
				std::iter_swap(prev, curr);
			}
			i = std::next(i, 1);
		}
		j = std::next(j, 1);
	}
}

template <typename Iter>
void mergesort(Iter begin, Iter end)
{
	std::size_t size = std::distance(begin, end);
	if (size <= 1) return;

	std::size_t offset = size / 2;

	Iter lBegin = begin;
	Iter lEnd = std::next(begin, offset);
	Iter rBegin = std::next(begin, offset);
	Iter rEnd = end;

	mergesort(lBegin, lEnd);
	mergesort(rBegin, rEnd);

	merge(lBegin, lEnd, rBegin, rEnd);
}