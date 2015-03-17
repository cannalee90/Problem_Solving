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



int cnt;

int input(vector<int> &d1)
{
	int n;
	int t1;
	cin >> n;
	for(int i = 0; i<n; i++)
	{
		cin >> t1;
		d1.push_back(t1);
	}
	return n;
}

bool Ispossible(int m, vector<int> &result)
{
	string s = "";
	while(m)
	{
		if(m % 10 == 5 || m % 10 == 8)
		{
			s+= m % 10 + '0';
			m = m / 10;
		}
		else 
			return 0;
	}
	reverse(s.begin(), s.end());
	m = stoi(s);
	for(int i = 0; i<cnt; i++)
	{
		if(result[i] == m) return 0;
	}
	result.push_back(m);
	return 1;
}

int main()
{
#ifdef _CONSOLE
    freopen("input.txt", "r", stdin);
#endif
	int t;
	cin >> t;
	while(t--)
	{
		vector <int> result;
		int n1,n2,n3;
		cnt = 0;
		vector<int> d1;
		n1 = input(d1);
		vector<int> d2;
		n2 = input(d2);
		vector<int> d3;
		n3 = input(d3);
		
		for(int i = 0; i<n1; i++)
		{
			for(int j = 0; j<n2; j++)
			{
				for(int k  = 0; k<n3; k++)
				{
					if(Ispossible(d1[i]+d2[j]+d3[k], result))
						cnt++;
				}
			}
		}
		cout << cnt << endl;
	}
}
