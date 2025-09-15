#pragma once

#include <algorithm>

#include <iostream>

template <typename Iter>
void merge(Iter lBegin, Iter lEnd, Iter rBegin, Iter rEnd) {
	Iter i = lBegin;
	for (Iter j = rBegin; j != rEnd;) {
		if (*i < *j) {
			i = std::next(i, 1);
			j = rBegin;
			continue;
		}
		else {
			for (Iter curr = j; curr != i; curr = std::prev(curr, 1)) {
				Iter prev = std::prev(curr, 1);
				std::iter_swap(prev, curr);
			}
			i = std::next(i, 1);
		}
		rBegin = std::next(rBegin, 1);
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

template <typename Iter, typename BuffIter>
void merge_v1(Iter lBegin, Iter lEnd, 
              Iter rBegin, Iter rEnd, 
              BuffIter buffBegin) {
    Iter l = lBegin;
    Iter r = rBegin;
    BuffIter b = buffBegin;
    while(l != lEnd && r != rEnd){
        if(*l < *r) {
            *b = *l;
            l = std::next(l);
            b = std::next(b);
        }
        else {
            *b = *r;
            r = std::next(r);
            b = std::next(b);
        }
    }
    if(l != lEnd) {
        std::copy(l, lEnd, b);
    }
    if(r != rEnd) {
        std::copy(r, rEnd, b);
    }
}

template <typename Iter>
void mergesort_v1(Iter begin, Iter end) {
    std::size_t size = std::distance(begin, end);
    if(size <= 1) return;

    std::size_t offset = size / 2;

    Iter lBegin = begin;
    Iter lEnd = std::next(begin, offset);
    Iter rBegin = std::next(begin, offset);
    Iter rEnd = end;

    mergesort_v1(lBegin, lEnd);
    mergesort_v1(rBegin, rEnd);

    using ValueType = typename std::iterator_traits<Iter>::value_type;
    std::vector<ValueType> buff(size);

    merge_v1(lBegin, lEnd, rBegin, rEnd, buff.begin());

    std::copy(buff.begin(), buff.end(), begin);
}