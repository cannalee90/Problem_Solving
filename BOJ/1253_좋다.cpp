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
#include <functional>

typedef long long ll;
using namespace std;


int n;


int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w+", stdout);
#endif
	int n;
	int ans = 0;
	vector<ll> data;
	vector<bool> visited;
	scanf("%d", &n);
	data = vector<ll>(n);
	visited = vector<bool>(n, 0);
	for (int i = 0; i < n; i++)
		scanf("%lld", &data[i]);
	sort(data.begin(), data.end());
	vector<ll>::iterator itor;
	vector<ll>::iterator begin;
	for (int i = 0; i < n; i++){
		for (int j = i + 1; j < n; j++){
			begin = data.begin();
			int cnt = 0;
			while (1){

				itor = lower_bound(begin, data.end(), data[i] + data[j]);
				if (itor == data.end() || *itor != data[i] + data[j])
					break;
				if (itor - data.begin() == i || itor - data.begin() == j){
					begin++;
					continue;
				}
				if (*itor == data[i] + data[j] && visited[itor - data.begin()] == false){
					visited[itor - data.begin()] = true;
					ans++;
				}
				else if (visited[itor - data.begin()] == true){
					while (visited[itor - data.begin()] == true){
						itor++;
						if (itor == data.end()) break;
					}
					if (itor == data.end()) break;
				}
				begin = ++itor;
			}
		}
	}
	printf("%d\n", ans);
}