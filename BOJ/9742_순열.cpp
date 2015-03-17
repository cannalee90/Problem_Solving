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


int main()
{
#ifdef _CONSOLE
    freopen("input.txt", "r", stdin);
#endif
	string a;
	int n;
	while(cin >> a >> n)
	{
		string original = a;
		int flag = 0, cnt = 1;
		while(next_permutation(a.begin(), a.end()))
		{
			cnt++;
			if(cnt == n)
			{ 
				cout << original << " " << n  <<  " " << "= " << a << endl;
				flag = 1;
				break;
			}
		}
		if(flag == 0)
		{
			cout << original << " " << n  <<  " " << "= No permutation" << endl;
		}
	}
}
