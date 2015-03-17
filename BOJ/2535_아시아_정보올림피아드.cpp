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

using namespace std;

typedef long long ll;

class d1
{
public:
	int nation;
	int sn;
	int score;
	d1(int na, int s, int sco)
	{
		this->nation = na;
		this->sn = s;
		this->score = sco;
	}
};

class comp
{
public:
	bool operator()(const d1 &a, const d1 &b)
	{
		return a.score < b.score;
	}
};
int main()
{
#ifdef _CONSOLE
    freopen("input.txt", "r", stdin);
#endif
	int n;
	ll t1,t2,t3;

	cin >> n;

	priority_queue <d1, vector< d1 >, comp > table;
	vector <ll> check(n + 1,0);


	for(int i = 0; i<n; i++)
	{
		cin >> t1 >> t2 >> t3;
		table.push(d1(t1,t2,t3));
	}
	int cnt = 0;
	while(cnt <= 2)
	{
		d1 temp = table.top();
		if(check[temp.nation] < 2)
		{
			check[temp.nation]++;
			cout << temp.nation << " " << temp.sn << endl;
			cnt++;
		}
		table.pop();
	}
}
