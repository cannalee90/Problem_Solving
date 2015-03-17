#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <queue>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <stack>

#define INF
const long long  hash_value =  1000000000000000007;
                               

typedef long long ll;
using namespace std;


int main()
{
#ifdef _CONSOLE
    freopen("input.txt", "r", stdin);
#endif
	int t;
	cin >> t;
	getchar();
	while(t--)
	{
		string a;
		getline(cin, a);
		vector<int> char_count(28);
		bool flag = 0;
		int lens = a.length(), mmax = 0, maxp;
		for(int i = 0; i<lens; i++)
		{
			if(a[i] == ' ') continue;
			char_count[a[i]-'a']++;
			if(mmax < char_count[a[i]-'a']) 
			{
				maxp = a[i]-'a';
				mmax = char_count[a[i]-'a'];
			}
		}
			for(int i = 0; i<28; i++)
			{
				if(mmax == char_count[i] && maxp != i)
				{
					flag = 1; break;
				}
			}
			if(flag == 1) 
			{
				printf("?\n");
			}
			else
			{
				printf("%c\n", maxp + 'a');
			}

	}
}