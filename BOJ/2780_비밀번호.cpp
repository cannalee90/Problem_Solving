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

	unsigned long long map[1010][1010];
	int mmove[10][4] = {{7,-1,-1,-1}, {2,4,-1,-1}, {1,5,3,-1}, {2,6,-1,-1}, {1,5,7,-1},{2,4,6,8},{3,5,9,-1},{0,4,8,-1},{7,5,9,-1},{8,6,-1,-1}};


	int main()
	{
	#ifdef _CONSOLE
		freopen("input.txt", "r", stdin);
	#endif
		int n;
		int t1;
		unsigned long long result = 0;
		for(int i = 0; i<10; i++)
		{
			map[1][i] = 1;
		}
		for(int i = 2; i<=1000; i ++)
		{
			for(int j = 0; j<10; j++)
			{
				for(int k = 0; k<4; k++)
				{
					if(mmove[j][k] == -1) break;
					map[i][j] += map[i-1][mmove[j][k]];
					map[i][j] = map[i][j] % 1234567;
				}
			}
		}
		cin >> n;
		while(n--)
		{
			result = 0;
			cin >> t1;
			for(int i = 0; i<10; i++)
			{
				result+=map[t1][i];
			}
			cout << result % 1234567<<  endl;
		}
}	
