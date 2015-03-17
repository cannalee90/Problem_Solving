#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <queue>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <stack>
#define INF 900000000


typedef long long ll;
using namespace std;

int mmax;

class data
{
public:
	int x;
	int y;
	int r;
	int n;
	data(int x, int y, int r, int number)
	{
		this->x = x;
		this->y = y;
		this->r = r;
		this->n = number;
	}
};

bool cmp(const data &a, const data &b)
{
	return a.r > b.r;
}

int traversal(int node, vector<vector<int> > &tree)
{
    int longest = 0;
    pair<int, int> total;
    for(int i = 0; i<tree[node].size(); i++)
    {
        int dis = traversal(tree[node][i], tree) + 1;
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
	int t, n;
	cin >> t;
	while(t--)
	{
		int t1, t2, t3;
		cin >> n;
		vector<data> d1;
		vector<vector<int> > tree(n + 1);
		for(int i = 0; i<n; i++)
		{
			cin >> t1 >> t2 >> t3;
			d1.push_back(data(t1, t2, t3, i));
		}
		sort(d1.begin(), d1.end(), cmp);
		for(int i = n-1; i>=0; i--)
		{
			for(int j = i -1; j>=0; j--)
			{
				int differ_x = abs(d1[i].x - d1[j].x);
				int differ_y = abs(d1[i].y - d1[j].y);
				int D = (differ_x * differ_x) + (differ_y * differ_y);
				int R = d1[j].r * d1[j].r;
				int r = d1[i].r * d1[i].r;
				if(D < R - r)
				{
					tree[j].push_back(i);
					break;

				}
			}
		}
		mmax = 0;
		traversal(0, tree);
		cout << mmax << endl;
	}
}
