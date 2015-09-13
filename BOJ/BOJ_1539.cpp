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
#include <cmath>
#include <set>
#include <limits.h>

typedef long long ll;
using namespace std;

ll data[1000001] = {};


int main()
{
	ll ans = 0;
	int idx = 1;
	map<char, int > array;
	string a, b;
	cin >> a >> b;
	data[1] = a.size();
	for(int i = 2; i<=b.size(); i++){
		data[i] = data[i-1] * a.size() % 900528;
	}
	while(idx < b.size()){
		ans += data[idx++];
		ans %= 900528;
	}
	for(int i = 0; i<a.size(); i++) array[a[i]] = i;
	for(int i = 0; i<b.size(); i++){
		ans += data[--idx] * array[b[i]] % 900528;
		ans %= 900528;
	}
	cout << ans + array[b[b.size() - 1]] + 1 << endl;
}




