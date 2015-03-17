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

string a;

int main()
{
#ifdef _CONSOLE
    freopen("input.txt", "r", stdin);
#endif
	int n;
	char temp;
	string result;
	cin >> n;
	for(int i = 0; i<n; i++)
	{
		cin >> a;
		stack <char> st;
		st.push(a[0]);
		result = "YES";
		for(int j = 1; j<a.length();j++)
		{
			if(!st.empty())
				temp = st.top();
			else
			{
				st.push(a[j]);
				continue;
			}
			if(a[j] == '(' || a[j] == '[' || a[j] == '{')
			{
				st.push(a[j]);
			}
			else
			{
				if(temp == '(' || temp == '[' || temp == '{')
				{
					if(a[j] == ')' && temp == '(')	st.pop();
					else if(a[j] == ']' && temp == '[')	st.pop();
					else if(a[j] == '}' && temp == '{')	st.pop();
					else
					{
						result = "NO";
						break;
					}
				}
				else
				{
					result = "NO";
					break;

				}
			}
		}
		if(st.empty()) 	cout << result << endl;
		else cout << "NO" << endl;
	}
}