 #include <Quicksort.h>

#include <vector>
#include <array>

#include <gtest/gtest.h>

TEST(QuickSortTest, Empty_Vector) {
     std::vector<int> vec{};
     quicksort(vec.begin(), vec.end());

     EXPECT_TRUE(vec.empty());
 }

  TEST(QuickSortTest, Empty_Array) {
      std::array<int, 0> arr{};
      quicksort(arr.begin(), arr.end());

      EXPECT_TRUE(arr.empty());
  }

 TEST(QuickSortTest, One_Element_Vector) {
     std::vector<int> vec{1};
     std::vector<int> expect{ 1 };
     quicksort(vec.begin(), vec.end());

     EXPECT_EQ(expect, vec);
 }

 TEST(QuickSortTest, Two_Element_Right_Order_Vector) {
     std::vector<int> vec{ 1, 2 };
     std::vector<int> expect{ 1, 2 };
     quicksort(vec.begin(), vec.end());

     EXPECT_EQ(expect, vec);
 }

 TEST(QuickSortTest, Two_Element_Not_Right_Order_Vector) {
     std::vector<int> vec{ 2, 1 };
     std::vector<int> expect{ 1, 2 };
     quicksort(vec.begin(), vec.end());

     EXPECT_EQ(expect, vec);
 }