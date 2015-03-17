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

int n, m;


//{Re,Pt,Cc,Ea,Tb,Cm,Ex} 

int main()
{
#ifdef _CONSOLE
    freopen("input.txt", "r", stdin);
#endif
	int check[10] = {0};
	string t1;
	string d1[] = {"Re","Pt","Cc","Ea","Tb","Cm","Ex"};
	int cnt = 0;
	while(cin >> t1)
	{
		cnt++;
		for(int i = 0; i<7; i++)
		{
			if(d1[i] == t1)
			{
				check[i]++;
			}
		}
	}
	for(int i = 0; i<7; i++)
	{
		printf("%s %d %0.2f\n", d1[i].c_str(),check[i], (float)check[i] / cnt);
	}
	printf("Total %d 1.00\n", cnt);
}
