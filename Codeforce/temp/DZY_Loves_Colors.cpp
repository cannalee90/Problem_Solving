#include <iostream>
using namespace std;


int a[310][310] = {};
int b[310][310] = {};
bool visit[310][310] = {};

void bing(int y, int x)
{
	if (y<0 || x<0)return;
	if (a[y][x] == 0 || visit[y][x] == 1)return;
	visit[y][x] = 1;
	bing(y + 1, x);
	bing(y - 1, x);
	bing(y, x + 1);
	bing(y, x - 1);
}

int main()
{
	freopen("input.txt", "r", stdin);
	int N, M;
	int year = 0;
	cin >> N >> M;

	for (int i = 0; i<N; i++)
	{
		for (int j = 0; j<M; j++)
		{
			cin >> a[i][j];
		}
	}

	for (int k = 1; ; k++)
	{

		for (int i = 0; i<N; i++)
		{
			for (int j = 0; j<M; j++)
			{
				b[i][j] = 0;
				visit[i][j] = 0;
			}
		}

		int sum = 0;
		for (int i = 1; i<N - 1; i++)
		{
			for (int j = 1; j<M - 1; j++)
			{
				int counter = 0;
				if (a[i - 1][j] == 0)
					b[i][j]++;
				if (a[i + 1][j] == 0)
					b[i][j]++;
				if (a[i][j - 1] == 0)
					b[i][j]++;
				if (a[i][j + 1] == 0)
					b[i][j]++;
			}
		}

		for (int i = 1; i<N - 1; i++)
		{
			for (int j = 1; j<M - 1; j++)
			{
				if (a[i][j] < b[i][j])
					a[i][j] = 0;
				else
					a[i][j] -= b[i][j];

				sum = sum + a[i][j];
			}
		}

		if (sum == 0)
		{
			cout << "0";
			break;
		}
		//for (int i = 0; i < N; i++){
		//	for (int j = 0; j < M; j++){
		//		cout << a[i][j];
		//	}
		//	cout << endl;
		//}
		int bingcnt = 0;
		for (int i = 0; i<N; i++)
		{
			for (int j = 0; j<M; j++)
			{
				if (a[i][j] != 0 && visit[i][j] != 1)
				{
					bing(i, j);
					bingcnt = bingcnt + 1;
				}
			}
		}

		if (bingcnt != 1)
		{
			cout << k;
			break;
		}

	}


}