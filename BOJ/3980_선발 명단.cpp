#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits.h>
#include <functional>
#include <utility>
#include <fstream>
#include <string>
#include <string.h>
#include <queue>
#include <stdio.h>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <stack>

using namespace std;
typedef long long ll;

int ability[12][12];
int dp[12][1 << 12];
int n = 11;

int sol(int pos, int status){
	if (status == (1 << n) - 1)
		return 0;

	int mmax = -987654321;
	for (int i = 0; i < n; i++){
		if (ability[pos][i] != 0 && !(status & (1 << i))){
			mmax = max(mmax, ability[pos][i] + sol(pos + 1, status | (1 << i)));
		}
	}
	return mmax;
}

int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	int t;
	scanf("%d", &t);
	while (t--){
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++)
				scanf("%d", &ability[i][j]);
		}
		int mmax = INT_MIN;
		for (int i = 0; i < n; i++){
			if (ability[0][i] != 0){
				mmax = max(mmax, sol(1, 1 << i) + ability[0][i]);
			}
		}
		cout << mmax << endl;
	}
}