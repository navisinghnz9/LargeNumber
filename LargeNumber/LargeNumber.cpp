#include "pch.h"
#include "LargeNumber.h"


LargeNumber::LargeNumber(string num) : num(num) { }

bool LargeNumber::operator== (LargeNumber const& lNum) {
	return num == lNum.num;
}