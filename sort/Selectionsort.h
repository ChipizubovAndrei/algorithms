#pragma once

#include <algorithm>

template <typename Iter>
Iter findMin(Iter begin, Iter end)
{
    Iter min = begin;
    for(Iter curr = begin; curr != end; curr = std::next(curr)){
        if(*min > *curr) {
            min = curr;
        }
    }
    return min;
}

template <typename Iter>
void seletionsort(Iter begin, Iter end)
{
    Iter unsortBegin = begin;
    while(unsortBegin != end){
        Iter min = findMin(unsortBegin, end);
        std::iter_swap(unsortBegin, min);
        unsortBegin = std::next(unsortBegin);
    }
}