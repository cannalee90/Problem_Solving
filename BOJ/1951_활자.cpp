#include <iostream>
#include <fstream>
#include <string>
#include<queue>
#include <algorithm>
#include <vector>
#include <cmath>
   
using namespace std;
  
 
 
int main()
{
	long long n;
	long long comp = 9;
	int cnt = 1;
	long long total = 0;
#ifdef _CONSOLE
    freopen("input.txt", "r", stdin);
#endif
    cin >> n;
	while(1)
	{
		if(n > comp)
		{
			n-= comp;
			total += comp * cnt % 1234567;
			cnt ++;
			comp*= 10;
		}
		else if(n <= comp)
		{
			total += n * cnt % 1234567;
			break;
		}
	}
	cout << total << endl;
}