#include "pch.h"
#include "LargeNumber.h"


LargeNumber::LargeNumber(string num) : num(num) {}

bool LargeNumber::operator== (LargeNumber const& lNum) {
	return num == lNum.num;
}

LargeNumber LargeNumber::reverse() {
	return LargeNumber(reverse(num));
}

string LargeNumber::reverse(string str) {
	string rev = "";
	for (int i = str.length() - 1; i >= 0; i--) {
		rev += str[i];
	}
	return rev;
}

LargeNumber LargeNumber::operator+ (LargeNumber const& lNum) {

	string str1 = num; // lhs
	string str2 = lNum.num; // rhs

	// ensuring length of str2 > length of str1
	if (str1.length() > str2.length())
		swap(str1, str2);

	string str = "";
	int n1 = str1.length(), n2 = str2.length();
	int diff = n2 - n1;
	int carry = 0;

	// summing digits of both strings
	for (int i = n1 - 1; i >= 0; i--) {
		// compute sum of current digits and carry
		int sum = ((str1[i] - '0') + (str2[i + diff] - '0') + carry);
		str.push_back(sum % 10 + '0');
		carry = sum / 10;
	}

	// adding remaining digits of str2[] 
	for (int i = n2 - n1 - 1; i >= 0; i--) {
		int sum = ((str2[i] - '0') + carry);
		str.push_back(sum % 10 + '0');
		carry = sum / 10;
	}

	// adding remaining carry 
	if (carry) {
		str.push_back(carry + '0');
	}

	return LargeNumber(str).reverse();
}