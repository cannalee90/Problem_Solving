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

#define INF 987654321

struct school {
	string univ;
	string team;
	int ac;
	int penalty;
	bool operator<(const school& a) const {
		if (this->ac == a.ac)
			return this->penalty > a.penalty;
		return this->ac < a.ac;
	}
};

int main(){
	int n, m;
	cin >> n >> m;
	vector<school> vi(n);
	for (int i = 0; i < n; i++)
		cin >> vi[i].univ >> vi[i].team >> vi[i].ac >> vi[i].penalty;
	sort(vi.begin(), vi.end());
	reverse(vi.begin(), vi.end());
	set<string> str;
	int idx = 0;
	while(m && idx < n){
		if (!str.count(vi[idx].univ)){
			cout << vi[idx].team << endl;
			str.insert(vi[idx].univ);
			m--;
		}
		idx++;
	}
}
