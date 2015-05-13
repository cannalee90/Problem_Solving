#include <iostream>
#include <fstream>
#include <string>
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

int n, t, m;

vector<int>max_dvd;
vector<int>min_dvd;

int get_idx(){
	int idx = 1;
	while (idx < n)
		idx <<= 1;
	return idx;
}

void maketree(){
	int idx = get_idx();
	max_dvd = vector<int>(idx * 2 + 1, INT_MIN);
	min_dvd = vector<int>(idx * 2 + 1, INT_MAX);
	for (int i = 0; i < n; i++){
		max_dvd[idx + i] = i + 1;
		min_dvd[idx + i] = i + 1;
	}
	idx >>= 1;
	while (idx){
		for (int i = idx; i < idx * 2; i++){
			max_dvd[i] = max(max_dvd[i << 1], max_dvd[(i << 1) + 1]);
			min_dvd[i] = min(min_dvd[i << 1], min_dvd[(i << 1) + 1]);
		}
		idx >>= 1;
	}
}

bool isIn(int left, int right){
	int mmin = INT_MAX;
	int mmax = INT_MIN;
	int a = get_idx()  + left;
	int b = get_idx()  + right;
	while (a <= b){
		if (a % 2 == 1)
			mmin = min(min_dvd[a++], mmin);
		if (b % 2 == 0)
			mmin = min(min_dvd[b--], mmin);
		a >>= 1;
		b >>= 1;
	}
	a = get_idx() + left;
	b = get_idx() + right;
	while (a <= b){
		if (a % 2 == 1)
			mmax = max(max_dvd[a++], mmax);
		if (b % 2 == 0)
			mmax = max(max_dvd[b--], mmax);
		a >>= 1;
		b >>= 1;
	}
	if (mmin == left + 1 && right + 1 == mmax) 
		return true;
	else 
		return false;
}

void update(int left, int right){
	int a = get_idx() + left;
	int b = get_idx() + right;
	swap(max_dvd[a], max_dvd[b]);
	swap(min_dvd[a], min_dvd[b]);
	a = (get_idx() + left) >> 1;
	while (a){
		max_dvd[a] = max(max_dvd[a << 1], max_dvd[(a << 1) + 1]);
		a >>= 1;
	}
	a = (get_idx() + left) >> 1;
	while (a){
		min_dvd[a] = min(min_dvd[a << 1], min_dvd[(a << 1) + 1]);
		a >>= 1;
	}
	b = (get_idx() + right) >> 1;
	while (b){
		max_dvd[b] = max(max_dvd[b << 1], max_dvd[(b << 1) + 1]);
		b >>= 1;
	}
	b = (get_idx() + right) >> 1;
	while (b){
		min_dvd[b] = min(min_dvd[b << 1], min_dvd[(b << 1) + 1]);
		b >>= 1;
	}

}

int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w+", stdout);
#endif
	scanf("%d", &t);
	while (t--){
		scanf("%d %d", &n, &m);
		maketree();
		for (int i = 0; i < m; i++){
			int q, a, b;
			scanf("%d %d %d", &q, &a, &b);
			if (q == 0)
				update(a, b);
			if (q == 1){
				if (isIn(a, b))
					printf("YES\n");
				else
					printf("NO\n");
			}
		}
	}
}