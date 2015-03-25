#include<iostream>
#include <iostream>
#include <utility>
#include <fstream>
#include <string>
#include <string.h>
#include <queue>
#include <stdio.h>
#include <algorithm>
#include <limits.h>
#include <set>
#include <map>
#include <vector>
#include <stack>

typedef long long ll;

using namespace std;


int s[4];
int p[4];

int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	int n = 4;
	string data[4];
	for (int i = 0; i<n; i++){
		cin >> data[i];
	}
	for (int i = 0; i<n; i++){
		int flag = 0;
		for (int j = 0; j<n; j++){
			int a = data[i].size() - 2;
			int b = data[j].size() - 2;
			if (a >= b * 2){
				s[j]++;
				p[i]++;
			}
		}
	}
	int flag = 0;
	int score = 0;
	int idx = 5;
	for (int i = 0; i<n; i++){
		if (s[i] == n - 1 || p[i] == n - 1){
			flag++;
			idx = i;
		}
	}
	if (flag == 1)
		printf("%c\n", idx + 'A');
	else
		printf("C\n");
}