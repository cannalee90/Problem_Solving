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

int main()
{
#ifdef _CONSOLE
    freopen("input.txt", "r", stdin);
#endif
	string a;
	cin >> n;
	getchar();
	for(int i = 0; i<n; i++)
	{
		getline(cin, a);
		a[0] = toupper(a[0]);
		cout << a << endl;	
	}
}
