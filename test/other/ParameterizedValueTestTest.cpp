#include <vector>
#include <list>
#include <algorithm>

#include <gtest/gtest.h>

class FooTest : public testing::TestWithParam<std::vector<int>>
{
public:
    bool isSorted(const std::vector<int> & vec) {
        if(vec.size() <= 1) return true;
        auto preLastElem = std::prev(vec.end(), 2);
        for(auto iter = vec.begin(); 
            iter != preLastElem; iter = std::next(iter, 1)) 
        {
            auto nextElem = std::next(iter, 1);
            if(*iter > *nextElem) return false;
        }
        return true;
    }
};

TEST_P(FooTest, SortVector)
{
	std::vector<int> vec = GetParam();
    std::sort(vec.begin(), vec.end());

    EXPECT_TRUE(this->isSorted(vec));
}

std::vector<std::vector<int>> test_data = {
    {},
    {1, 2},
    {2, 1},
    {3, 2, 1},
    {1, 3, 2}
};

INSTANTIATE_TEST_SUITE_P(
	DynamicVectorSortTest,
	FooTest,
	testing::ValuesIn(
        test_data    
    )
);