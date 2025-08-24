#include <algorithm>
#include <array>

#include <gtest/gtest.h>

TEST(SwapTest, Swap_Two_Int) {
	int a1 = 0, a2 = 1;
	int b1 = 1, b2 = 0;

	std::swap(a1, b1);

	EXPECT_EQ(a1, a2);
	EXPECT_EQ(b1, b2);
}

TEST(SwapTest, Swap_Two_Array_Int_By_Value) {
	std::array<int, 2> real = { 0, 1 };
	std::array<int, 2> expected = { 1, 0 };

	std::swap(real[0], real[1]);

	EXPECT_EQ(real, expected);
}

TEST(SwapTest, Swap_Iter_Array) {
	std::array<int, 2> real = { 0, 1 };

	auto firstElemIter = real.begin();
	auto lastElemIter = real.end()-1;

	std::swap(firstElemIter, lastElemIter);

	EXPECT_EQ(real.begin(), lastElemIter);
	EXPECT_EQ(real.end()-1, firstElemIter);
}

TEST(SwapTest, Swap_Two_Array_Int_By_Iter) {
	std::array<int, 2> real = { 0, 1 };
	std::array<int, 2> expected = { 1, 0 };

	auto firstElemIter = real.begin();
	auto lastElemIter = real.end()-1;

	std::swap(*firstElemIter, *lastElemIter);

	EXPECT_EQ(real, expected);
}

TEST(SwapTest, Swap_Same_Element) {
	std::array<int, 2> real = { 0, 1 };
	std::array<int, 2> expected = { 0, 1 };

	auto elemIter = real.begin();

	std::swap(*elemIter, *elemIter);

	EXPECT_EQ(real, expected);
}

TEST(SwapTest, IterSwap_Elements_By_Iter) {
	std::array<int, 2> real = { 0, 1 };
	std::array<int, 2> expect = { 1, 0 };

	auto firstElemIter = real.begin();
	auto lastElemIter = real.end() - 1;

	std::iter_swap(firstElemIter, lastElemIter);

	EXPECT_EQ(real, expect);
}