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

class data{
private:
public:
	int here;
	int there;
	int weight;
	data(int here, int there, int weight){
		this->here = here;
		this->there = there;
		this->weight = weight;
	}
};

vector <data> edges;

int finding(int vertex){
	if (parent[vertex] == vertex)
		return vertex;
	else
		return parent[vertex] = finding(parent[vertex]);
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

inline bool operator<(const data& a, const data& b)
{
	return a.weight < b.weight;
}


int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	int n, m;
	int test;
	cin >> test;
	while (test--){
		cin >> n >> m;
		parent.clear();
		ranking.clear();
		parent.resize(n + 1, 0);
		ranking.resize(n + 1, 1);
		edges.clear();
		for (int i = 1; i <= n; i++){
			parent[i] = i;
		}
		for (int i = 0; i < m; i++){
			int t1, t2, t3;
			scanf("%d %d %d", &t1, &t2, &t3);
			edges.push_back(data(t1, t2, t3));
		}
		sort(edges.begin(), edges.end());
		int ans = 0;
		int idx = 0;
		for (int i = 0; i < m; i++){

			int here = edges[i].here;
			int there = edges[i].there;
			int weight = edges[i].weight;
			int p1 = finding(here);
			int p2 = finding(there);

			if (p1 == p2){
				continue;
			}
			else{
				ans += weight;
				merging(p1, p2);
				idx++;
				if (idx == n - 1) break;
			}
		}
	}
}