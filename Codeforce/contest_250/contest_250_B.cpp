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
	vector<pair<int, int> > data;
	vector<int> res;
	for (int i = 0; i < 3; i++){
		int t1;
		cin >> t1;
		data.push_back(make_pair(t1, i));
		res.push_back(t1);
	}
	for (int i = 0; i <= data[0].first; i++){
		int a = data[0].first;
		int b = data[1].first;
		int c = data[2].first;
		int bond_a = a - i;
		int bond_b = b - bond_a;
		int bond_c = c - bond_b;
		if (bond_a < 0 || bond_b < 0 || bond_c < 0) 
			continue;
		if (bond_a + bond_b == b && bond_b + bond_c == c && bond_c + bond_a == a){
			cout << bond_a << " " << bond_b << " " << bond_c << endl;
			return 0;
		}
	}
	cout << "Impossible" << endl;
}
