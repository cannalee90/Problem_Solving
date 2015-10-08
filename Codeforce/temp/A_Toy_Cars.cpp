#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <functional>
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

const int M = 100010;
int n, t;

int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	cin >> n;
	int data[110][110];
	vector<int> ans;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) scanf("%d", &data[i][j]);
	for (int i = 1; i <= n; i++){
		bool isGood = true;
		for (int j = 1; j <= n; j++){
			if (data[i][j] == 1 || data[i][j] == 3)
				isGood = false;
		}
		if (isGood) ans.push_back(i);
	}
	cout << ans.size() << endl;
	if (ans.size() != 0){
		for (int i = 0; i < ans.size(); i++)
			cout << ans[i] << " ";
		cout << endl;
	}
}