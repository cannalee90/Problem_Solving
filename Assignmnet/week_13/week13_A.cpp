#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
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


inline bool cmp(const pair<ll, ll> & a, const pair<ll, ll> &b){
	if (a.first == b.first)
		return b.second < a.second;
	return a.first < b.first;
}

int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	int t;
	cin >> t;
//	ios::sync_with_stdio(false);
	while (t--){
		int n;
		double slope;
		cin >> n;
		vector<pair<ll, ll > > dots, group_a, group_b;
		dots = vector<pair<ll, ll> >(n);
		for (int i = 0; i < n; i++) cin >> dots[i].first >> dots[i].second;
		sort(dots.begin(), dots.end(), cmp);
		if (dots[n - 1].first - dots[0].first == 0){
			cout << "0" << endl;
			return 0;
		}
		else 
			slope = (double)((double)dots[n - 1].second - (double)dots[0].second) / (double)((double)dots[n - 1].first - (double)dots[0].first);

		group_a.push_back(dots[0]);
		group_b.push_back(dots[0]);

		for (int i = 1; i < n - 1; i++){
			double t_slope = (double)((double)dots[i].second - (double)dots[0].second) / (double)((double)dots[i].first - (double)dots[0].first);
			if (t_slope >= slope)
				group_a.push_back(dots[i]);
			else
				group_b.push_back(dots[i]);
		}

		group_a.push_back(dots[n - 1]);
		group_b.push_back(dots[n - 1]);

		ll area = 0;
		for (int i = 0; i < group_a.size() - 1; i++)
			area += (ll)((group_a[i + 1].second + group_a[i].second) * (group_a[i + 1].first - group_a[i].first));
		for (int i = 0; i < group_b.size() - 1; i++)
			area -= (ll)((group_b[i + 1].second + group_b[i].second) * (group_b[i + 1].first - group_b[i].first));
		cout << area * (ll)5000<< endl;
	}	
}