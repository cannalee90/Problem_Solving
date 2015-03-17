#include <iostream>
#include <algorithm>
#include <vector>

#define INF 900000000


typedef long long ll;
using namespace std;

vector<vector<pair<int, int> > > tree;
int mmax;

int traversal(int node)
{
	int longest = 0;
	pair<int, int> total;
	for(int i = 0; i<tree[node].size(); i++)
	{
		int dis = traversal(tree[node][i].first) + tree[node][i].second;
		if(dis > total.first)  swap(total.first, total.second), total.first = dis;
		else if(dis > total.second) total.second = dis;
	}
	mmax = max(total.first + total.second , mmax);
	return total.first;
}

int main()
{
#ifdef _CONSOLE
    freopen("input.txt", "r", stdin);
#endif	
	int n, t1, t2, t3;
	cin >> n;
	tree.resize(n+ 1);
	for(int i = 0; i<n- 1; i++)
	{
		cin >> t1 >> t2 >> t3;
		tree[t1].push_back(make_pair(t2, t3));
	}
	traversal(1);

	cout << mmax << endl;
}
