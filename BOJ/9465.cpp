#include <stdio.h>
#include <algorithm>
#define INF 900000000


typedef long long ll;
using namespace std;

int n, m, t;
int d1[2][1000010];
int DP[2][1000010];

int main()
{
#ifdef _CONSOLE
    freopen("input.txt", "r", stdin);
#endif
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		for(int i = 0; i<2; i++)
		{
			for(int j = 1; j<=n; j++)
			{
				scanf("%d", &d1[i][j]);
				(d1[0][j] + DP[1][j-1] > DP[0][j-1]) ? DP[0][j] = d1[0][j] + DP[1][j-1]: DP[0][j] = DP[0][j-1];
				(d1[1][j] + DP[0][j-1] > DP[1][j-1]) ? DP[1][j] = d1[1][j] + DP[0][j-1]: DP[1][j] = DP[1][j-1];
			}
		}
		printf("%d\n", (DP[0][n]> DP[1][n]) ? DP[0][n]: DP[1][n]);
	}
}
