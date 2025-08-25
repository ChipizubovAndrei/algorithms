#include <vector>
#include <random>
#include <chrono>

std::vector<int> generateRandomVector(const std::size_t& size) {
	int lowEdge = 0;
	int highEdge = 1000;

	std::mt19937_64 rng(std::chrono::high_resolution_clock::now().time_since_epoch().count());
	std::uniform_int_distribution<int> dist(lowEdge, highEdge);

	std::vector<int> result;
	result.reserve(size);

	for (int i = 0; i < size; ++i) {
		result.push_back(dist(rng));
	}

	return result;
}