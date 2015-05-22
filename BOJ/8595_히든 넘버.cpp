#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <queue>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <limits.h>

typedef long long ll;
using namespace std;

int n, m, t;


int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	int n;
	string str, temp;
	cin >> n >> str;
	unsigned long long  ans = 0;
	for (int i = 0; i < str.size(); i++){
		if (str[i] >= '0' && str[i] <= '9')
			temp += str[i];
		else if(temp != ""){
			ans += stoll(temp);
			temp = "";
		}
	}
	if (temp != "") 	ans += stoll(temp);

	cout << ans << endl;
}