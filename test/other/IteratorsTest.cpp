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