#include <algorithm>

template <class Iter>
void bubblesort(Iter begin, Iter end)
{
	for (Iter sortedEnd = end; sortedEnd != begin; sortedEnd = std::prev(sortedEnd, 1)) {
        Iter finishSortedIter = std::prev(sortedEnd, 1);
		for (Iter curr = begin; curr != finishSortedIter; curr = std::next(curr, 1)) {
			Iter nextCurr = std::next(curr, 1);
			if (*curr > *nextCurr) {
				std::swap(*curr, *nextCurr);
			}
		}
	}
}