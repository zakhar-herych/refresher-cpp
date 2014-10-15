#include "median.h"

#include <vector>
#include <string>
#include "gtest/gtest.h"

TEST(MedianTest, Positive){
	std::vector<int> v1 {8, 4, 2, 6};
	EXPECT_EQ(5, median(v1));
	std::vector<int> v2 {8, 4, 2, 6, 2};
	EXPECT_EQ(4, median(v2));
	std::vector<double> v3 {1, 2, 3, 4};
	EXPECT_EQ(2.5, median(v3));
}

TEST(MedianTest, Negative){
	std::vector<int> v1;
	EXPECT_THROW(median(v1), std::domain_error);
}
