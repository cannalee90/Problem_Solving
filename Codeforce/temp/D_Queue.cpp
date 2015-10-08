#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <functional>
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
int n, t;

int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	ll n;
	ll time = 0;
	cin >> n;
	vector<ll> data(n);
	for (int i = 0; i < n; i++){
		cin >> data[i];
	}
	sort(data.begin(), data.end());
	vector<ll>::iterator itor;
	int cnt = 0;
	for(int i = 0; i<n; i++){
		if (time <= data[i]){
			time += data[i];
			cnt++;
		}
	}
	cout << cnt << endl;	
}