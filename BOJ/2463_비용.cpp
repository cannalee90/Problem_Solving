#include <iostream>
#include <cmath>
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

int n, m;

class edges{
public:
	int here;
	int there;
	int weight;
	bool operator<(const edges &a) const{
		return this->weight > a.weight;
	}
};

long long sum;
long long ans; 
long long num_union;

vector<edges> v;
vector<long long> ranking;
vector<long long> parent;


int finding(int vertex){
	if (parent[vertex] == vertex)
		return vertex;
	else{
		int p = finding(parent[vertex]);
		parent[vertex] = p;
		return p;
	}
}

long long merging(int h_p, int w_p){
	ll h_r = ranking[h_p];
	ll w_r = ranking[w_p];
	if (h_r > w_r){
		parent[w_p] = h_p;
		ranking[h_p] += w_r;
	}
	else{
		parent[h_p] = w_p;
		ranking[w_p] += h_r;
	}
	return h_r * w_r;
}

int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	cin >> n;
	cin >> m;

	long long a = pow((double)10, 9);

	ranking.resize(n + 1);
	parent.resize(n + 1);

	for (int i = 1; i <= n; i++){
		ranking[i] = 1;
		parent[i] = i;
	}

	for (int i = 0; i < m; i++){
		edges e;
		scanf("%d %d %d", &e.here, &e.there, &e.weight);
		v.push_back(e);
		sum += e.weight;
	}

	sort(v.begin(), v.end());
	num_union = n;
	
	for (int i = 0; i < m; i++){
		int h = v[i].here;
		int t = v[i].there;
		int w = v[i].weight;

		int h_p = finding(h);
		int t_p = finding(t);

		if (h_p != t_p){
			ans += (merging(h_p, t_p) * sum);
			ans %= a;
		}
		sum -= w;
	}
	cout << ans << endl;
}