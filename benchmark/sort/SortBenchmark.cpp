#include <Bubblesort.h>
#include <InsertionSort.h>
#include <Quicksort.h>

#include <Utils.h>

#include <benchmark/benchmark.h>

void BubbleSortBenchmark(benchmark::State& state) {
	for (auto _ : state) {
		std::vector<int> test = generateRandomVector(state.range(0));
		bubblesort(test.begin(), test.end());
	}
}

void InsertionSortBenchmark(benchmark::State& state) {
	for (auto _ : state) {
		std::vector<int> test = generateRandomVector(state.range(0));
		insertionsort(test.begin(), test.end());
	}
}

void QuickSortBenchmark(benchmark::State& state) {
	for (auto _ : state) {
		std::vector<int> test = generateRandomVector(state.range(0));
		quicksort(test.begin(), test.end());
	}
}

void QuickSortModBenchmark(benchmark::State& state) {
	for (auto _ : state) {
		std::vector<int> test = generateRandomVector(state.range(0));
		quicksort_mod(test.begin(), test.end());
	}
}

void STLSortBenchmark(benchmark::State& state) {
	for (auto _ : state) {
		std::vector<int> test = generateRandomVector(state.range(0));
		std::sort(test.begin(), test.end());
	}
}

BENCHMARK(BubbleSortBenchmark)->Arg(10)->Arg(100)->Arg(10000);
BENCHMARK(InsertionSortBenchmark)->Arg(10)->Arg(100)->Arg(10000);
BENCHMARK(QuickSortBenchmark)->Arg(10)->Arg(100)->Arg(10000);
BENCHMARK(QuickSortModBenchmark)->Arg(10)->Arg(100)->Arg(10000);
BENCHMARK(STLSortBenchmark)->Arg(10)->Arg(100)->Arg(10000);

BENCHMARK_MAIN();
