#include <iostream>
#include <limits.h>
#include <utility>
#include <fstream>
#include <string>
#include <string.h>
#include <functional>
#include <queue>
#include <stdio.h>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <stack>

typedef long long ll;

using namespace std;


int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	long long n, m;
	cin >> n >> m;
	vector<long long> color(n + 1, 0);
	vector<long long> colorness(n + 1, 0);
	for (long long i = 1; i <= n; i++)
		color[i] = i;
	for (long long i = 0; i < m; i++){
		long long type, begin, end, c;
		cin >> type;

		if (type == 1){
			cin >> begin >> end >> c;
			for (long long i = begin; i <= end; i++){
				colorness[i] += abs(c - color[i]);
				color[i] = c;
			}
		}
			
		if (type == 2){
			cin >> begin >> end;
			ll total = 0;
			for (long long i = begin; i <= end; i++)
				total += colorness[i];
			cout << total << endl;
		}

	}

}