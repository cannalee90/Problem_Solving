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
#include <limits.h>

typedef long long ll;
using namespace std;


int n, m, k;


int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	cin >> n;
	vector<int> tri;
	int temp = 0;
	int tempT = 0;

	vector<int> DP(n + 1, INT_MAX);
	for (int i = 1; 1; i++)
	{
		temp += i;
		tempT += temp;
		if (n < tempT) break;
		tri.push_back(tempT);
	}
	DP[0] = 0;
	for (int i = 0; i < tri.size(); i++){
		int curr = tri[i];
		for (int j = curr; j <= n; j++){
			if (DP[j] > DP[j - curr] + 1){
				DP[j] = DP[j - curr] + 1;
			}
		}
	}
	cout << DP[n] << endl;
}