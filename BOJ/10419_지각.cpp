#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <queue>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <stack>
#define INF 10000007
#define INF 10000009
#define INF 900000000


typedef long long ll;
using namespace std;


int main()
{
#ifdef _CONSOLE
    freopen("input.txt", "r", stdin);
#endif
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		int s = sqrt(n * 1.0);
		if(s * s + s > n) cout << s - 1 << endl;
		else cout << s << endl;
	}
}
