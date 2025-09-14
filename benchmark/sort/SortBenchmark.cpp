#include <Bubblesort.h>
#include <InsertionSort.h>
#include <Quicksort.h>
#include <Mergesort.h>

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

void MergeSortBenchmark(benchmark::State& state) {
	for (auto _ : state) {
		std::vector<int> vec = generateRandomVector(state.range(0));
		mergesort(vec.begin(), vec.end());
	}
}

void QuickSortBenchmark(benchmark::State& state) {
	for (auto _ : state) {
		std::vector<int> test = generateRandomVector(state.range(0));
		quicksort(test.begin(), test.end());
	}
}

void STLSortBenchmark(benchmark::State& state) {
	for (auto _ : state) {
		std::vector<int> test = generateRandomVector(state.range(0));
		std::sort(test.begin(), test.end());
	}
}

BENCHMARK(BubbleSortBenchmark)->Arg(100)->Arg(1000)->Arg(10000);
BENCHMARK(InsertionSortBenchmark)->Arg(100)->Arg(1000)->Arg(10000);
BENCHMARK(MergeSortBenchmark)->Arg(100)->Arg(1000)->Arg(10000);
BENCHMARK(QuickSortBenchmark)->Arg(100)->Arg(1000)->Arg(10000);
BENCHMARK(STLSortBenchmark)->Arg(100)->Arg(1000)->Arg(10000);

BENCHMARK_MAIN();
