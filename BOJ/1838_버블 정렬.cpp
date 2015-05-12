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


int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	int n;
	scanf("%d", &n);
	vector<int> data(n);
	vector<int> sorted(n);
	for (int i = 0; i < n; i++){
		scanf("%d", &data[i]);
		sorted[i] = data[i];
	}
	vector<int>::iterator itor;
	int mmin = 0;
	sort(sorted.begin(), sorted.end());
	for (int i = 0; i < n; i++){
		int target = data[i];
		itor = upper_bound(sorted.begin(), sorted.end(), target) - 1;
		if ((itor - sorted.begin()) - i < mmin)
			mmin = (itor - sorted.begin()) - i;
	}
	cout << (mmin * -1) + 1 << endl;
}