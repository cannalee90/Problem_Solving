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

const int M = 10;

int map[M][M];

class d1
{
public:
	long long number;
	int cnt;
	d1(long long number, int cnt)
	{
		this->number = number;
		this->cnt = cnt;
	}

};

int main()
{
#ifdef _CONSOLE
    freopen("input.txt", "r", stdin);
#endif
	long long number;
	cin >> number;
	queue<d1> que;
	que.push(d1(number, 0));
	while(!que.empty())
	{
		d1 Q = que.front();
		if(Q.number == 1) 
		{
			cout << Q.cnt << endl;
			return 0;
		}
		if(Q.number % 3 == 0 && Q.number / 3 > 0) que.push(d1(Q.number / 3 , Q.cnt + 1));
		if(Q.number % 2 == 0 && Q.number / 2 > 0) que.push(d1(Q.number / 2 , Q.cnt + 1));
		if(Q.number - 1 > 0) que.push(d1(Q.number - 1, Q.cnt + 1));
		que.pop();
	}
	
}
