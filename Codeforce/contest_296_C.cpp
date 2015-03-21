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

vector<long long> tree;
vector<int> data;
int n, k, m;

int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	int x;
	int y;
	int m;
	multiset<int> x_length;
	set<int> x_coor;
	multiset<int> y_length;
	set<int> y_coor;
	char q;
	int d;
	set<int>::iterator itor;
	multiset<int>::iterator itor_y, itor_x;
	cin >> x >> y >> m;
	x_length.insert(x);
	y_length.insert(y);
	int a = 0, l_1 = 0, l_2 = 0;
	x_coor.insert(x);
	x_coor.insert(0);
	y_coor.insert(y);
	y_coor.insert(0);
	while (m--){
		
		getchar();
		scanf("%c %d", &q, &d);
		if (q == 'H'){
			y_coor.insert(d);
			itor = y_coor.lower_bound(d);
			itor++;
			a = *itor;
			l_1 = *itor - (*--itor);
			y_length.insert(l_1);
			l_2 = *itor - (*--itor);
			a -= *itor;
			y_length.insert(l_2);
			itor_y = y_length.lower_bound(a);
			y_length.erase(itor_y);

		}
		else if (q == 'V'){
			x_coor.insert(d);
			itor = x_coor.lower_bound(d);
			itor++;
			a = *itor;
			l_1 = *itor - (*--itor);
			x_length.insert(l_1);
			l_2 = *itor - (*--itor);
			a -= *itor;
			x_length.insert(l_2);
			itor_x = x_length.lower_bound(a);
			x_length.erase(itor_x);

		}
		long long h = *x_length.end().operator--();
		long long w = *y_length.end().operator--();

		printf("%I64d\n", h * w);
	}
}