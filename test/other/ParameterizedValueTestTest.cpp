#include <vector>
#include <list>

#include <gtest/gtest.h>

class FooTest : public testing::TestWithParam<std::string>
{

};

TEST_P(FooTest, Test1)
{
	EXPECT_TRUE(true);
}

INSTANTIATE_TEST_SUITE_P(
	MeenyMinyMoe,
	FooTest,
	testing::Values("dddd", "aaaa"));