#include "pch.h"
#include "../Project11/SimilarityChecker.cpp"

TEST(TestCaseName, TestName) {
	SimilarityChecker* s1 = new SimilarityChecker();
	EXPECT_EQ(0, s1->CheckAlphabet({ "1","DSA" }));
	EXPECT_EQ(40, s1->CheckAlphabet({ "ASD","DSA" }));
	EXPECT_EQ(0, s1->CheckAlphabet({ "A","BB" }));
	EXPECT_EQ(40, s1->CheckAlphabet({ "AAABB", "BA" }));
	EXPECT_EQ(20, s1->CheckAlphabet({ "AA", "AAE" }));
	EXPECT_EQ(0, s1->CheckAlphabet({ "ABC", "DEF" }));
	EXPECT_EQ(30, s1->CheckAlphabet({ "ABC", "ABCD" }));
	EXPECT_EQ(24, s1->CheckAlphabet({ "ABC", "ABCDE" }));
}