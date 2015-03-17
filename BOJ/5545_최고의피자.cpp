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

bool compare(int x, int y)
{
	return (x>y);
}

int main()
{
#ifdef _CONSOLE
    freopen("input.txt", "r", stdin);
#endif
	int n;
	int cnt = 0;
	int price_d, price_t, k_d, k_t[110];
	int total_t;
	cin >> n;
	cin >> price_d >> price_t;
	cin >> k_d;
	for(int i = 0; i<n; i++)
	{
		cin >> k_t[i];
	}
	sort(k_t, k_t + n,compare);
	int max = k_d / price_d;
	for(int i = 0; i<n; i++)
	{
		int total_k =0;
		for(int j = 0; j<=i;j++)
		{
			total_k += k_t[j];
		}
		if(max < (total_k + k_d) / (price_d + (price_t * (i+1)))) max =  (total_k + k_d) / (price_d + (price_t * (i+1)));
	}
	cout << max << endl;
}