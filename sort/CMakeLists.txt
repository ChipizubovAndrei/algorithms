project(sort)

set(SORT_SOURCES 
    ./Global.h
    
    ./Quicksort.h
    ./Quicksort.cpp

    ./Bubblesort.h
)

add_library(sort SHARED ${SORT_SOURCES})

target_include_directories(sort PUBLIC ./)