#ifndef __LARGE_NUMBER_H__
#define __LARGE_NUMBER_H__

#include <iostream>

using namespace std;

class LargeNumber {
public:
	LargeNumber(string num);
	bool operator ==(LargeNumber const& rhs);
	bool operator <(LargeNumber const& rhs);
	LargeNumber operator +(LargeNumber const& rhs);
	LargeNumber operator -(LargeNumber const& rhs);
	LargeNumber operator *(LargeNumber const& rhs);


	LargeNumber reverse();
	string reverse(string str);
	int length();

private:
	string num;
};

#endif// __LARGE_NUMBER_H__
