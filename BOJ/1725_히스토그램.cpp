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

const int M = 100010;
int n, m, t;

int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	int n;
	ll mmax = 0;
	stack<pair<ll, int > > st;
	scanf("%d", &n);
	int height[M];
	for (int i = 0; i < n; i++)
		cin >> height[i];
	for (int i = 0; i < n; i++){
		int h = height[i];
		if (st.empty())
			st.push(make_pair(h, i));
		else if (st.top().first < h)
			st.push(make_pair(h, i));
		else{
			int before = i;
			while (st.top().first > h){
				mmax = max(mmax, st.top().first * (i - st.top().second));
				before = st.top().second;
				st.pop();
				if (st.empty()) break;
			}
			if (st.empty())
				st.push(make_pair(h, before));
			else if (h != st.top().first)
				st.push(make_pair(h, before));
		}
	}
	while (!st.empty()){
		mmax = max(mmax, st.top().first * (n - st.top().second));
		st.pop();
	}
	cout << mmax << endl;
}