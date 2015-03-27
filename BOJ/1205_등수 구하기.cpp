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

typedef long long ll;

using namespace std;

int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	int n;
	int n_s;
	int p;
	vector<ll> score;
	scanf("%d %d %d", &n, &n_s, &p);
	n_s *= -1;
	for (int i = 0; i < n; i++){
		ll t1;
		cin >> t1;
		score.push_back(t1 * -1);
	}
	sort(score.begin(), score.end());
	vector<ll>::iterator itor = lower_bound(score.begin(), score.end(), n_s);
	vector<ll>::iterator it = upper_bound(score.begin(), score.end(), n_s);

	itor = lower_bound(score.begin(), score.end(), n_s);
	int rank = itor - score.begin() + 1;
	if (rank > p || it - score.begin() >= p)
		cout << "-1" << endl;
	else
		cout << rank << endl;
}