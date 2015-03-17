#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <queue>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <stack>

#define INF
const long long  hash_value =  1000000000000000007;
                               

typedef long long ll;
using namespace std;


int main()
{
#ifdef _CONSOLE
    freopen("input.txt", "r", stdin);
#endif
	vector<long long> DP(101, 0);
	for(int i = 1; i<=100; i++)
	{
		DP[i] = DP[i-1] + i * i; 
	}
	int n;
	while(cin >> n && n)
	{
		cout << DP[n] << endl;
	}
}