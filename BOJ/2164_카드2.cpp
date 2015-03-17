#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <queue>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <stack>
#include<list>

#define INF 900000000

using namespace std;

typedef long long ll;

int check[500001];

int main()
{
#ifdef _CONSOLE
    freopen("input.txt", "r", stdin);
#endif
	int n;
	cin >> n;
	vector<ll> d1;
	for(int i= 1; i<=n; i++)
	{
		d1.push_back(i);
	}
	int index = 0;
	while(d1.size() >= index)
	{
		if(index>= d1.size()) break;
		index ++;
		if(index>= d1.size()) break;
		d1.push_back(d1[index++]);
	}
	cout << d1.back() << endl;
}
