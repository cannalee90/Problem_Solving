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
	int n,m;
	cin >> n >> m;
	vector<int> arr(n + 1,0);
	int cnt = 0;
	while(cnt != m)
	{
		int min;
		for(int i = 2; i<=n; i++)
		{
			if(arr[i] == 0){arr[i] = 1; min = i; cnt++;  break;}
		}
		if(cnt == m) {cout << min << endl; return 0;}
		for(int j = min+ min; j<=n; j+= min)
		{
			if(arr[j] == 0){	arr[j] = 1; cnt++;}
			if(cnt == m)
			{
				cout << j << endl; return 0;
			}
		}
	}
}
