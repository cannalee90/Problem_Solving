#include <iostream>
#include <string>
#include <string.h>
#include <queue>
#include <stack>
#include <stdio.h>
#include <algorithm>
#include <vector>
   
using namespace std;

char a[100];
int total;
int value = 1;


int main()
{
#ifdef _CONSOLE
    freopen("input.txt", "r", stdin);
#endif
	int index =0;
	int inx;
	int top;
	int con;
	stack<int> st;
	cin >> a;
	int length = strlen(a);
	while(index < length)
	{
		if(a[index] == '(')	st.push(-2);
		if(a[index] == '[') st.push(-3);
		if(a[index] == ')')
		{
			con = 0;
			inx = index - 1;
			while(st.top() != -2)
			{
				if(st.top() ==-3) {cout << "0" << endl; return 0;}
				con += st.top();
				st.pop();
			}
			st.pop();
			if(con != 0) st.push(con * 2);
			else st.push(2);
		}
		if(a[index] == ']')
		{
			con = 0;
			inx = index - 1;
			while(st.top() != -3)
			{
				if(st.top() ==-2) {cout << "0" << endl; return 0;}
				con += st.top();
				st.pop();
			}
			st.pop();
			if(con != 0) st.push(con * 3);
			else st.push(3);
		}
		index++;
	}
	while(!st.empty())
	{
		if(st.top() < 0) {cout << "0" << endl; return 0;}
		else total += st.top();
		st.pop();
	}
	cout << total;
}
