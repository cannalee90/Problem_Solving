#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <queue>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <set>
#define INF 900000000


typedef long long ll;
using namespace std;

int n, m;
int t;
bool check[1000010];

int main()
{
#ifdef _CONSOLE
    freopen("input.txt", "r", stdin);
#endif
	char t1;
	int t2;
	cin >> t;
	while(t--)
	{
		cin >> n;
		int input_n = 0;
		int output_n = 0;
		priority_queue<pair<int, int> , vector< pair<int, int> >,  greater<pair<int, int> > > min_pq;
		priority_queue<pair<int, int> , vector< pair<int, int> >,  less<pair<int, int> > > max_pq;
		memset(check, 0, 1000010);
		for(int i = 0; i<n; i++)
		{
			getchar();
			scanf("%c %d", &t1, &t2);
			if(t1 == 'I')
			{
				input_n ++;
				min_pq.push(make_pair(t2,i));
				max_pq.push(make_pair(t2,i));
			}
			else
			{
				if(t2 == 1)
				{
					while(!max_pq.empty())
					{
						pair<int, int> temp = max_pq.top();
						max_pq.pop();
						if(check[temp.second] == 0)
						{
							output_n++;
							check[temp.second] = 1;
							break;
						}
					}
				}
				else
				{
					while(!min_pq.empty())
					{
						pair<int, int> temp = min_pq.top();
						min_pq.pop();
						if(check[temp.second] == 0)
						{
							output_n++;
							check[temp.second] = 1;
							break;
						}
					}
				}
			}

		}
		if(output_n >= input_n)
		{
			cout << "EMPTY" << endl;
		}
		else
		{
			while(!max_pq.empty())
			{
				pair<int, int> temp = max_pq.top();
				max_pq.pop();
				if(check[temp.second] == 0)
				{
					cout << temp.first << " ";
					break;
				}
			}
			while(!min_pq.empty())
			{
				pair<int, int> temp = min_pq.top();
				min_pq.pop();
				if(check[temp.second] == 0)
				{
					cout << temp.first << endl;
					break;
				}
			}

		}
	}
}
