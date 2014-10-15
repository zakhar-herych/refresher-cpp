#include "iterators.h"

#include <vector>
#include <list>
#include <string>
#include "gtest/gtest.h"

TEST(FindTest, Positive){
	std::vector<int> v1 {8, 4, 2, 6};
	EXPECT_EQ(begin(v1), find_iter(begin(v1), end(v1), 8));
	EXPECT_EQ(begin(v1)+1, find_iter(begin(v1), end(v1), 4));
	EXPECT_EQ(begin(v1)+2, find_iter(begin(v1), end(v1), 2));
	EXPECT_EQ(begin(v1)+3, find_iter(begin(v1), end(v1), 6));

	std::list<std::string> l1 {"hi", "hello", "this", "hi"};
	auto it = begin(l1);
	EXPECT_EQ(it++, find_iter(begin(l1), end(l1), "hi"));
	EXPECT_EQ(it++, find_iter(begin(l1), end(l1), "hello"));
	EXPECT_EQ(it++, find_iter(begin(l1), end(l1), "this"));
}

TEST(FindTest, Negative){
	std::vector<int> v1 {8, 4, 2, 6};
	EXPECT_EQ(end(v1), find_iter(begin(v1), end(v1), 9));
}

TEST(CopyTest, Positive){
	std::list<double> l1{3.14159, 2.71828, -1, 4};
	std::list<double> l2;
	copy_iter(begin(l1), end(l1), back_inserter(l2));
	ASSERT_EQ(l1.size(), l2.size());
	auto it = begin(l1);
	auto it2 = begin(l2);
	for (size_t i=0; i!=l1.size(); i++){
		EXPECT_EQ(*it++, *it2++);
	}
}

TEST(ReplaceTest, Positive){
	std::vector<int> v1 {8, 4, 2, 6, 2};
	replace_iter(begin(v1), end(v1), 8, 3);
	EXPECT_EQ(v1[0], 3);
	replace_iter(begin(v1), end(v1), 2, 5);
	EXPECT_EQ(v1[1], 4);
	EXPECT_EQ(v1[2], 5);
	EXPECT_EQ(v1[3], 6);
	EXPECT_EQ(v1[4], 5);
}

TEST(ReverseTest, Positive){
	std::vector<int> v1 {2, 3, 5, 7, 11};
	std::vector<int> v2 {11, 7, 5, 3, 2};
	reverse_iter(begin(v1), end(v1));
	ASSERT_EQ(v1.size(), v2.size());
	for (size_t i=0; i!=v1.size(); i++){
		EXPECT_EQ(v1[i], v2[i]);
	}

	std::list<int> l1 {2, 5, 7, 11};
	std::list<int> l2 {11, 7, 5, 2};
	reverse_iter(begin(l1), end(l1));
	ASSERT_EQ(l1.size(), l2.size());
	auto it = begin(l1);
	auto it2 = begin(l2);
	for (size_t i=0; i!=l1.size(); i++){
		EXPECT_EQ(*it++, *it2++);
	}
}

TEST(BinarySearchTest, Positive){
	std::vector<int> v1 {1, 2, 4, 7, 12, 16};
	for (size_t i=0; i<v1.size(); i++){
		bool b = binary_search(begin(v1), end(v1), v1[i]);
		EXPECT_EQ(b, true);
	}
}

TEST(BinarySearchTest, Negative){
	std::vector<int> v1 {1, 2, 4, 7, 12, 16};
	bool b1 = binary_search(begin(v1), end(v1), 9);
	EXPECT_EQ(b1, false);
}

TEST(ReadTest, Positive){
	std::vector<int> v1 {1, 2, 3, 4, 5};
	std::vector<int> v2;
	std::stringstream cin_test;
	std::copy(begin(v1), end(v1), std::ostream_iterator<int>(cin_test, " "));
	// Save original cin stream
	std::streambuf* orig = std::cin.rdbuf();
	// Redirect cin to custom stringstream
	std::cin.rdbuf(cin_test.rdbuf());
	
	// Test read_iter
	read_iter<std::vector<int>, int>(v2);
	// Redirect cin back to original
	std::cin.rdbuf(orig);
	
	ASSERT_EQ(v1.size(), v2.size());
	for (size_t i=0; i!=v1.size(); i++){
		EXPECT_EQ(v1[i], v2[i]);
	}
}

TEST(WriteTest, Positive){
	std::vector<int> v1 {1, 2, 3, 4, 5};
	std::vector<int> v2;
	std::stringstream cout_test;
	// Save original cout stream
	std::streambuf* orig = std::cout.rdbuf();
	// Redirect cout to custom stringstream
	std::cout.rdbuf(cout_test.rdbuf());

	// Test write iter
	write_iter<std::vector<int>, int>(v1);
	// Redirect cin back to original
	std::cout.rdbuf(orig);

	std::copy(std::istream_iterator<int>(cout_test), std::istream_iterator<int>(), std::back_inserter(v2));
	
	ASSERT_EQ(v1.size(), v2.size());
	for (size_t i=0; i!=v1.size(); i++){
		EXPECT_EQ(v1[i], v2[i]);
	}
}

TEST(SplitTest, Positive){
	std::string s1 = "Hello world and hello people";
	std::initializer_list<std::string> il {"Hello", "world", "and", "hello", "people"};
	std::vector<std::string> v1(il);
	std::vector<std::string> v2;
	split_iter(s1, back_inserter(v2));
	ASSERT_EQ(v1.size(), v2.size());
	for (size_t i=0; i!=v1.size(); i++){
		EXPECT_EQ(v1[i], v2[i]);
	}

	std::list<std::string> l1(il);
	std::list<std::string> l2;
	split_iter(s1, back_inserter(l2));
	ASSERT_EQ(l1.size(), l2.size());
	auto it = begin(l1);
	auto it2 = begin(l2);
	for (size_t i=0; i!=l1.size(); i++){
		EXPECT_EQ(*it++, *it2++);
	}
}
