project(sort)

set(SORT_SOURCES 
    ./Global.h
    ./Quicksort.h
    ./Quicksort.cpp
    ./Bubblesort.h
    ./InsertionSort.h
    ./Mergesort.h
    ./Selectionsort.h
)

add_library(sort SHARED ${SORT_SOURCES})

if(MSVC)
    target_compile_options(sort 
        PRIVATE
            -W4 -WX -permissive -sdl -analyze -FC       
    )
else()
    target_compile_options(sort 
        PRIVATE
            -Wall -Wextra -Werror -pedantic        
    )
endif()

target_include_directories(sort PUBLIC ./)