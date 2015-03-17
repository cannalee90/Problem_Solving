#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <queue>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <stack>
#define INF 900000000


typedef long long ll;
using namespace std;

int n, m, t;
int index;

void change_order(vector<int> &d1, vector<int> &d2, int front, int end, stack<int> &a)
{
	if(d2[front] == d1[index])
	{
		cout << d1[index] << " ";
		index++;
		return;
	}
	for(int i = front; i<end; i++)
	{
		if(index >= n) return;
		if(d2[i] == d1[index])
		{
			a.push(d1[index]);
			index++;
			change_order(d1, d2, front, i, a);
			if(d2[i] == d1[index])
			{
				cout << d1[index] << " ";
				index ++;
				return;
			}
			a.push(d1[index]);
			index++;
			change_order(d1, d2, i+ 1, end, a);
		}
	}
	cout << a.top() << " ";
	a.pop();
}

int main()
{
#ifdef _CONSOLE
    freopen("input.txt", "r", stdin);
#endif
	int t1, t2;
	cin >> t;
	while(t--)
	{
		cin >> n;
		vector<int> d1;
		vector<int> d2;
		stack<int> a;
		for(int i = 0; i<n; i++)
		{
			cin >> t1;
			d1.push_back(t1);
		}
		for(int i = 0; i<n; i++)
		{
			cin >> t1;
			d2.push_back(t1);
		}
		index = 0;
		change_order(d1, d2, 0, n, a);
	}
}
