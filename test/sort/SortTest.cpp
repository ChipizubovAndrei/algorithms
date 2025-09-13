#include <Quicksort.h>
#include <Bubblesort.h>
#include <InsertionSort.h>

#include <vector>
#include <array>
#include <list>
#include <forward_list>

#include <gtest/gtest.h>


struct QuickSort {
    template<typename Iter>
    void operator()(Iter begin, Iter end) const {
        quicksort(begin, end);
    }
};

struct BubbleSort {
    template<typename Iter>
    void operator()(Iter begin, Iter end) const {
        bubblesort(begin, end);
    }
};

struct InsertionSort {
    template <typename Iter>
    void operator()(Iter begin, Iter end) const {
        insertionsort(begin, end);
    }
};

template <typename SortStrategy>
class SortTest : public testing::Test {
protected:
    SortStrategy sorter;
};

using SortImplementations = testing::Types<
    BubbleSort,
    InsertionSort,
    QuickSort
>;

TYPED_TEST_SUITE(SortTest, SortImplementations);

TYPED_TEST(SortTest, Empty_Vector) {
     std::vector<int> vec{};
     this->sorter(vec.begin(), vec.end());

     EXPECT_TRUE(vec.empty());
 }

TYPED_TEST(SortTest, Empty_Array) {
    std::array<int, 0> arr{};
    this->sorter(arr.begin(), arr.end());

    EXPECT_TRUE(arr.empty());
}

TYPED_TEST(SortTest, Empty_List) {
    std::list<int> cont{};
    this->sorter(cont.begin(), cont.end());

    EXPECT_TRUE(cont.empty());
}

TYPED_TEST(SortTest, One_Element_Vector) {
    std::vector<int> vec = { 1 };
    std::vector<int> expect = { 1 };
    this->sorter(vec.begin(), vec.end());

    EXPECT_EQ(expect, vec);
}

TYPED_TEST(SortTest, Two_Element_Right_Order_Vector) {
    std::vector<int> vec = { 1, 2 };
    std::vector<int> expect = { 1, 2 };
    this->sorter(vec.begin(), vec.end());

    EXPECT_EQ(expect, vec);
}

TYPED_TEST(SortTest, Two_Element_Not_Right_Order_Vector) {
    std::vector<int> vec = { 2, 1 };
    std::vector<int> expect = { 1, 2 };
    this->sorter(vec.begin(), vec.end());

    EXPECT_EQ(expect, vec);
}

TYPED_TEST(SortTest, Four_Element_Not_Right_Order_Vector) {
    std::vector<int> vec = { 4, 3, 2, 1 };
    std::vector<int> expect = { 1, 2, 3, 4 };
    this->sorter(vec.begin(), vec.end());

    EXPECT_EQ(expect, vec);
}

TYPED_TEST(SortTest, Ten_Element_Not_Right_Order_Vector) {
    std::vector<int> vec = { 4, 3, 2, 1, 0, -1, -2, -3, -4, -5 };
    std::vector<int> expect = { -5, -4, -3, -2, -1, 0, 1, 2, 3, 4 };
    this->sorter(vec.begin(), vec.end());

    EXPECT_EQ(expect, vec);
}

TYPED_TEST(SortTest, Half_Same_Even_Elements_Vector) {
    std::vector<int> vec = { 1, 1, 0, 0 };
    std::vector<int> expect = { 0, 0, 1, 1 };
    this->sorter(vec.begin(), vec.end());

    EXPECT_EQ(expect, vec);
}

TYPED_TEST(SortTest, Half_Same_Odd_Elements_Vector) {
    std::vector<int> vec = { 1, 1, 0, 0, 0 };
    std::vector<int> expect = { 0, 0, 0, 1, 1 };
    this->sorter(vec.begin(), vec.end());

    EXPECT_EQ(expect, vec);
}