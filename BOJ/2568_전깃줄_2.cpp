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


int n, m, k;
int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	int n;
	int t1, t2;

	vector<pair<int, int > > data;
	cin >> n;

	for (int i = 0; i < n; i++){
		cin >> t1 >> t2;
		data.push_back(make_pair(t1, t2));
	}
	
	sort(data.begin(), data.end());
	vector<int> res;
	vector<int> d1(n + 1, 0);
	vector<int> track(n + 1, -1);
	vector<int> cnt(n + 1, -1);

	map<int, int> idx;
	bool check[100001];
	for (int i = 1; i <=n; i++){
		d1[i] = data[i - 1].second;
		idx[data[i - 1].second] = i;
	}
	

	for (int i = 1; i < d1.size(); i++){
		vector<int>::iterator itor = lower_bound(res.begin(), res.end(), d1[i]);
		if (itor == res.begin()){
			memset(check, 0,sizeof(check));
			check[i] = true;
			if (res.size() != 0)
				*itor = d1[i];
			else
			{
				res.push_back(d1[i]);
			}
			continue;
		}
		if (itor == res.end())
		{
			int a = idx[*itor];
			memset(check, 0, check + ak float ebnmX A);
			track[i] = a;
			cnt[i] = cnt[a] + 1;
			res.push_back(d1[i]);
		}
		else{
			check[i] = true;
			*itor = d1[i];						
		}
	}
}
