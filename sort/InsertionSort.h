#pragma once

#include <algorithm>

template <class Iter>
void moveAllRightAndInsert(Iter begin, Iter end)
{
    Iter curr = end;
    while(curr != begin) {
        Iter nextCurr = std::prev(curr, 1);
        std::iter_swap(nextCurr, curr);
        curr = std::prev(curr, 1);
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
                sortedElem = std::next(sortedElem, 1);
            }
            else {
                moveAllRightAndInsert(sortedElem, curr);
                break;
            }
        }
        curr++;
    }
}