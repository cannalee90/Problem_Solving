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

class segment{
public:		
	int x;
	int w;
};

bool cmp (const segment &a, const segment &b){
	return (a.w + a.x) < (b.w + b.x);
}

int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	int n;
	cin >> n;
	vector<segment> seg;
	for (int i = 0; i < n; i++){
		segment s;
		scanf("%d %d", &s.x, &s.w);
		seg.push_back(s);
	}
	sort(seg.begin(), seg.end(), cmp);
	int last = 0;
	int ans = 1;
	for (int i = 1; i < seg.size(); i++){
		if (seg[i].x - seg[i].w >= seg[last].x + seg[last].w){
			last = i;
			ans++;
		}
	}
	cout << ans << endl;
}