#pragma once

template <class Iter>
void insertionsort(Iter beginIter, Iter endIter)
{
    Iter curr = beginIter;

    while (curr != endIter) {
        Iter sortedElem = beginIter;
        while (sortedElem != curr) {
            if (curr > sortedElem) {
                sortedElem++;
            }
            else {
                moveRightAndInsert(sortedElem, curr);
            }
        }
    }
}

template <class Iter>
void moveAllRightAndInsert(Iter begin, Iter end)
{

}