#pragma once

#include <algorithm>

template <class Iter>
void moveAllRightAndInsert(Iter begin, Iter end)
{
    Iter curr = end;
    while(curr != begin) {
        Iter nextCurr = curr - 1;
        std::iter_swap(nextCurr, curr);
        curr--;
    }
}

template <class Iter>
void insertionsort(Iter beginIter, Iter endIter)
{
    Iter curr = beginIter;

    while (curr != endIter) {
        Iter sortedElem = beginIter;
        while (sortedElem != curr) {
            if (*curr > *sortedElem) {
                sortedElem++;
            }
            else {
                moveAllRightAndInsert(sortedElem, curr);
                break;
            }
        }
        curr++;
    }
}