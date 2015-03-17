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
	while(t--)
	{
		string a;
		cin >> a;
		int flag = 0;
		int lens = a.length();
		vector<int> char_count(28);
		for(int i = 0; i<lens; i++)
		{
			char t1 = a[i];
			char_count[t1 - 'A']++;
			if(char_count[t1 - 'A'] % 3 == 0) 
			{
				if(i == lens - 1 || a[i] != a[i + 1])
				{
					flag = 1; break;
				}
				i++;
			}
		}
		if(flag == 1) cout << "FAKE" << endl;
		else cout <<"OK" << endl;
	}
}