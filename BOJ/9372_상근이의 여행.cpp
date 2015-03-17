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
	int t, n, m;
	cin >> t;
	while(t--)
	{
		int t1, t2;
		cin >> n >> m;
		for(int i =0; i<m; i++)
		{
			scanf("%d %d", &t1, &t2);
		}
		cout << n - 1 << endl;
	}
}
