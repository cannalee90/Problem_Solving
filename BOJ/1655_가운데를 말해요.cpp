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

vector<int> data;
vector<long long> tree;

int n, m, k;
int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	int n;
	cin >> n;
	multiset<int> tree;
	multiset<int>::iterator itor = tree.begin();
	int t2;
	cin >> t2;
	cout << t2 << endl;
	tree.insert(t2);
	itor = tree.find(t2);
	for (int i = 2; i <= n; i++){
		int t1;
		scanf("%d", &t1);
		tree.insert(t1);
		if (t1 >= *itor){
			if (i % 2 == 1)
				itor++;
		}	
		else if (t1 < *itor){
			if (i % 2 == 0){
				itor--;
			}
		}
		printf("%d\n", *itor);
	}
}
