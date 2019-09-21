#include "pch.h"

TEST(LargeNumberTests, LengthTest) {

	EXPECT_EQ(LargeNumber("1234567890987654321").length(), 19);
	EXPECT_EQ(LargeNumber("1234567890987654321001234567890987654321").length(), 40);
}

TEST(LargeNumberTests, EqualToTest) {

	LargeNumber I("1");
	LargeNumber J("1");

	EXPECT_EQ(true, I == J);
}

TEST(LargeNumberTests, LessThanTest) {

	LargeNumber I("981234567892");
	LargeNumber J("987156710000");

	EXPECT_EQ(true, I < J);
}

TEST(LargeNumberTests, ReverseTest) {

	LargeNumber I("12345678");
	LargeNumber E("87654321"); // expected result
	LargeNumber R = I.reverse();

	EXPECT_EQ(true, R == E);
}

TEST(LargeNumberTests, AdditionTest) {

	LargeNumber I("12345678");
	LargeNumber J("87654321");
	LargeNumber E("99999999");  // expected result

	LargeNumber R = I + J;

	EXPECT_EQ(true, R == E);
}

TEST(LargeNumberTests, SubtractionTest) {

	LargeNumber I("87654321");
	LargeNumber J("12345678");
	LargeNumber E("75308643");  // expected result

	LargeNumber R = I - J;

	EXPECT_EQ(true, R == E);
}

TEST(LargeNumberTests, MultiplyTest) {

	LargeNumber I("3456");
	LargeNumber J("789876");
	LargeNumber E("2729811456");  // expected result

	LargeNumber R = I * J;

	EXPECT_EQ(true, R == E);
}

TEST(LargeNumberTests, RaiseToPowerTest) {

	LargeNumber I("123");
	LargeNumber J("3");
	LargeNumber E("1860867");  // expected result

	LargeNumber R = I ^ J;

	EXPECT_EQ(true, R == E);
}

TEST(LargeNumberTests, RaiseToPowerWithIntTest) {

	LargeNumber I("45");
	LargeNumber E("184528125");  // expected result

	LargeNumber R = I ^ 5;

	EXPECT_EQ(true, R == E);
}

int main(int argc, char **argv) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}