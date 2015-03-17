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

int main()
{
#ifdef _CONSOLE
    freopen("input.txt", "r", stdin);
#endif
	int n;
	cin >> n;
	if(n % 2 == 1) cout <<"CY" << endl;
	else cout << "SK" << endl;
}