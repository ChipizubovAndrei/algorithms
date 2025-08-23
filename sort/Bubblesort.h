#include <algorithm>

template <class Iter>
void bubblesort(Iter begin, Iter end)
{
	for (Iter sortedEnd = end; sortedEnd != begin; --sortedEnd) {
		for (Iter curr = begin; curr != sortedEnd-1; ++curr) {
			Iter nextCurr = curr + 1;
			if (*curr > *nextCurr) {
				std::swap(*curr, *nextCurr);
			}
		}
	}
}