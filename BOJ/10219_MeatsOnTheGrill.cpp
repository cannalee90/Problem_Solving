#include <iostream>
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

typedef long long ll;

using namespace std;

vector<vector<char> > data;

int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	int t;
	cin >> t;
	while (t--){
		int n, m;
		cin >> n >> m;
		vector<vector<char> > meats(n + 1);
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++){
				char t1;
				cin >> t1;
				meats[i].push_back(t1);
			}
		}
		for (int i = n - 1; i >= 0; i--){
			for (int j = 0; j <m ; j++){
				cout << meats[i][j];
			}
			cout << endl;
		}
	}
}

