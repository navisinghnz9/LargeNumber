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

TEST(LargeNumberTests, ExpresessionTest) {

	LargeNumber I("123");
	LargeNumber R = I.reverse();

	LargeNumber E("72367033806371673149109894141163778628811792657571658906010558390395870363798401744095280686155" \
				"50773640492165707028496172182896059297790954263709889769722310262262856678765409132782545399159" \
		        "51402057014129613641887324089361978905536997158369515699998004319577692170067433210262575179327" \
		        "64164662319487914962533302741368207211189494615326552790667720411285474162636765168907211924134" \
		        "97337430449601963537666585855994173570392483646775691724799546958348746779152458215374452210759" \
		        "78652777981360800741614852804242740769310839944871117195622497025403628557129111322659662357543" \
		        "55353516703339043001506118520760359577737869472018617942120590873170710805078696371738906375723" \
		        "583032");  // expected result

	LargeNumber X = (I ^ R) + (I ^ 3) - (R ^ 2) + (I * R);

	EXPECT_EQ(true, X == E);
	EXPECT_EQ(671, X.length());
}

int main(int argc, char **argv) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}