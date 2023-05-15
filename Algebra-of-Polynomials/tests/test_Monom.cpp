#include "gtest/gtest.h"
#include "../libs/Functional/lib_Monom/Monom.cpp"

TEST(Monom_op, plus_if) {
	int* powers1 = new int[3] {2, 1, 0};
	int* powers2 = new int[3] {1, 1, 0};
	Monom m1(3.0, 3, powers1);
	Monom m2(3.0, 3, powers1);

	assert(m1 == m2);
	EXPECT_EQ(m1, m2);
}
TEST(Monom_op, plus_not_if) {
	int* powers1 = new int[3] {2, 1, 0};
	int* powers2 = new int[3] {1, 1, 0};
	Monom m1(3.0, 3, powers1);
	Monom m2(3.0, 3, powers2);
	assert(m1 != m2);
	EXPECT_NE(m1, m2);
}
 



