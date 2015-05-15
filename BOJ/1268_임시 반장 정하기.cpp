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

int n, m, t;


int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w+", stdout);
#endif
	int data[10][8] = {};
	int arr[1010][8] = {};
	cin >> n;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < 5; j++){
			cin >> arr[i][j];
		}
	}
	int ans = 0, mmax = 0;
	for (int i = 0; i < n; i++){
		set<int> visited;
		for (int j = 0; j < 5; j++){
			for (int k = 0; k < n; k++){
				if (i == k) continue;
				if (arr[i][j] == arr[k][j])
					visited.insert(k);
			}
		}
		if (mmax < visited.size()){
			mmax = visited.size();
			ans = i;
		}
	}
	cout << ans + 1 << endl;
}

