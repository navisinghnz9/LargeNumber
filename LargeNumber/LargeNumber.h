#ifndef __LARGE_NUMBER_H__
#define __LARGE_NUMBER_H__

#include <iostream>

using namespace std;

class LargeNumber {
public:
	LargeNumber();
	LargeNumber(string num);
	bool operator ==(LargeNumber const& rhs);
	bool operator <(LargeNumber const& rhs);
	LargeNumber operator +(LargeNumber const& rhs);
	LargeNumber operator -(LargeNumber const& rhs);
	LargeNumber operator *(LargeNumber const& rhs);
	LargeNumber operator ^(LargeNumber const& rhs);
	LargeNumber operator ^(int n);

	LargeNumber reverse();
	string reverse(string str);
	int length();

	// convenice function to print large number on console
	friend ostream& operator<<(ostream& os, LargeNumber& rhs);

	// convenice function to input large number from console
	friend istream& operator >> (istream& in, LargeNumber& rhs);

private:
	string num;
};

#endif// __LARGE_NUMBER_H__
