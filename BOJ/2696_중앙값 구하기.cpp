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
	int t;
	cin >> t;
	while (t--){
		cin >> n;
		vector<int> data(n);
		multiset<int> tree;
		for (int i = 0; i < n; i++){
			cin >> data[i];
		}
		cout << (n + 1) / 2 << endl;
		tree.insert(data[0]);
		multiset<int>::iterator itor = tree.begin();
		cout << data[0] << " ";
		for (int i = 1; i < n; i++){
			tree.insert(data[i]);
			if (i % 2 == 1 && *itor > data[i]){
				itor--;
			}
			if (i % 2 == 0 && *itor < data[i]){
				itor++;
			}
			if ((i + 1) % 20 == 0)
				cout << endl;
			if (i % 2 == 0)
				cout << *itor << " ";
		}
		cout << endl;
	}
}