#include <vector>
#include <array>

#include <gtest/gtest.h>

TEST(IteratorsTest, Vector_Same_Iter_Diff) {
	std::vector<int> test = { 0 };

	int diff = test.begin() - test.begin();

	EXPECT_EQ( diff, 0 );
}

TEST(IteratorsTest, Vector_Step_1_Iter_Diff) {
	std::vector<int> test = { 0, 1, 2, 3, 4 };

	int diff = test.end() - test.begin();

	EXPECT_EQ(diff, 5);
}

TEST(IteratorsTest, Array_Same_Iter_Diff) {
	std::array<int, 1> test = { 0 };

	int diff = test.begin() - test.begin();

	EXPECT_EQ(diff, 0);
}

TEST(IteratorsTest, Array_Step_1_Iter_Diff) {
	std::array<int, 5> test = { 0, 1, 2, 3, 4 };

	int diff = test.end() - test.begin();

	EXPECT_EQ(diff, 5);
}

TEST(IteratorsTest, Compare_Iterators_Less) {
	std::array<int, 5> test = { 0, 1, 2, 3, 4 };

	auto lessIter = test.begin();
	auto greaterIter = test.end() - 1;

	EXPECT_TRUE(lessIter < greaterIter);
}

TEST(IteratorsTest, Compare_Iterators_Greater) {
	std::array<int, 5> test = { 0, 1, 2, 3, 4 };

	auto lessIter = test.begin();
	auto greaterIter = test.end() - 1;

	EXPECT_TRUE(greaterIter > lessIter);
}

TEST(IteratorsTest, Compare_Iterators_Equal) {
	std::array<int, 5> test = { 0, 1, 2, 3, 4 };

	auto iter = test.begin();
	auto iter_same = test.begin();

	EXPECT_TRUE(iter == iter_same);
}

TEST(IteratorsTest, Compare_Iterators_Not_Equal) {
	std::array<int, 5> test = { 0, 1, 2, 3, 4 };

	auto iter = test.begin();
	auto iter_plus_1 = test.begin() + 1;

	EXPECT_FALSE(iter == iter_plus_1);
}