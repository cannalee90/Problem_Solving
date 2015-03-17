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


int main()
{
#ifdef _CONSOLE
    freopen("input.txt", "r", stdin);
#endif
	int n, ave, t1;
	int median;
	int result;
	ll sum = 0;
	cin >> n;
	vector<int> data;
	for(int i = 0; i<n; i++)
	{
		scanf("%d", &t1);
		data.push_back(t1);
		sum += data[i];
	}
	if(n == 1){ cout << data[0] << " " << data[0]; return 0;}
	sort(data.begin(), data.end());
	(n % 2 == 0) ? median = (int)((data[(int)n / 2] + data[(int)n/2 - 1])/2 + (double)0.5) : median = data[(int)n/2];
	ave = (int)(((double)sum / (double)n) + (double)0.5);
	printf("%d %d\n", median, ave);
}
