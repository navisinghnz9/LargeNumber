#include "pch.h"

void getDigitCount() {

	cout << "Enter a number (0-99999): ";

	LargeNumber I;
	cin >> I;

	LargeNumber R = I.reverse();
	LargeNumber X = (I ^ R) + (I ^ 3) - (R ^ 2) + (I * R);

	cout << "X = (I ^ R) + (I ^ 3) - (R ^ 2) + (I * R)" << endl;
	cout << "X = " << X << endl;
	cout << "Length of X = " << X.length() << endl;
}

int main(int argc, char **argv) {
	testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();
	
	getDigitCount();

	return 0;
}