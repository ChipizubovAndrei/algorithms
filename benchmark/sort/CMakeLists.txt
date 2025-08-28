project(SortBenchmark)

set(SORT_BENCHMARK_SOURCES 
    ./SortBenchmark.cpp

    ./Utils.h
)

add_executable(SortBenchmark ${SORT_BENCHMARK_SOURCES})

set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 17)

target_include_directories(${PROJECT_NAME} PRIVATE ./)

target_link_libraries(${PROJECT_NAME} 
    PRIVATE 
        benchmark
        sort
)
