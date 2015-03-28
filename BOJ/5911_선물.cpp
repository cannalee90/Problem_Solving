#include <iostream>
#include <limits.h>
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
#include <functional>

typedef long long ll;

using namespace std;

bool cmp(const pair<long long, long long > &a, const pair<long long, long long> &b)
{
	return a.first + a.second < b.first + b.second;
}

int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	long long n;
	long long m;
	cin >> n >> m;
	vector<pair<long long, long long> > data;
	vector<pair<long long, long long> > temp;
	for (long long i = 0; i < n; i++){
		long long t1, t2;
		cin >> t1 >> t2;
		data.push_back(make_pair(t1, t2));
	}

	temp = data;
	long long mmax = -1;
	long long saving = m;
	for (long long i = 0; i<n; i++){
		long long ans = 0;
		m = saving;
		data = temp;
		data[i].first /= 2;
		sort(data.begin(), data.end(), cmp);

		for (long long j = 0; j < n; j++){
			long long cost = data[j].first + data[j].second;
			if (m - cost >= 0){
				m -= cost;
				ans++;
			}

		}
		mmax = max(ans, mmax);
	}

	cout << mmax << endl;
}