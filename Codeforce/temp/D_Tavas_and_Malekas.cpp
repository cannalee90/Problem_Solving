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

vector<int> get_z(const string &str){
	vector<int> z(str.size());
	int l = 0, r = 0;
	for (int i = 1; i < str.size(); i++){
		if (i <= r){
			z[i] = min(z[i - l], r - i + 1);
		}
		while (z[i] + i < str.size() && str[z[i] + i] == str[z[i]])
			z[i]++;
		if (i + z[i] - 1 > r){
			l = i;
			r = i + z[i] - 1;
		}
	}
	return z;
}

int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	int n, m;
	ll ans = 1;
	string str;
	cin >> n >> m >> str;
	vector<int> vi(m);
	for (int i = 0; i < m; i++)	cin >> vi[i];
	vector<int> z = get_z(str);
	vector<bool> visited(n, 0);
	sort(vi.begin(), vi.end());
	if (m != 0){
		int idx = vi[0] - 1;
		for (int i = idx; i < n && i < idx + str.size(); i++)
			visited[i] = true;
		idx = vi[0] + str.size() - 1;
		for (int i = 1; i < m; i++){
			int interval = vi[i] - vi[i - 1];
			int left = vi[i - 1] - 1;
			int right = vi[i] - 1;
			if (interval >= str.size()){ idx = right; }
			else{

				if (z[interval] != str.size() - interval){
					cout << "0" << endl;
					return 0;
				}
			}
			for (int j = idx; j < n && j < right + str.size(); j++){
				visited[j] = true;
			}
			idx = right + str.size();

		}
	}
	for (int i = 0; i < n; i++){
		if (!visited[i]) 
			ans = (ans * 26LL) % 1000000007;
	}
	cout << ans << endl;
}