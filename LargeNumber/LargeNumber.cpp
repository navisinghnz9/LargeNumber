#include "pch.h"
#include "LargeNumber.h"


LargeNumber::LargeNumber(string num) : num(num) {}

int LargeNumber::length () {
  return num.length();
}

bool LargeNumber::operator== (LargeNumber const& rhs) {
	return num == rhs.num;
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

LargeNumber LargeNumber::operator+ (LargeNumber const& rhs) {

	string str1 = num; // lhs
	string str2 = rhs.num; // rhs

	// ensuring length of str2 > length of str1
	if (str1.length() > str2.length()) {
		swap(str1, str2);
	}

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

LargeNumber LargeNumber::operator- (LargeNumber const& rhs) {

	string str1 = num; // lhs
	string str2 = rhs.num; // rhs

	// ensuring that value of str1 > str2
	if ( *this < rhs) {
		string str1 = rhs.num; // lhs
		string str2 = num; // rhs
	}

	string str = "";
	int carry = 0;
	int n1 = str1.length(), n2 = str2.length();

	// reversing both of strings 
	str1 = reverse(str1);
	str2 = reverse(str2);
		
	// looping till small string length and subtracting digit of str1 to str2
	for (int i = 0; i < n2; i++) {
		// computing difference of current digits 
		int sub = ((str1[i] - '0') - (str2[i] - '0') - carry);

		// If subtraction is less than zero, then add 10 into sub
		// and take carry as 1 for calculating next step 
		if (sub < 0) {
			sub = sub + 10;
			carry = 1;
		} else {
			carry = 0;
		}

		str.push_back(sub + '0');
	}

	// subtracting remaining digits of larger number 
	for (int i = n2; i < n1; i++) {
		int sub = ((str1[i] - '0') - carry);

		// if the sub value is -ve, then make it positive 
		if (sub < 0) {
			sub = sub + 10;
			carry = 1;
		} else {
			carry = 0;
		}

		str.push_back(sub + '0');
	}

	// reverse resultant string 
	str = reverse(str);

	return LargeNumber(str);
}

bool LargeNumber::operator <(LargeNumber const& rhs) {
	int n1 = num.length(), n2 = rhs.num.length();

	if (n1 != n2) return n1 < n2;

	// both have same length, lets compare each digit
	for (int i = 0; i < n1; i++) {
		if (num[i] < rhs.num[i]) return true;
		if (num[i] > rhs.num[i]) return false;
	}

	return false;
}

LargeNumber LargeNumber::operator* (LargeNumber const& rhs) {

	string num1 = num; // lhs
	string num2 = rhs.num; // rhs

	int len1 = num1.size();
	int len2 = num2.size();

	// if any num is empty, multiplication will result in 0
	if (len1 == 0 || len2 == 0) return LargeNumber("0");

	// will keep the result number in vector in reverse order 
	vector<int> result(len1 + len2, 0);

	// using two indexes to find positions in result.  
	int i_n1 = 0;
	int i_n2 = 0;

	// go from right to left in num1 
	for (int i = len1 - 1; i >= 0; i--) {
		int carry = 0;
		int n1 = num1[i] - '0';

		// to shift position to left after every 
		// multiplication of a digit in num2 
		i_n2 = 0;

		// go from right to left in num2              
		for (int j = len2 - 1; j >= 0; j--) {
			// take current digit of second number 
			int n2 = num2[j] - '0';

			// multiply with current digit of first number and add result to
			// previously stored result at current position.  
			int sum = n1 * n2 + result[i_n1 + i_n2] + carry;

			// carry for next iteration 
			carry = sum / 10;

			// store result 
			result[i_n1 + i_n2] = sum % 10;

			i_n2++;
		}

		// store carry in next cell 
		if (carry > 0)
			result[i_n1 + i_n2] += carry;

		// shift position to left after every multiplication of a digit in num1
		i_n1++;
	}

	// ignore '0's from the right 
	int i = result.size() - 1;
	for (; i >= 0 && result[i] == 0; i--);

	// got all '0's in the result
	if (i == -1) return LargeNumber("0");

	// generate the result string 
	string s = "";

	while (i >= 0) {
		s += std::to_string(result[i--]);
	}

	return LargeNumber(s);
}