#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <queue>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <limits.h>

typedef long long ll;
using namespace std;

int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	string str;
	cin >> str;
	map<int, string> number;
	number[0] = "zero";
	number[1] = "one";
	number[2] = "two";
	number[3] = "three";
	number[4] = "four";
	number[5] = "five";
	number[6] = "six";
	number[7] = "seven";
	number[8] = "eight";
	number[9] = "nine";
	number[10] = "ten";
	number[11] = "eleven";
	number[12] = "twelve";
	number[13] = "thirteen";
	number[14] = "fourteen";
	number[15] = "fifteen";
	number[16] = "sixteen";
	number[17] = "seventeen";
	number[18] = "eighteen";
	number[19] = "nineteen";
	number[20] = "twenty";
	number[30] = "thirty";
	number[40] = "forty";
	number[50] = "fifty";
	number[60] = "sixty";
	number[70] = "seventy";
	number[80] = "eighty";
	number[90] = "ninety";

	int a = stoi(str);
	if (a<= 20){
		cout << number[a] << endl;
	}
	else{
		if (a % 10 != 0){
			cout << number[a / 10 * 10] << "-" << number[a % 10] << endl;
		}
		else
			cout << number[a] << endl;
	}
}