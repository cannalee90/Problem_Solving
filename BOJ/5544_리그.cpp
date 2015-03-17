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

const int M = 110;

int score[M];

int main()
{
#ifdef _CONSOLE
    freopen("input.txt", "r", stdin);
#endif
	int n;
	int t1,t2,t3,t4;
	cin >> n;
	while(1)
	{
		cin >> t1 >> t2 >> t3 >> t4;
		if(cin.fail()) break;
		if(t3 > t4) score[t1] += 3;
		if(t4 > t3) score[t2] += 3;
		if(t3 == t4) {score[t1] += 1; score[t2]+= 1;}
	}
	for(int i = 1; i<=n; i++)
	{
		int rank = 1;
		for(int j = 1; j<=n; j++)
		{
			if(score[j] > score[i]) rank ++;
		}
		cout << rank << endl;
	}
}