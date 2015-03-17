#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <queue>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cstdlib>
 
#include <stack>
   
using namespace std;

bool check[90000000];
vector<string> result;


int main()
{
#ifdef _CONSOLE
    freopen("input.txt", "r", stdin);
#endif
	int n,k;
	int t1;
	string answer;
	string d1,t,t2;
	cin >> n >> k;
	for(int i = 0; i<n; i++)
	{
		cin >> t1;
		d1.insert(d1.begin(),t1 + '0');
	}
	answer = d1;
	reverse(d1.begin(), d1.end());
	sort(answer.begin(), answer.end());
	
	queue<string> que;
	queue<int> count;
	int temp = 0;
	int cnt = 0;
	que.push(d1);
	count.push(0);
	while(!que.empty())
	{
		t = que.front();
		if(t == answer)
		{
			cout << count.front()  << endl;
			return 0;
		}
		for(int i = 0; i<=n - k; i++)
		{
			t2 = t;
			cnt = 0	;
			for(int j = i; j<i + k; j++)
			{
				t2[i + k - 1- cnt++] = t[j];
			}
			temp = stoi(t2);
			if(check[temp]) continue;
			else
			{
				check[temp] = 1;
				que.push(t2);
				count.push(count.front() + 1);
			}
		}
		count.pop();
		que.pop();
	}
	cout << "-1";
}	