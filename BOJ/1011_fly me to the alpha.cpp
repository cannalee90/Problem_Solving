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
	int t;
	cin >> t;
	while (t--){
		int begin, end;
		int move = 0;
		int cnt = 0;
		cin >> begin >> end;
		end -= begin;
		while (1){
			if ((end - move) == 0){
				cout << cnt * 2 << endl;
				break;
			}
			if ((end - (move + (cnt + 1) * 1)) <= 0){
				cout << cnt * 2 + 1 << endl;
				break;
			}

			else if ((end - (move + (cnt + 1) * 2)) <= 0){
				cout << (cnt + 1) * 2  << endl;
				break;
			}
			cnt++;
			move += cnt * 2;
		}
	}
}
