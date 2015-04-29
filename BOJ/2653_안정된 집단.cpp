#include <iostream>
#include <utility>
#include <limits.h>
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


int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	int n;
	cin >> n;
	vector<vector<int> > status(n + 1, vector<int>(n + 1, 0));
	vector<vector<int> > ans;
	vector<bool> visited(n + 1, false);
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			cin >> status[i][j];
		}
	}
	int cnt = 0;
	for (int p = 1; p <= n; p++){
		if (visited[p] == true) continue;
		vector<int> temp;
		for (int j = 1; j <= n; j++){
			if (visited[j] == false){
				bool isPossible = true;
				for (int k = 0; k < temp.size(); k++){
					int here = j;
					int there = temp[k];
					if (status[here][there] == 1 || status[there][here] == 1){
						isPossible = false;
						break;
					}
				}
				if (isPossible){
					bool isPossible_2 = true;
					for (int i = 0; i < temp.size(); i++){
						int here = j;
						int there = temp[i];
						if (status[here][there] == 1 || status[there][here] == 1){
							isPossible_2 = false;
						}
					}
					if (isPossible_2){
						temp.push_back(j);
						visited[j] = true;

					}
				}
			}
		}
		if (temp.size() > 1){
			bool isPossible = true;
			for (int k = 0; k < temp.size(); k++){
				for (int i = 0; i < ans.size(); i++){
					for (int j = 0; j < ans[i].size(); j++){
						int there = ans[i][j];
						int here = temp[k];
						if (status[here][there] == 0 || status[there][here] == 0) {
							isPossible = false;
							break;
						}
					}
					if (!isPossible) break;
				}
				if (!isPossible) break;

			}
			if (isPossible){
				ans.push_back(temp);
				cnt += temp.size();
			}
		}
	}
	if (cnt != n){
		cout << "0" << endl;
		return 0;
	}
	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); i++){
		for (int j = 0; j < ans[i].size(); j++){
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}
}