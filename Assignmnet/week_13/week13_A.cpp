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

vector<pair<int, int > > dots, group_a, group_b;

int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	int t;
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		dots = vector<pair<int, int > >(n);
		for (int i = 0; i < n; i++) cin >> dots[i].first >> dots[i].second;
		sort(dots.begin(), dots.end());
		double slope = (double)(dots[n - 1].first - dots[0].first) / (double)(dots[n - 1].second - dots[0].second);
		group_a.push_back(dots[0]);
		group_a.push_back(dots[n - 1]);
		group_b.push_back(dots[0]);
		group_b.push_back(dots[n - 1]);
		for (int i = 1; i < n - 1; i++){
			double t_slope = (double)(dots[i].first - dots[0].first) / (double)(dots[i].second - dots[0].second);
			if (t_slope >= slope)
				group_a.push_back(dots[i]);
			else
				group_b.push_back(dots[i]);
		}
		for (int i = dots[0].first; i <= dots[n - 1].first; i++){

		}
	}
}