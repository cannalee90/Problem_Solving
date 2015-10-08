#include<functional>
#include<algorithm>
#include<iostream>
#include<climits>
#include<cstring>
#include<iomanip>
#include<cstdio>
#include<vector>
#include<string>
#include<limits>
#include<cmath>
#include<stack>
#include<queue>
#include<list>
#include<set>
#include<map>
using namespace std;

int tc;
bool isPrime[5000051];
int a, b;

vector < int > prime;
int res[5000051];
int main()
{
	//freopen("input.txt", "r", stdin);
	memset(isPrime, true, sizeof(isPrime));
	for (int i = 2; i <= 5000000; i++)
	{
		if (!isPrime[i]) continue;
		prime.push_back(i);
		for (int j = i + i; j <= 5000000; j += i)
			isPrime[j] = false;
	}
	for (int i = 2; i <= 5000000; i++)
	{
		int now = i;
		//cout << i << endl;
		for (int j = 0; j < prime.size(); j++)
		{
			if (prime[j] > sqrt(i)) break;
			//cout << j << endl;
			while (now%prime[j] == 0)
			{
				now /= prime[j];
				res[i]++;
			}
		}
//		cout << i << ' ' << res[i] << endl;
	}

	return 0;
	/*
	scanf("%d", &tc);
	while(tc--)
	{

	}*/
}