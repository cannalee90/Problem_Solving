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

const long long  hashvalue_1 = 10000000000;

#define INF 900000000


typedef long long ll;
using namespace std;


int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	int t, n;
	cin >> t;
	map<ll, int > hashtable;
	vector<ll> F;
	vector<ll> F2;
	hashtable[0] = 0;
	hashtable[1] = 2;
	hashtable[2] = 3;
	F.push_back(0);
	F.push_back(1);
	F.push_back(1);
	for (int i = 3; i <= 100000; i++)
	{
		F.push_back((F[i - 1] + F[i - 2]) % hashvalue_1);
		hashtable[F[i]] = i;
	}
	while (t--)
	{
		string b;
		long long a = 0;
		long long d = 0;
		cin >> b;
		if (b.size() < 20){ a = stoll(b) % hashvalue_1; }
		else
		{
			int idx = 0;
			for (int i = b.size() - 1; i >= b.size() - 10; i--)
			{
				long long t1 = b[i] - '0';
				if (t1 == 0){ idx++; continue; }
				for (int j = 0; j<idx; j++)
				{
					t1 *= 10;
					t1 %= hashvalue_1;

				}
				a += t1;
				a %= hashvalue_1;
				idx++;
			}
		}
		if (a == 0) { cout << "0" << endl; continue; }
		if (a == 1) { cout << "2" << endl; continue; }
		printf("%d\n", hashtable[a]);
	}
}