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

int data[10];

int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w+", stdout);
#endif
	int n;
	scanf("%d", &n);

	for (int i = 1; i <=n; i++)
		scanf("%d", &data[i]);
	int i, j, t;
	int change;
	int cnt = 0;
	for (i = 1; i <= n; i++){
		for (j = 1; j <= n - 1; j++){
			if (data[j] > data[j + 1]){
				swap(data[j], data[j + 1]);
				cnt++;
			}
		}
	}
	cout << cnt << endl;
}