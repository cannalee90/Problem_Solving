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


int n, m, k;
int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	int n = 5;
	vector<int> data(n + 1);
	for (int i = 0; i < n; i++){
		cin >> data[i];
	}
	for (int i = 0; i <n; i++){
		for (int j = 0; j <n - 1; j++)	{
			if (data[j] > data[j + 1]){
				swap(data[j], data[j + 1]);
				for (int k = 0; k < n; k++){
					cout << data[k] << " ";
				}
				cout << endl;
			}
		}
	}
}
