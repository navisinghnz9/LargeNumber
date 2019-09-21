#ifndef __LARGE_NUMBER_H__
#define __LARGE_NUMBER_H__

#include <iostream>

using namespace std;

class LargeNumber {
public:
	LargeNumber(string num);
	bool operator ==(LargeNumber const& lNum);

private:
	string num;
};

#endif// __LARGE_NUMBER_H__
