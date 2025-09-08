#include <list>
#include <forward_list>

#include <gtest/gtest.h>

class ListIteratorTest : public testing::Test
{
public:
    ListIteratorTest() {
        m_list_empty = {};
        m_list_10_elements = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        m_forward_list_10 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    }
protected:
    std::list<int> m_list_empty;
    std::list<int> m_list_10_elements;
    std::forward_list<int> m_forward_list_10;
};

TEST_F(ListIteratorTest, CompareSameIterators) {
    auto first = m_list_empty.begin();
    auto second = m_list_empty.end();

    EXPECT_TRUE(first == second);

    first = m_list_10_elements.begin();
    second = m_list_10_elements.begin();

    EXPECT_TRUE(first == second);
}

TEST_F(ListIteratorTest, CompareDetermineSizeByIteratorsAndSizeFunc){
    std::size_t sizeBySizeFunc = m_list_empty.size();
    std::size_t sizeByIterators = std::distance(m_list_empty.begin(), m_list_empty.end());

    EXPECT_EQ(sizeBySizeFunc, sizeByIterators);

    sizeBySizeFunc = m_list_10_elements.size();
    sizeByIterators = std::distance(m_list_10_elements.begin(), m_list_10_elements.end());

    EXPECT_EQ(sizeBySizeFunc, sizeByIterators);
}

TEST_F(ListIteratorTest, DetermineSizeListByReversedIteratorsOrder) {
    auto begin = m_list_10_elements.begin();
    auto end = m_list_10_elements.end();

    std::size_t sizeByNormalOrder = std::distance(begin, end);
    std::size_t sizeByReversedOrder = std::distance(end, begin);

    EXPECT_NE(sizeByNormalOrder, sizeByReversedOrder);
    EXPECT_EQ(sizeByNormalOrder, 10);
    EXPECT_EQ(sizeByReversedOrder, 1);
}

TEST_F(ListIteratorTest, DetermineSizeForwardListByReversedIteratorsOrder) {
    auto begin = m_forward_list_10.begin();
    auto end = m_forward_list_10.end();

    std::size_t sizeByNormalOrder = std::distance(begin, end);
    std::size_t sizeByReversedOrder = std::distance(end, begin);

    EXPECT_NE(sizeByNormalOrder, sizeByReversedOrder);
    EXPECT_EQ(sizeByNormalOrder, 10);
    EXPECT_EQ(sizeByReversedOrder, 1);
}

// TODO: Define test for std::distence for iters from different lists