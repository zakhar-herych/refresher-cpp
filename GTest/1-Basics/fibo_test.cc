#include "fibo.h"

#include "gtest/gtest.h"

TEST(FiboTest, Standart){
	EXPECT_EQ(fibo(3), 2);
}

int main(){
	return RUN_ALL_TESTS();
}
