#include <iostream>
#include <utility>
#include <functional>
#include <limits.h>
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

#define INF 987654321
int cnt;


int main(){
	
	int n;
	cin >> n;
	vector<int> data(n);
	for (int i = 0; i < n; i++)
		cin >> data[i];
	sort(data.begin(), data.end());
	int mmax = -INF;
	for (int i = 0; i < n; i++) 
		mmax = max(mmax, data[n - i - 1] + i + 1);
	auto itor = lower_bound(data.begin(), data.end(), mmax - n);
	cout << data.end() - itor << endl;
}
