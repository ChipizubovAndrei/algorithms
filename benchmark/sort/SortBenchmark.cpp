#include <Quicksort.h>
#include <Bubblesort.h>

#include <Utils.h>

#include <benchmark/benchmark.h>

void QuickSortBenchmark(benchmark::State& state) {
	for (auto _ : state) {
		std::vector<int> test = generateRandomVector(state.range(0));
		quicksort(test.begin(), test.end());
	}
}


void BubbleSortBenchmark(benchmark::State& state) {
	for (auto _ : state) {
		std::vector<int> test = generateRandomVector(state.range(0));
		bubblesort(test.begin(), test.end());
	}
}

//BENCHMARK(QuickSortBenchmark)->Arg(10)->Arg(10000)->Arg(1000000);
BENCHMARK(BubbleSortBenchmark)->Arg(10)->Arg(10000)->Arg(1000000);

BENCHMARK_MAIN();
