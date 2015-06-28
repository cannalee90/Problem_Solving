#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits.h>
#include <functional>
#include <utility>
#include <fstream>
#include <string>
#include <string.h>
#include <queue>
#include <stdio.h>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <stack>

typedef long long ll;


using namespace std;

int n, m, test;

int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	while (cin >> n){
		bool isJolly = true;
		bool check[4000] = { 0 };
		memset(check, 0, sizeof(0));
		int ini, next;
		cin >> ini;
		for (int i = 0; i < n - 1; i++){
			cin >> next;
			if (abs(next - ini) > n - 1) {
				isJolly = false;
			}
			else{
				check[abs(next - ini)] = true;
				ini = next;
			}
		}
		for (int i = 1; i <= n - 1; i++)
			if (!check[i]) 
				isJolly = false;
		if (isJolly ) 
			cout << "Jolly" << endl;
		else 
			cout << "Not jolly" << endl;
	}
}