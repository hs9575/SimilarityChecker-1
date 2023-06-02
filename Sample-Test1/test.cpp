#include "pch.h"
#include "../Project11/SimilarityChecker.cpp"

TEST(TestCaseName, TestName) {
	SimilarityChecker* s1 = new SimilarityChecker();
	EXPECT_EQ(60, s1->CheckLength({ "ASD","DSA" }));
	EXPECT_EQ(0, s1->CheckLength({ "A","BB" }));
	EXPECT_EQ(20, s1->CheckLength({ "AAABB","BAA" }));
	EXPECT_EQ(30, s1->CheckLength({ "AA","AAA" }));
}