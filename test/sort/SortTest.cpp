#include <Quicksort.h>
#include <Bubblesort.h>

#include <vector>
#include <array>

#include <gtest/gtest.h>


struct QuickSort {
    template<class Iter>
    void operator()(Iter begin, Iter end) const {
        quicksort(begin, end);
    }
};

struct BubbleSort {
    template<class Iter>
    void operator()(Iter begin, Iter end) const {
        bubblesort(begin, end);
    }
};

template <class SortStratagy>
class SortTest : public testing::Test {
protected:
    SortStratagy sorter;
};

using SortImplementations = testing::Types<
    QuickSort,
    BubbleSort
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

TYPED_TEST(SortTest, One_Element_Vector) {
    std::vector<int> vec{1};
    std::vector<int> expect{ 1 };
    this->sorter(vec.begin(), vec.end());

    EXPECT_EQ(expect, vec);
}

TYPED_TEST(SortTest, Two_Element_Right_Order_Vector) {
    std::vector<int> vec{ 1, 2 };
    std::vector<int> expect{ 1, 2 };
    this->sorter(vec.begin(), vec.end());

    EXPECT_EQ(expect, vec);
}

TYPED_TEST(SortTest, Two_Element_Not_Right_Order_Vector) {
    std::vector<int> vec{ 2, 1 };
    std::vector<int> expect{ 1, 2 };
    this->sorter(vec.begin(), vec.end());

    EXPECT_EQ(expect, vec);
}

TYPED_TEST(SortTest, Four_Element_Not_Right_Order_Vector) {
    std::vector<int> vec{ 4, 3, 2, 1 };
    std::vector<int> expect{ 1, 2, 3, 4 };
    this->sorter(vec.begin(), vec.end());

    EXPECT_EQ(expect, vec);
}

TYPED_TEST(SortTest, Ten_Element_Not_Right_Order_Vector) {
    std::vector<int> vec{ 4, 3, 2, 1, 0, -1, -2, -3, -4, -5 };
    std::vector<int> expect{ -5, -4, -3, -2, -1, 0, 1, 2, 3, 4 };
    this->sorter(vec.begin(), vec.end());

    EXPECT_EQ(expect, vec);
}

TYPED_TEST(SortTest, Half_Same_Even_Elements_Vector) {
    std::vector<int> vec{ 1, 1, 0, 0 };
    std::vector<int> expect{ 0, 0, 1, 1 };
    this->sorter(vec.begin(), vec.end());

    EXPECT_EQ(expect, vec);
}

TYPED_TEST(SortTest, Half_Same_Odd_Elements_Vector) {
    std::vector<int> vec{ 1, 1, 0, 0, 0 };
    std::vector<int> expect{ 0, 0, 0, 1, 1 };
    this->sorter(vec.begin(), vec.end());

    EXPECT_EQ(expect, vec);
}