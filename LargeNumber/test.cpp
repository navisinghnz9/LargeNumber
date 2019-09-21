#include "pch.h"


TEST(LargeNumberTests, NumberComparisonTest) {

	LargeNumber I("1");
	LargeNumber J("1");

	EXPECT_EQ(true, I == J);
}


int main(int argc, char **argv) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}