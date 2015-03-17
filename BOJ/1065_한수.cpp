#include <iostream>
#include <utility>
#include <fstream>
#include <string>
#include <string.h>
#include <queue>
#include <stdio.h>
#include <algorithm>
#include<limits.h>
#include <set>
#include <map>
#include <vector>
#include <stack>

typedef long long ll;

using namespace std;


int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	int n;
	int ans = 0;
	cin >> n;
	for (int i = 1; i <= n; i++){
		if (i <= 99){
			ans++;
			continue;
		}
		else{
			int a = i / 100;
			int b = (i / 10)  % 10;
			int c = (i % 10);
			if ((b - a) == (c - b))
				ans++;
		}
	}
	cout << ans << endl;	
}