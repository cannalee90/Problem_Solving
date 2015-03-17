#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <queue>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <stack>
   
using namespace std;

int main()
{
#ifdef _CONSOLE
    freopen("input.txt", "r", stdin);
#endif
	pair< int, int > p1;
	priority_queue< pair<int, int>, vector<pair<int, int> >, less<pair<int, int> > > pq;
	int t1;
	for(int i = 1; i<=8; i++)
	{
		cin >> t1;
		pq.push(make_pair(t1, i));
	}
	int total = 0;
	vector<int> result;
	for(int i = 0; i<5; i++)
	{
		total += pq.top().first;
		result.push_back(pq.top().second);
		pq.pop();
	}
	cout << total << endl;
	sort(result.begin(), result.end());
	for(int i =0 ; i<5; i++)
	{
		printf("%d ",result[i]);
	}
	printf("\n");
}
