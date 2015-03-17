#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <queue>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <stack>
   
using namespace std;

int main()
{
#ifdef _CONSOLE
    freopen("input.txt", "r", stdin);
#endif
	int test;
	string result;
	cin >> test;
	while(test --)
	{
		unsigned long long number;
		unsigned long long t1;
		unsigned long long t2 = 0;
		result = "";
		cin >> number;
		for(int i = 31; i>=0; i--)
		{
			t1 = pow((double)2,i);
			if(number >= t1) 
			{
				number -= t1;
				result.push_back('1');
			}
			else
			{
				result.push_back('0');
			}
		}
		string output;
		string temp;
		temp = result.substr(24,8);
		output.insert(0,temp);
		temp = result.substr(16,8);
		output.insert(8,temp);
		temp = result.substr(8,8);
		output.insert(16,temp);
		temp = result.substr(0,8);
		output.insert(24,temp);
		for(int i = 0; i<=31; i++)
		{
			t1 = pow((double)2,32-i-1);
			if(output[i] == '1')
			{
				t2 += t1;
			}
		}
		cout << t2 << endl;
	}
}