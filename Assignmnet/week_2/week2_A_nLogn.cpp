#include <iostream>
#include <utility>
#include <fstream>
#include <limits.h>
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

class Line{
public:
	int X;
	int Yb;
	int Ye;
	bool type;
	Line(int x1, int y1, int y2, bool type){
		this->X = x1;
		this->Yb = y1;
		this->Ye = y2;
		this->type = type;
	}
	bool operator <(const Line &a) const
	{
		return X < a.X;
	}
};
class Sector{
public:
	int Yb;
	int Ye;
	int dis;
	int count;
	Sector();
	Sector(int Yb, int Ye, int dis, int count){
		this->Yb = Yb;
		this->Ye = Ye;
		this->dis = dis;
		this->count = count;
	}
};

int n, m;
vector<pair<int, int > > tree;
vector<int> data;
vector < pair<int, int>  > range;
vector<Sector> S;
vector<int> Y_pre;
vector<Line> L;

int get_idx(){
	int idx = 1;
	while (idx < range.size())
		idx *= 2;
	return idx;
}
void make_tree(){
	int t_idx = 0;
	while (Y_pre[t_idx] == Y_pre[t_idx + 1])
		t_idx++;
	range.push_back(make_pair(Y_pre[t_idx], Y_pre[t_idx + 1]));
	int lens = 0;
	for (int i = t_idx + 1; i < n * 2; i++){
		if (Y_pre[i] > range[lens].second)
			range.push_back(make_pair(range[lens++].second, Y_pre[i]));
	}
	int idx = get_idx();

	S.resize(idx * 2 + 1, Sector(0, 0, 0, 0));
	for (int i = idx; i < idx + range.size(); i++){
		S[i].Yb = range[i - idx].first;
		S[i].Ye = range[i - idx].second;
	}
	idx /= 2;
	while (idx){
		for (int i = idx; i < idx * 2; i++){
			S[i].Yb = S[i * 2].Yb;
			if (S[i * 2 + 1].Ye)
				S[i].Ye = S[i * 2 + 1].Ye;
			else
				S[i].Ye = S[i * 2].Ye;
		}
		idx /= 2;
	}
}

int get_dis(int node){
	if (S[node].count)
		return S[node].Ye - S[node].Yb;
	else if (node * 2 > get_idx() * 2 + 1)
		return 0;
	else
		return S[node * 2].dis + S[node * 2 + 1].dis;
}
int is_begin(bool type){
	if (type)
		return 1;
	else
		return -1;
}
void counting(int left, int right, bool type, int node){
	if (left == right)
		return;
	if (left == S[node].Yb && S[node].Ye == right){
		S[node].Yb = left;
		S[node].Ye = right;
		S[node].count += is_begin(type);
		S[node].dis = get_dis(node);
		return;
	}
	if (S[node * 2].Yb <= left && left <= S[node * 2].Ye){
		if (S[node * 2].Ye <= right)
			counting(left, S[node * 2].Ye, type, node * 2);
		else
			counting(left, right, type, node * 2);
	}
	if (S[node * 2 + 1].Yb <= right && right <= S[node * 2 + 1].Ye){
		if (S[node * 2 + 1].Yb <= left)
			counting(left, right, type, node * 2 + 1);
		else
			counting(S[node * 2 + 1].Yb, right, type, node * 2 + 1);
	}
	S[node].dis = get_dis(node);
}

int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	int ans = 0;
	cin >> n;
	for (int i = 0; i < n; i++){
		int x1, y1, x2, y2;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		x2 += x1;
		y2 += y1;
		L.push_back(Line(x1, y1, y2, 1));
		L.push_back(Line(x2, y1, y2, 0));

		Y_pre.push_back(y1);
		Y_pre.push_back(y2);
	}
	sort(L.begin(), L.end());
	sort(Y_pre.begin(), Y_pre.end());
	make_tree();
	for (int i = 0; i < L.size() - 1; i++){
		counting(L[i].Yb, L[i].Ye, L[i].type, 1);
		ans += S[1].dis * (L[i + 1].X - L[i].X);
	}
	cout << (int)ans << endl;
}
