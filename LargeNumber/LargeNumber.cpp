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