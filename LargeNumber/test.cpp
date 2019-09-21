#include "pch.h"


TEST(LargeNumberTests, NumberComparisonTest) {

	LargeNumber I("1");
	LargeNumber J("1");

	EXPECT_EQ(true, I == J);
}

TEST(LargeNumberTests, NumberReverseTest) {

	LargeNumber I("12345678");
	LargeNumber E("87654321"); // expected result
	LargeNumber R = I.reverse(); // actual result

	EXPECT_EQ(true, R == E);
}

int main(int argc, char **argv) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}