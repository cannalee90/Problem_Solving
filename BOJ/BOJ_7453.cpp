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
#include <cmath>

typedef long long ll;
using namespace std;

#define pb push_back
#define mp(a, b) make_pair((a), (b));

typedef long long ll;
using namespace std;
int ans;

int main()
{
	freopen("input.txt", "r", stdin);
	int n;

	scanf("%d", &n);
	vector<int> a(n), b(n), c(n), d(n);
	vector<int> vi, vii;
	for(int i = 0; i<n; i++)
		scanf("%d %d %d %d", &a[i], &b[i], &c[i], &d[i]);
	for(int i = 0; i<n; i++){
		for(int j = 0; j<n; j++){
			vi.pb(a[i] + b[j]);
			vii.pb(c[i] + d[j]);
		}
	}
	sort(vi.begin(), vi.end());
	sort(vii.begin(), vii.end());
	for(int i = 0; i<vi.size(); i++){		 
		vector<int>::iterator lower = lower_bound(vii.begin(), vii.end(), -vi[i]);
		vector<int>::iterator upper = upper_bound(vii.begin(), vii.end(), -vi[i]);
		ans += upper - lower;
		
	}
	cout << ans << endl;
}




