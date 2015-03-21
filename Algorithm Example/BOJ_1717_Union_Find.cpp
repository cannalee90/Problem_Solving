#include <iostream>
#include <utility>
#include <fstream>
#include <string>
#include <string.h>
#include <queue>
#include <stdio.h>
#include <algorithm>
#include <limits.h>
#include <set>
#include <map>
#include <vector>
#include <stack>

typedef long long ll;

using namespace std;

int n, m;
vector<int> parent;
vector<int> ranking;

int finding(int vertex){
	if (vertex == parent[vertex])
		return vertex;
	else{
		parent[vertex] = finding(parent[vertex]);
		return parent[vertex];
	}
}

void merging(int p1, int p2){
	if (ranking[p1] >= ranking[p2]){
		parent[p2] = p1;
		ranking[p1] += ranking[p2];
	}
	else{
		parent[p1] = p2;
		ranking[p2] += ranking[p1];
	}
}

int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	int n, m;
	cin >> n >> m;
	parent.resize(1000010, 0);
	ranking.resize(1000010, 1);
	for (int i = 1; i <= n; i++){
		parent[i] = i;
	}
	for (int i = 0; i < m; i++){
		int t1, t2, t3;
		scanf("%d %d %d", &t1, &t2, &t3);
		if (t2 > n || t3 > n){
			while (1){
			}
		}
		if (t1 == 0 && t2 != t3){
			int p1 = finding(t3);
			int p2 = finding(t2);
			if (p1 != p2)
				merging(p1, p2);
		}
		if (t1 == 1){
			if (t2 == t3){
				printf("YES\n");
				continue;
			}
			int p1 = finding(t2);
			int p2 = finding(t3);
			if (p1 == p2)
				printf("YES\n");
			else
				printf("NO\n");
		}
	}
}